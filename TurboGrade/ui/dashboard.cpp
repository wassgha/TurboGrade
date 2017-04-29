#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    setWindowTitle("TurboGrade Dashboard");
    setAttribute(Qt::WA_StyledBackground, true);

    // Use new Controller(true) to drop tables
    _controller = new Controller();

    int id = QFontDatabase::addApplicationFont(":/fonts/res/Roboto-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    roboto = QFont(family);
    roboto.setPointSize(12);

    QApplication::setFont(roboto);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    courses = new CourseView(this, _controller);

    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);

    connect(ui->logo, SIGNAL(clicked()), this, SLOT(show_courses()));
}

Dashboard::~Dashboard()
{
    delete _controller;
    delete ui;
    delete courses;
    if (sections != nullptr)
        delete sections;
}

void Dashboard::on_tutorial_btn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UCwI9yC7wu9aIqDol47Ep2BA"));
}

void Dashboard::show_courses() {

    if (courses != nullptr) {
        ui->mainWidget->removeWidget(courses);
        delete courses;
    }
    courses = new CourseView(this, _controller);
    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);

}

void Dashboard::show_sections(QObject* course) {

    if (sections != nullptr) {
        ui->mainWidget->removeWidget(sections);
        delete sections;
    }
    sections = new SectionView(this, course, _controller);
    ui->mainWidget->addWidget(sections);
    ui->mainWidget->setCurrentWidget(sections);

}

void Dashboard::show_assignments(QObject* section) {

    if (assignments != nullptr) {
        ui->mainWidget->removeWidget(assignments);
        delete assignments;
    }
    assignments = new AssignmentView(this, section, _controller);
    ui->mainWidget->addWidget(assignments);
    ui->mainWidget->setCurrentWidget(assignments);

}


void Dashboard::show_students(QObject* section) {

    if (students != nullptr) {
        ui->mainWidget->removeWidget(students);
        delete students;
    }
    students = new StudentView(this, section, _controller);
    ui->mainWidget->addWidget(students);
    ui->mainWidget->setCurrentWidget(students);

}


void Dashboard::show_submissions(QObject* section, QObject* assignment) {

    if (submissions != nullptr) {
        ui->mainWidget->removeWidget(submissions);
        delete submissions;
    }
    submissions = new SubmissionView(this, section, assignment, _controller);
    ui->mainWidget->addWidget(submissions);
    ui->mainWidget->setCurrentWidget(submissions);

}

void Dashboard::start_grading(QObject* submission) {
    if (submission == nullptr)
        return;
    if (grade_submission != nullptr)
        delete grade_submission;
    grade_submission = new GradeSubmission(this, (Submission*)submission, _controller);
    grade_submission->show();
    connect(grade_submission, SIGNAL(switched_submission(QObject*)), this, SLOT(start_grading(QObject*)));
}
