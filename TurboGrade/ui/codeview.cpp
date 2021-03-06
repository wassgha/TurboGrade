#include "codeview.h"
#include "ui_codeview.h"

CodeView::CodeView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::CodeView)
{
    ui->setupUi(this);

    installEventFilter(this);

    _controller = controller;
    _parent = dynamic_cast<GradeSubmission*>(parent);

    _popup = new CommentPopup(this);

    // Load comments for autocomplete
    refresh_autocomplete();


    /**************************************************
     *          Construct the file tree               *
     **************************************************/

    _root_path = _parent->_submission->getPath();
    _model = new QFileSystemModel;
    _model->setRootPath(_root_path);
    first_file = QDir(_root_path).absoluteFilePath(QDir(_root_path).relativeFilePath(DirTools::first_file(_root_path)));

    root_index = _model->index(_root_path);

    ui->treeView->setModel(_model);
    ui->treeView->setRootIndex(root_index);
    ui->treeView->setCurrentIndex(root_index);

    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    ui->treeView->setAttribute(Qt::WA_MacShowFocusRect, 0);

    ui->comment_layout->setAlignment(Qt::AlignTop);

    ui->general_comments->setPlainText(_parent->_submission->general_comment());

    setupCodeEditor(first_file);
    refresh_criteria();

    // Loads the first file
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    // When users selects text, prompt to add a comment
    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));

    // If the user asks to add a comment then add it
    this->connect(_popup,  SIGNAL(submit()), this, SLOT(add_comment()));

    // Expand all items in the tree
    this->connect(_model, SIGNAL(directoryLoaded(QString)), this, SLOT(finished_loading()));

}


void CodeView::getSelection() {

    // If we're not selecting then hide the "add comment" window
    if (ui->editor->textCursor().selectionEnd() == ui->editor->textCursor().selectionStart()) {
        _popup->hide();
        return;
    }

    // Move the "add comment" window to cursor position
    move_popup();

    // Display it
    _popup->show();
    _popup->ui->comment->setDisabled(false);
    _popup->ui->comment->setReadOnly(false);
    _popup->ui->comment->setEnabled(true);
}

void CodeView::move_popup() {
    // Get the size of the screen
    QRect screen_size = QApplication::desktop()->screenGeometry();

    // Calculate where to move the "add comment" winow
    int popup_x = this->cursor().pos().x() + 5;
    int popup_y = this->cursor().pos().y() + 5;

    // If the window is out of bounds then draw it inside
    if (this->cursor().pos().x() + _popup->width() + 5 > screen_size.width())
        popup_x = this->cursor().pos().x() - _popup->width() - 5;
    if (this->cursor().pos().y() + _popup->height() + 5 > screen_size.height())
        popup_y = this->cursor().pos().y() - _popup->height() - 5;

    // Move the "add comment" window to where the cursor is
    _popup->move(popup_x, popup_y);
}

void CodeView::add_comment() {
    QComboBox *criterion_select = _popup->ui->criterion;
    if (criterion_select->currentIndex() >= 0) {

        // Find table id of the selecter criterion
        int criterion_id;
        if (criterion_select->currentIndex() == 0)
            criterion_id = -1;
        else
            criterion_id = criterion_select->itemData(criterion_select->currentIndex()).toInt();

        // Find the criterion by its id
        Criterion *criterion;
        if (criterion_id == -1)
            criterion = nullptr;
        else
            criterion = _parent->_submission->_assignment->_rubric->get_criterion(criterion_id);


        if (criterion == nullptr) {

            QMessageBox errorBox(QMessageBox::Critical,
                                 "No criterion selected.",
                                 "Please select a category for this comment.",
                                 QMessageBox::Close, this, Qt::Sheet);
            errorBox.exec();
            return;
        }

        // Get comment text
        QString comment_text = _popup->peek("comment");

        if(comment_text == "") {
            QMessageBox errorBox(QMessageBox::Critical,
                                 "No text entered.",
                                 "A comment can not be empty, please enter text in the box.",
                                 QMessageBox::Close, this, Qt::Sheet);
            errorBox.exec();
            return;
        }

        // Get grade adjustment
        int grade_adjustment = _popup->peek("adjust_grade").toInt();

        int adjusted_grade = _parent->_submission->get_grade(criterion) + grade_adjustment;
        if(adjusted_grade > criterion->_out_of || adjusted_grade < 0) {
            QMessageBox errorBox(QMessageBox::Critical,
                                 "The point adjustment is out of grading range.",
                                 "The point adjustment made by this comment is either higher than the"
                                 " maximum score for this criterion or lower than 0, please change it.",
                                 QMessageBox::Close, this, Qt::Sheet);
            errorBox.exec();
            return;
        }



        // Get the file name from the tree view
        QString file_name = QDir(_model->rootPath()).relativeFilePath(_model->filePath(ui->treeView->currentIndex()));

        // Add the comment
        _parent->_submission->add_comment(file_name,
                                          criterion,
                                          _popup->val("comment"),
                                          _popup->val("adjust_grade").toInt(),
                                          ui->editor->textCursor().selectionStart(),
                                          ui->editor->textCursor().selectionEnd());
        _popup->val("criterion");
    }
    _popup->hide();
    refresh_comments();
    refresh_autocomplete();
    _parent->grade_view->update_grades();
}

void CodeView::refresh_criteria() {
    _popup->ui->criterion->clear();
    _popup->ui->criterion->addItem("No criterion selected", -1);
    int i = 1;
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(_popup->ui->criterion->model());
    for(Criterion* criterion : *_parent->_submission->_assignment->_rubric->_criteria) {
        _popup->ui->criterion->addItem(criterion->_name, criterion->_id);
        QStandardItem* item= model->item(i);
        if (criterion->has_children()) {
            item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
            for(Criterion* child : *criterion->_sub_criteria) {
                _popup->ui->criterion->addItem("--- " + child->_name, child->_id);
                i++;
            }
        }
        i++;
    }
}

CodeView::~CodeView()
{

    for (CommentCard *comment_card : _comment_cards) {
        delete comment_card;
    }
    _comment_cards.clear();
    if (_completer != nullptr)
        delete _completer;
    delete _popup;
    delete _model;
    delete ui;

}

void CodeView::loadFile(QModelIndex item)
{
    if (!_model->isDir(item)) {
        qDebug() << "Selected " << _model->filePath(item);
        QFile file(_model->filePath(item));
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->editor->setPlainText(file.readAll());
    }

    refresh_comments();
}

void CodeView::refresh_comments() {
    // Get the file name from the tree view
    QString file_name = QDir(_model->rootPath()).relativeFilePath(_model->filePath(ui->treeView->currentIndex()));
    // Remove old comments
    for (CommentCard *comment_card : _comment_cards) {
        ui->comment_layout->removeWidget(comment_card);
       delete comment_card;
    }
    _comment_cards.clear();
    // Add the comments to the sidebar
    for (Comment* comment : _parent->_submission->get_comment(file_name)) {

        // Add the comment card
        CommentCard *comment_card = new CommentCard(this, comment, _parent);
        _comment_cards.push_back(comment_card);
        ui->comment_layout->addWidget(comment_card);

        // Add events for highlighting the comment in the code when the mouse is over the comment card
        connect(comment_card, SIGNAL(mouseOver(Comment*)), this, SLOT(highlight_comment(Comment *)));
        connect(comment_card, SIGNAL(mouseOut(Comment*)), this, SLOT(unhighlight_comments()));
    }

    refresh_autocomplete();
}

void CodeView::setupCodeEditor(const QString &file_name)
{
    ui->editor->setFontSize(_controller->settings.value("general/font_size").toInt());
    ui->editor->setTheme(_controller->settings.value("general/theme").toString());
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->editor->setPlainText(file.readAll());
}


void CodeView::finished_loading() {
    ui->treeView->setCurrentIndex(_model->index(first_file));
    ui->treeView->expandToDepth(0);
    refresh_comments();
}

bool CodeView::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::Hide) {
        _popup->hide();
    }

    return QWidget::eventFilter(obj, event);
}

void CodeView::highlight_comment(Comment * comment) {

    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    selection.format.setBackground(QColor("#ffea8d"));
    selection.format.setForeground(QColor("#000000"));
    selection.cursor = QTextCursor(ui->editor->document());
    selection.cursor.setPosition( comment->_start_pos );
    selection.cursor.setPosition( comment->_end_pos, QTextCursor::KeepAnchor );
    extraSelections.append(selection);

    QTextCursor cursor (ui->editor->document());
    cursor.setPosition(comment->_start_pos);
    ui->editor->setTextCursor(cursor);

    ui->editor->setExtraSelections(extraSelections);

    for (CommentCard *card : _comment_cards) {
        if (card->_comment == comment) {
            card->highlight();
        } else {
            card->unhighlight();
        }
    }
}

void CodeView::unhighlight_comments() {
    QList<QTextEdit::ExtraSelection> extraSelections;
    ui->editor->setExtraSelections(extraSelections);

    for (CommentCard *card : _comment_cards) {
        card->highlight();
    }
}

void CodeView::refresh_autocomplete() {
    if (_completer != nullptr)
        delete _completer;

    _controller->refresh_autocomplete(_parent->_submission->_assignment);
    _completer = new QCompleter(_controller->_all_comments, this);
    _completer->setCompletionMode(QCompleter::InlineCompletion);
    _completer->setCaseSensitivity(Qt::CaseInsensitive);
    _completer->setCompletionColumn(4);
    _popup->ui->comment->setCompleter(_completer);
    connect(_completer, SIGNAL(highlighted(QModelIndex)), this, SLOT(auto_completed(QModelIndex)));
}

void CodeView::auto_completed(QModelIndex index) {
    QModelIndex index_table_model = qobject_cast<QAbstractProxyModel*> (_completer->completionModel())->mapToSource(index);

    qDebug()<<"Called autocompleted with index"<<index_table_model.row();
    _popup->ui->adjust_grade->setValue(_controller->_all_comments->record(index_table_model.row()).value("grade").toInt());
    int row = _popup->ui->criterion->findData(_controller->_all_comments->record(index_table_model.row()).value("rubric").toInt());
    _popup->ui->criterion->setCurrentIndex(_popup->ui->criterion->model()->index(row, 0).row());
}

QString CodeView::current_file() {
    QString local_path = _model->filePath(ui->treeView->currentIndex());

     return local_path;
}

QString CodeView::current_folder() {
    if (_model->isDir(ui->treeView->currentIndex()))
        return _model->filePath(ui->treeView->currentIndex());

    return _model->filePath(ui->treeView->currentIndex().parent());
}

void CodeView::show_comment(Comment * comment)
{
    QModelIndex new_index = _model->index(QDir(_root_path).absoluteFilePath(comment->_filename));
    ui->treeView->setCurrentIndex(new_index);
    loadFile(new_index);
    refresh_comments();
    highlight_comment(comment);
}

void CodeView::on_general_comments_textChanged()
{
    if (ui->general_comments->toPlainText() == _parent->_submission->general_comment()) {
        ui->save_general_comment->setEnabled(false);
        ui->save_general_comment->setText("SAVED");
    } else {
        ui->save_general_comment->setEnabled(true);
        ui->save_general_comment->setText("SAVE");
    }
}

void CodeView::on_save_general_comment_clicked()
{
    _parent->_submission->update_general_comment(ui->general_comments->toPlainText());
    ui->save_general_comment->setEnabled(false);
    ui->save_general_comment->setText("SAVED");
}
