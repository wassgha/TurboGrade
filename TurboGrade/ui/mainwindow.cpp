#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupEditor("MainWindow.cpp");

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath()+ "/../../../../../");
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()+ "/../../../../../"));

    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    ui->treeView->setAttribute(Qt::WA_MacShowFocusRect, 0);

    setWindowTitle(tr("Grading"));
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));
}

void MainWindow::getSelection() {
    if (ui->editor->textCursor().selectionEnd() == ui->editor->textCursor().selectionStart()) {
        popup->hide();
        return;
    }
    popup->move(this->cursor().pos());
    popup->show();
    QString text = "Insert comment from ";
    text += QString::number(ui->editor->textCursor().selectionStart());
    text += " to ";
    text += QString::number(ui->editor->textCursor().selectionEnd());
    popup->ui->add->setText(text);
}

MainWindow::~MainWindow()
{

    delete popup;
    delete ui;
}

void MainWindow::loadFile(QModelIndex item)
{
    if (!model->isDir(item)) {
        QFile file(model->filePath(item));
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->editor->setPlainText(file.readAll());
    }
}

void MainWindow::setupEditor(const QString &file_name)
{
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->editor->setPlainText(file.readAll());
}
