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
    _controller = new Controller(true);

//    Course* cs105 = _controller->add_course("CS 105");
//    _controller->add_course("CS 150");
//    Course* cs150 = _controller->get_courses()->at(1);
//    cs150->add_section("01");
//    cs105->add_section("01");
//    Section * cs150_02 = cs105->add_section(-1, "02");
//    cs150_02->add_student("Wassim Gharbi", "gharbiw");
//    cs150_02->add_student("Darren Norton", "nortondj");
//    cs105->add_section("03");
//    _controller->add_assignment("Binary Search Tree", "Implement a binary search tree with polymorphism");
//    Assignment *bst_assignment = _controller->get_assignments()->at(0);
//    cs150_02->add_assignment(bst_assignment);
//    Section* cs105_01 = cs105->_sections->at(0);
//    cs105_01->add_assignment(bst_assignment);


//    bst_assignment->_rubric->add_criterion("Correctness", NULL, 10);
//    bst_assignment->_rubric->add_criterion("Design", NULL, 5);
//    Criterion* comments = bst_assignment->_rubric->add_criterion("Comments", NULL, 2);
//    bst_assignment->_rubric->add_criterion("JavaDoc", comments, 2);

//    Student * gharbiw = cs150_02->get_student("Wassim Gharbi");
//    Submission* gharbiw_01 = gharbiw->add_submission(bst_assignment);
//    gharbiw_01->add_comment("main.java", bst_assignment->_rubric->get_criterion("Correctness"),
//                            "You screwed up bro", -2, 20, 150);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Correctness"), 4);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Design"), 3);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("JavaDoc"), 2);

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
    if (grade_submission != nullptr)
        delete grade_submission;
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

    if (grade_submission != nullptr)
        delete grade_submission;
    grade_submission = new GradeSubmission(this, (Submission*)submission, _controller);
    grade_submission->show();

}
