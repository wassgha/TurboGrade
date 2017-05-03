#include "gradesubmission.h"
#include "ui_gradesubmission.h"

GradeSubmission::GradeSubmission(QWidget *parent, Submission *submission, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeSubmission),
    _parent(dynamic_cast<Dashboard*>(parent))
{

    ui->setupUi(this);

    _controller = controller;
    _submission = submission;

    setWindowTitle("TurboGrade - Grading submission");
    setAttribute(Qt::WA_StyledBackground, true);

    code_view = new CodeView(this, _controller);
    grade_view = new GradeView(this, _controller);

    ui->mainWidget->addWidget(code_view);
    ui->mainWidget->setCurrentWidget(code_view);
    code_view->ui->grade_view->addWidget(grade_view);

    // Show grading progress (graded/total submissions)
    update_progress();

    update_next();

    ui->logo->setCursor(Qt::PointingHandCursor);
    connect(ui->logo, SIGNAL(clicked()), this, SLOT(show_dashboard()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(show_dashboard()));

    ui->next->setCursor(Qt::PointingHandCursor);
    connect(ui->next, SIGNAL(clicked(bool)), this, SLOT(next_submission()));

    refresh_students();

    ui->hideName->setChecked(true);

    installEventFilter(this);
}

void GradeSubmission::update_next() {
    if (_submission->_status == 2 && _submission->_student->_section->num_submissions_ungraded(_submission->_assignment) > (_submission->_status == 2 ? 0 : 1)) {
        ui->next->setEnabled(true);
    } else {
        ui->next->setEnabled(false);
    }
}

GradeSubmission::~GradeSubmission()
{
    if(compile !=nullptr)
        delete compile;
    delete code_view;
    if(fireworks != nullptr)
        delete fireworks;
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
    QByteArray errors = compile->readAllStandardError();
    if (errors != QByteArray("")) {
        code_view->ui->terminal->append("<code style=\"color:white; background:#e74c3c; padding-top:10px; padding-right:10px;padding-left:10px;padding-bottom:10px;\">"
                                            + errors + "</code>");
        activateWindow();
        raise();
    }
    code_view->ui->terminal->append(compile->readAllStandardOutput());

}


void GradeSubmission::refresh_students() {
    ui->studentName->clear();
    ui->studentName->addItem("Anonymous Grading", -1);
    for(Student* student : *_submission->_student->_section->_students) {
        if (student->get_submission(_submission->_assignment) != nullptr)
            ui->studentName->addItem(student->_name);
    }
    ui->studentName->setCurrentIndex(ui->studentName->findText(_submission->_student->_name));
}

void GradeSubmission::on_hideName_toggled(bool checked)
{
    if (checked) {
        ui->studentName->setCurrentIndex(0);
        ui->studentName->setEnabled(false);
    } else {
        ui->studentName->setCurrentIndex(ui->studentName->findText(_submission->_student->_name));
        ui->studentName->setEnabled(true);
    }
}

bool GradeSubmission::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::Move) {
        code_view->move_popup();
        if(fireworks != nullptr)
            fireworks->update();
    }
    else if (event->type() == QEvent::FocusOut)
    {
        qDebug()<<"Lost focus";
        code_view->_popup->hide();
    } else if (event->type() == QEvent::Resize)
    {
        if(fireworks != nullptr)
            fireworks->update();
    }

    return QWidget::eventFilter(watched, event);
}

void GradeSubmission::on_studentName_currentIndexChanged(int index)
{
    qDebug()<<"Student name changed"<< index;
    if (index <= 0 || index == ui->studentName->findText(_submission->_student->_name))
        return;
    QString student_name = ui->studentName->itemText(index);
    qDebug()<<"name : "<< student_name;
    Student *selected_student = _submission->_student->_section->get_student(student_name);
    Submission *selected_submission = selected_student->get_submission(_submission->_assignment);
    emit(switched_submission(selected_submission));
}

void GradeSubmission::show_dashboard() {
    _parent->show_submissions(_submission->_student->_section,
                              _submission->_assignment);
}

void GradeSubmission::next_submission() {
    emit(switched_submission(_submission->_student->_section->get_random_ungraded(_submission->_assignment)));
}

void GradeSubmission::update_progress() {
    Section *section = _submission->_student->_section;
    ui->progressBar->setMaximum(section->num_submissions_total(_submission->_assignment));
    ui->progressBar->setValue(section->num_submissions_graded(_submission->_assignment));
    if (!_parent->submissions->_finished_grading && section->num_submissions_ungraded(_submission->_assignment) == 0 && section->num_submissions_total(_submission->_assignment) != 0) {
        display_fireworks();
        _parent->submissions->_finished_grading = true;
    }
}

void GradeSubmission::display_fireworks() {
    if(fireworks != nullptr)
        delete fireworks;
    fireworks = new Fireworks(this);
    fireworks->show();
    QTimer::singleShot(6000, this, SLOT(hide_fireworks()));
}

void GradeSubmission::hide_fireworks() {
    if(fireworks != nullptr)
        fireworks->hide();
}

void GradeSubmission::on_finalize_clicked()
{
    if (_submission->_status == 2) {
        _submission->update_status(1);
    } else {
        _submission->update_status(2);
    }
    grade_view->update_status();

}

void GradeSubmission::on_exportpdf_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, tr("Save report in..."), "~/",
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (folder != "") {
        StudentDeliverable s;
        QString html = s.placeParameters(_submission);
        HTMLToPDF* report = new HTMLToPDF(html, folder + "/" + _submission->_student->_name + ".pdf");
    }
}

void GradeSubmission::update_finalize_button()
{
    ui->finalize->setText((_submission->_status == 2)? "Unlock submission" : "Finalize");
}
