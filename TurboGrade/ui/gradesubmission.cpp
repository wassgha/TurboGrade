#include "gradesubmission.h"
#include "ui_gradesubmission.h"

GradeSubmission::GradeSubmission(QWidget *parent, Submission *submission, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeSubmission)
{
    ui->setupUi(this);

    _controller = controller;
    _submission = submission;

    setWindowTitle("TurboGrade - Grading submission");
    setAttribute(Qt::WA_StyledBackground, true);
    setWindowFlags(Qt::Window);
    setWindowState(Qt::WindowFullScreen);

    code_view = new CodeView(this, _controller);
    grade_view = new GradeView(this, _controller);

    ui->mainWidget->addWidget(code_view);
    ui->mainWidget->addWidget(grade_view);
    ui->mainWidget->setCurrentWidget(code_view);

    refresh_students();
}


GradeSubmission::~GradeSubmission()
{
    delete code_view;
    delete grade_view;
    delete ui;
}

void GradeSubmission::on_run_clicked()
{
    ui->run->setText("Running");
    ui->run->setDisabled(true);

    QProcess *compile = new QProcess(this);
    compile->start("/usr/local/bin/processing-java",QStringList() << "--sketch=/Users/wassgha/Documents/cs205/project/yikyak"<<"--run");

    connect(compile, SIGNAL(finished(int)), this, SLOT(finished_running()));
}

void GradeSubmission::finished_running() {

    ui->run->setText("Run");
    ui->run->setEnabled(true);

}

void GradeSubmission::on_toggle_clicked()
{
    if(ui->mainWidget->currentWidget() == code_view) {
        QPixmap pixmap(":/misc/res/code.png");
        ui->toggle->setIcon(QIcon(pixmap).pixmap(64));
        ui->toggle->setText("View Code");
        ui->mainWidget->setCurrentWidget(grade_view);
    } else {
        QPixmap pixmap(":/misc/res/grade.png");
        ui->toggle->setIcon(QIcon(pixmap).pixmap(64));
        ui->toggle->setText("View Grade");
        ui->mainWidget->setCurrentWidget(code_view);
    }
}


void GradeSubmission::refresh_students() {
    ui->studentName->clear();
    ui->studentName->addItem("Anonymous Grading", -1);
    for(Student* student : *_submission->_student->_section->_students) {
        ui->studentName->addItem(student->_name, student->_id);
    }
    ui->studentName->setCurrentIndex(ui->studentName->findData(_submission->_student->_id));
}

void GradeSubmission::on_hideName_toggled(bool checked)
{
    if (checked) {
        ui->studentName->setCurrentIndex(0);
        ui->studentName->setEnabled(false);
    } else {
        ui->studentName->setCurrentIndex(ui->studentName->findData(_submission->_student->_id));
        ui->studentName->setEnabled(true);
    }
}
