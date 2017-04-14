#include "gradesubmission.h"
#include "ui_gradesubmission.h"

GradeSubmission::GradeSubmission(QWidget *parent, Submission *submission, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeSubmission)
{
    ui->setupUi(this);

    installEventFilter(this);

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

    ui->hideName->setChecked(true);
}


GradeSubmission::~GradeSubmission()
{
    if(compile !=nullptr)
        delete compile;
    delete code_view;
    delete grade_view;
    delete ui;
}

void GradeSubmission::on_run_clicked()
{
    ui->run->setText("Running");
    ui->run->setDisabled(true);
    code_view->ui->terminal->append("Running project...");

    if(compile != nullptr)
        delete compile;

    compile = new QProcess(this);
    compile->start("/usr/local/bin/processing-java",QStringList() << "--sketch=" +  code_view->current_folder() <<"--run");

    connect(compile, SIGNAL(finished(int)), this, SLOT(finished_running()));
}

void GradeSubmission::finished_running() {

    ui->run->setText("Run");
    ui->run->setEnabled(true);
    code_view->ui->terminal->append(compile->readAllStandardOutput());

}

void GradeSubmission::on_toggle_clicked()
{
    if(ui->mainWidget->currentWidget() == code_view) {
        grade_view->update_grades();
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

bool GradeSubmission::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::Move) {
        code_view->move_popup();
    }
    else if (event->type() == QEvent::ActivationChange)
    {
        if(!this->isActiveWindow())
        {
            code_view->_popup->hide();
        }
    }
    else if (event->type() == QEvent::FocusOut)
    {
        qDebug()<<"Lost focus";
        code_view->_popup->hide();
    }

    return QWidget::eventFilter(watched, event);
}
