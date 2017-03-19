#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupFileMenu();
    setupHelpMenu();
    setupEditor("MainWindow.cpp");

    ui->centralWidget->layout()->addWidget(editor);
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath()+ "/../../../../../");
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()+ "/../../../../../"));

    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    setWindowTitle(tr("Code Editor"));
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    this->connect(editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));
}

void MainWindow::getSelection() {
    if(popup == nullptr) {
            popup = new QWidget(NULL, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
            pos = new QLabel();
            QHBoxLayout* layout = new QHBoxLayout();
            layout->addWidget(pos);
            popup->setLayout(layout);
    }
    if (editor->textCursor().selectionEnd() == editor->textCursor().selectionStart()) {
        popup->hide();
        return;
    }
    popup->move(this->cursor().pos());
    popup->show();
    QString text = "Insert comment from ";
    text += QString::number(editor->textCursor().selectionStart());
    text += " to ";
    text += QString::number(editor->textCursor().selectionEnd());
    pos->setText(text);
}

MainWindow::~MainWindow()
{

    delete pos;
    delete popup;
    delete highlighter;
    delete editor;
    delete ui;
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                   "to perform simple syntax highlighting by subclassing " \
                   "the QSyntaxHighlighter class and describing " \
                   "highlighting rules using regular expressions.</p>"));
}

void MainWindow::newFile()
{
    editor->clear();
}

void MainWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "Code Files (*.java *.csv *.pde *.txt *.md *.py *.html *.css *.sql *.js *.cpp *.h)");
//        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void MainWindow::loadFile(QModelIndex item)
{
    if (!model->isDir(item)) {
        QFile file(model->filePath(item));
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void MainWindow::openDir(const QString &path)
{
    QString dirName = path;

    if (dirName.isNull())
        dirName = QFileDialog::getExistingDirectory(this,
                                               tr("Open Folder"), "",
                                               QFileDialog::ShowDirsOnly
                                               | QFileDialog::DontResolveSymlinks);

    if (!dirName.isEmpty()) {
        model->setRootPath(dirName);
        ui->treeView->setRootIndex(model->index(dirName));
    }
}

void MainWindow::setupEditor(const QString &file_name)
{
    QFont font;
    font.setFamily("Courier");
    font.setStyleHint(QFont::TypeWriter);
    font.setFixedPitch(true);
    font.setPointSize(12);

    editor = new CodeEditor(this);
    editor->setFont(font);

    highlighter = new SyntaxHighlighter(editor->document());
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text))
        editor->setPlainText(file.readAll());
}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), this, SLOT(openDir()), QKeySequence::Open);
    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()), QKeySequence::Quit);
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(tr("&About"), this, SLOT(about()));
    helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
}
