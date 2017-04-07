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

    _model = new QFileSystemModel;
    _model->setRootPath(_parent->_submission->getPath());

    QModelIndex root_index = _model->index(_parent->_submission->getPath());

    ui->treeView->setModel(_model);
    ui->treeView->setRootIndex(root_index);

    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    ui->treeView->setAttribute(Qt::WA_MacShowFocusRect, 0);

    ui->comment_layout->setAlignment(Qt::AlignTop);


    setupCodeEditor("Main.java");
    refresh_criteria();

    // Loads the first file
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    // When users selects text, prompt to add a comment
    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));

    // If the user asks to add a comment then add it
    this->connect(_popup,  SIGNAL(submit()), this, SLOT(add_comment()));

    // Expand all items in the tree
    this->connect(_model, SIGNAL(directoryLoaded(QString)), this, SLOT(expandToDepth(QString)));

}


void CodeView::getSelection() {
    if (ui->editor->textCursor().selectionEnd() == ui->editor->textCursor().selectionStart()) {
        _popup->hide();
        return;
    }
    _popup->move(this->cursor().pos());
    _popup->show();
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

        // Get the file name from the tree view
        QString file_name = _model->data(ui->treeView->currentIndex()).toString();

        // Add the comment
        _parent->_submission->add_comment(-1,
                                          file_name,
                                          criterion,
                                          _popup->val("comment"),
                                          _popup->val("adjust_grade").toInt(),
                                          ui->editor->textCursor().selectionStart(),
                                          ui->editor->textCursor().selectionEnd());
        _popup->val("criterion");
    }
    refresh_comments();
}

void CodeView::refresh_criteria() {
    _popup->ui->criterion->clear();
    _popup->ui->criterion->addItem("No criterion selected", -1);
    for(Criterion* criterion : *_parent->_submission->_assignment->_rubric->_criteria) {
        _popup->ui->criterion->addItem(criterion->_name, criterion->_id);
        qDebug()<<"Adding criterion"<< criterion->_name<<endl;
        for(Criterion* child : *criterion->_sub_criteria) {
            _popup->ui->criterion->addItem("    | " + child->_name, child->_id);
        }
    }
}

CodeView::~CodeView()
{

    for (CommentCard *comment_card : _comment_cards) {
        delete comment_card;
    }
    _comment_cards.clear();
    delete _popup;
    delete _model;
    delete ui;

}

void CodeView::loadFile(QModelIndex item)
{
    if (!_model->isDir(item)) {
        QFile file(_model->filePath(item));
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->editor->setPlainText(file.readAll());
    }

    refresh_comments();
}

void CodeView::refresh_comments() {
    // Get the file name from the tree view
    QString file_name = _model->data(ui->treeView->currentIndex()).toString();
    // Remove old comments
    for (CommentCard *comment_card : _comment_cards) {
        ui->comment_layout->removeWidget(comment_card);
       delete comment_card;
    }
    _comment_cards.clear();
    // Add the comments to the sidebar
    for (Comment* comment : _parent->_submission->get_comment(file_name)) {

        // Add the comment card
        CommentCard *comment_card = new CommentCard(this, comment);
        _comment_cards.push_back(comment_card);
        ui->comment_layout->addWidget(comment_card);

        // Add events for highlighting the comment in the code when the mouse is over the comment card
        connect(comment_card, SIGNAL(mouseOver(Comment*)), this, SLOT(highlight_comment(Comment *)));
        connect(comment_card, SIGNAL(mouseOut(Comment*)), this, SLOT(unhighlight_comment(Comment *)));
    }
}

void CodeView::setupCodeEditor(const QString &file_name)
{
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->editor->setPlainText(file.readAll());
}

void CodeView::expandToDepth(QString file) {
    ui->treeView->expandToDepth(0);
}

bool CodeView::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::Move) {
        QMoveEvent *moveEvent = static_cast<QMoveEvent*>(event);
        _popup->move(this->cursor().pos());
    } else if (event->type() == QEvent::Close) {
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
}

void CodeView::unhighlight_comment(Comment * comment) {
    QList<QTextEdit::ExtraSelection> extraSelections;
    ui->editor->setExtraSelections(extraSelections);
}
