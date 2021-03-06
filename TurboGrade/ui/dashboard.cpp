#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
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

    preferences = new Preferences(this, _controller);

    // Create Git connection and pull data/database
    _last_sync = QTime::currentTime();

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(update_sync()));
    _timer->start(8000);

}

Dashboard::~Dashboard()
{
    delete _controller;
    delete ui;
    delete courses;
    delete _timer;
    if (sections != nullptr)
        delete sections;
}

void Dashboard::on_tutorial_btn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UCwI9yC7wu9aIqDol47Ep2BA"));
}

void Dashboard::show_courses() {
    remove_current_widget();
    courses = new CourseView(this, _controller);
    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);
    toggle_headers(true);

}

void Dashboard::show_sections(QObject* course) {
    remove_current_widget();
    sections = new SectionView(this, course, _controller);
    ui->mainWidget->addWidget(sections);
    ui->mainWidget->setCurrentWidget(sections);
    toggle_headers(true);

}

void Dashboard::show_assignments(QObject* section) {
    remove_current_widget();
    assignments = new AssignmentView(this, section, _controller);
    ui->mainWidget->addWidget(assignments);
    ui->mainWidget->setCurrentWidget(assignments);
    toggle_headers(true);
}


void Dashboard::show_students(QObject* section) {
    remove_current_widget();
    students = new StudentView(this, section, _controller);
    ui->mainWidget->addWidget(students);
    ui->mainWidget->setCurrentWidget(students);
    toggle_headers(true);
}


void Dashboard::show_submissions(QObject* section, QObject* assignment) {
    remove_current_widget();
    submissions = new SubmissionView(this, section, assignment, _controller);
    ui->mainWidget->addWidget(submissions);
    ui->mainWidget->setCurrentWidget(submissions);
    toggle_headers(true);
}

void Dashboard::start_grading(QObject* submission) {
    if (submission == nullptr)
        return;
    remove_current_widget();
    grade_submission = new GradeSubmission(this, (Submission*)submission, _controller);
    ui->mainWidget->addWidget(grade_submission);
    ui->mainWidget->setCurrentWidget(grade_submission);
    toggle_headers(false);
    connect(grade_submission, SIGNAL(switched_submission(QObject*)), this, SLOT(start_grading(QObject*)));
}

void Dashboard::remove_current_widget() {
    if (ui->mainWidget->currentWidget() != nullptr) {
        ui->mainWidget->removeWidget(ui->mainWidget->currentWidget());
        delete ui->mainWidget->currentWidget();
    }
}

void Dashboard::toggle_headers(bool show) {
    if (show) {
        ui->tutorial->show();
        ui->header->show();
        setWindowState(Qt::WindowActive);
        resize(760, 475);
    } else {
        ui->tutorial->hide();
        ui->header->hide();
        showFullScreen();
    }
}


/**************************************
 *        Git synchronization               *
 **************************************/

void Dashboard::update_git() {
    _controller->sync_git();
    _last_sync = QTime::currentTime();
}

void Dashboard::update_sync() {
    ui->last_synced->setText("Last Synced : " + time_elapsed(_last_sync.secsTo(QTime::currentTime())) + " ago");
}


QString Dashboard::time_elapsed(int time) {
    time = abs(time);
    time = (time<1)? 1 : time;
    std::vector<std::pair<int, QString>> tokens;
    tokens.push_back(std::make_pair(31536000, "year"));
    tokens.push_back(std::make_pair(2592000, "month"));
    tokens.push_back(std::make_pair(604800, "week"));
    tokens.push_back(std::make_pair(86400, "day"));
    tokens.push_back(std::make_pair(3600, "hour"));
    tokens.push_back(std::make_pair(60, "minute"));
    tokens.push_back(std::make_pair(1, "second"));
    for (std::pair<int, QString> token : tokens) {
        if(time<token.first) continue;
        int numberOfUnits = floor(time/token.first);
        return (numberOfUnits == 1?"a":QString::number(numberOfUnits)) + " " + token.second + (numberOfUnits>1?"s":"");
    }
}

void Dashboard::on_sync_now_clicked()
{
    update_git();
    update_sync();
}

void Dashboard::on_actionPreferences_triggered()
{
    preferences->show();
}
