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

    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    setWindowTitle(tr("Grading"));
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));
}

void MainWindow::getSelection() {
    if(popup == nullptr) {
            popup = new QWidget(NULL, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
            pos = new QLabel();
            QHBoxLayout* layout = new QHBoxLayout();
            layout->addWidget(pos);
            popup->setLayout(layout);
    }
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
    pos->setText(text);
}

MainWindow::~MainWindow()
{

    delete pos;
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
