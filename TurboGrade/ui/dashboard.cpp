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

    setAttribute(Qt::WA_AcceptTouchEvents, true);

}

Dashboard::~Dashboard()
{
    delete _controller;
    delete ui;
    delete courses;
    if (sections != nullptr)
        delete sections;
}

void Dashboard::show_courses() {
    remove_current_widget();
    courses = new CourseView(this, _controller);
    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);
}

void Dashboard::show_sections(QObject* course) {
    remove_current_widget();
    sections = new SectionView(this, course, _controller);
    ui->mainWidget->addWidget(sections);
    ui->mainWidget->setCurrentWidget(sections);
}

void Dashboard::show_assignments(QObject* section) {
    remove_current_widget();
    assignments = new AssignmentView(this, section, _controller);
    ui->mainWidget->addWidget(assignments);
    ui->mainWidget->setCurrentWidget(assignments);
}


void Dashboard::show_students(QObject* section) {
    remove_current_widget();
    students = new StudentView(this, section, _controller);
    ui->mainWidget->addWidget(students);
    ui->mainWidget->setCurrentWidget(students);
}


void Dashboard::show_submissions(QObject* section, QObject* assignment) {
    remove_current_widget();
    submissions = new SubmissionView(this, section, assignment, _controller);
    ui->mainWidget->addWidget(submissions);
    ui->mainWidget->setCurrentWidget(submissions);
}

void Dashboard::start_grading(QObject* submission) {
    if (submission == nullptr)
        return;
    remove_current_widget();
    grade_submission = new GradeSubmission(this, (Submission*)submission, _controller);
    ui->mainWidget->addWidget(grade_submission);
    ui->mainWidget->setCurrentWidget(grade_submission);
    connect(grade_submission, SIGNAL(switched_submission(QObject*)), this, SLOT(start_grading(QObject*)));
}

void Dashboard::remove_current_widget() {
    if (ui->mainWidget->currentWidget() != nullptr) {
        ui->mainWidget->removeWidget(ui->mainWidget->currentWidget());
        delete ui->mainWidget->currentWidget();
    }
}
