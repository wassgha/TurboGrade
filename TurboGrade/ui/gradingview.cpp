#include "gradingview.h"
#include "ui_gradingview.h"

GradingView::GradingView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradingView)
{
    ui->setupUi(this);
    setupEditor("MainWindow.cpp");

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath()+ "/../../../../../yikyak");
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()+ "/../../../../../yikyak"));

    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
    ui->treeView->setAttribute(Qt::WA_MacShowFocusRect, 0);

    ui->run->setIcon(ui->run->style()->standardIcon(QStyle::SP_MediaPlay));
    ui->overview->setIcon(ui->overview->style()->standardIcon(QStyle::SP_DialogApplyButton));


    setWindowTitle(tr("TurboGrade - Grading submission"));
    this->connect(ui->treeView, SIGNAL(clicked( QModelIndex )), this, SLOT(loadFile(QModelIndex)));

    this->connect(ui->editor,  SIGNAL(selectionChanged()), this, SLOT(getSelection()));
}


void GradingView::getSelection() {
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

GradingView::~GradingView()
{

    delete popup;
    delete ui;
}

void GradingView::loadFile(QModelIndex item)
{
    if (!model->isDir(item)) {
        QFile file(model->filePath(item));
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->editor->setPlainText(file.readAll());
    }
}

void GradingView::setupEditor(const QString &file_name)
{
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->editor->setPlainText(file.readAll());
}

void GradingView::on_run_clicked()
{
    ui->run->setText("Running");
    QProcess *processing_app = new QProcess(this);
    processing_app->start("/usr/local/bin/processing-java",QStringList() << "--sketch=/Users/wassgha/Documents/cs205/project/yikyak"<<"--run");
//    processing_app->waitForFinished();
    QString output(processing_app->readAllStandardOutput());
    std::cout<<output.toStdString()<<std::endl;
    std::cerr<<output.toStdString()<<std::endl;


}

void GradingView::on_overview_clicked()
{
    emit toggle();
}
