#include "codeview.h"
#include "ui_codeview.h"

CodeView::CodeView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::CodeView)
{
    ui->setupUi(this);

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

    std::cout<<filepath.toStdString()<<std::endl;

    setupCodeEditor("Main.java");

    // Loads the first file
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    // When users selects text, prompt to add a comment
    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));

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
    QString text = "Insert comment from ";
    text += QString::number(ui->editor->textCursor().selectionStart());
    text += " to ";
    text += QString::number(ui->editor->textCursor().selectionEnd());
    _popup->ui->add_btn->setText(text);
}

CodeView::~CodeView()
{

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
