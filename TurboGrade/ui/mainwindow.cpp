#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _controller = new Controller(true);

    Course* cs105 = _controller->add_course(-1, "CS 105");
    _controller->add_course(-1, "CS 150");
    Course* cs150 = _controller->get_courses()->at(1);
    cs150->add_section(-1, "01");
    cs105->add_section(-1, "01");
    Section * cs150_02 = cs105->add_section(-1, "02");
    cs150_02->add_student(-1, "Wassim Gharbi", "gharbiw");
    cs150_02->add_student(-1, "Darren Norton", "nortondj");
    cs105->add_section(-1, "03");
    _controller->add_assignment(-1, "Binary Search Tree", "Implement a binary search tree with polymorphism");
    Assignment *bst_assignment = _controller->get_assignments()->at(0);
    cs150_02->add_assignment(bst_assignment, "/Users/wassgha/Downloads/CS150_02");
    Section* cs105_01 = cs105->_sections->at(0);
    cs105_01->add_assignment(bst_assignment, "/Users/wassgha/Downloads/CS105_01");



    bst_assignment->_rubric->add_criterion(-1, "Correctness", NULL, 10);
    bst_assignment->_rubric->add_criterion(-1, "Design", NULL, 5);
    Criterion* comments = bst_assignment->_rubric->add_criterion(-1, "Comments", NULL, 2);
    bst_assignment->_rubric->add_criterion(-1, "JavaDoc", comments, 2);

    Student * gharbiw = cs150_02->get_student("gharbiw");
    Submission* gharbiw_01 = gharbiw->add_submission(-1, bst_assignment);
    gharbiw_01->add_comment(-1, "main.java", bst_assignment->_rubric->get_criterion("Correctness"),
                            "You screwed up bro", -2, 20, 150);

    int id = QFontDatabase::addApplicationFont(":/fonts/res/Roboto-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    roboto = QFont(family);
    roboto.setPointSize(14);

    QApplication::setFont(roboto);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    dashboard = new Dashboard(this->parentWidget(), _controller);
    dashboard->setFont(roboto);
    grade_submission = new GradeSubmission(this->parentWidget(), _controller);
    grade_submission->setFont(roboto);

    ui->mainWidget->addWidget(dashboard);
    ui->mainWidget->addWidget(grade_submission);
    ui->mainWidget->setCurrentWidget(dashboard);
}

MainWindow::~MainWindow()
{

    delete _controller;
    delete dashboard;
    delete grade_submission;
    delete ui;
}

