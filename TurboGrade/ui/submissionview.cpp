#include "submissionview.h"

SubmissionView::SubmissionView(QWidget* parent, QObject* section,
                               QObject* assignment, Controller* controller):
    ListView(parent)
{

    _controller = controller;
    _section = (Section*)section;
    _assignment = (Assignment*)assignment;

    add_dialog = new FormDialog(this, "Import Submissions");
    add_dialog->add_field("QLabel", "info", "Submissions are copied and stored within TurboGrade, \n"
                                             "you can delete the original folder if you wish.");
    add_dialog->add_field("QLabel", "instructions", "Please unzip the Moodle submissions and point \n"
                                                    "to the folder where you unzipped them.");
    add_dialog->add_field("QFileDialog", "select_folder", "Choose folder", ":/misc/res/folder.png");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(import_submission()));

    add_btn = new QPushButton("Import submissions");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    export_csv_btn = new QPushButton("Export Grades (CSV)");
    export_csv_btn->setFlat(true);
    export_csv_btn->setCursor(Qt::PointingHandCursor);
    export_csv_btn->setObjectName("export_csv_btn");
    QPixmap csv_icon(":/misc/res/csv.png");
    export_csv_btn->setIcon(QIcon(csv_icon).pixmap(64));
    export_csv_btn->setIconSize(QSize(20,20));
    connect(export_csv_btn, SIGNAL(clicked(bool)), this, SLOT(export_csv()));


    export_pdf_btn = new QPushButton("Export Reports (PDF)");
    export_pdf_btn->setFlat(true);
    export_pdf_btn->setCursor(Qt::PointingHandCursor);
    export_pdf_btn->setObjectName("export_pdf_btn");
    QPixmap pdf_icon(":/misc/res/pdf.png");
    export_pdf_btn->setIcon(QIcon(pdf_icon).pixmap(64));
    export_pdf_btn->setIconSize(QSize(20,20));
    connect(export_pdf_btn, SIGNAL(clicked(bool)), this, SLOT(export_all_pdf()));


    _breadcrumb->add_item(_section->_course->_name, SLOT(show_sections(QObject*)), _section->_course);
    _breadcrumb->add_item(_section->_name, SLOT(show_assignments(QObject*)), _section);
    _breadcrumb->add_item(_assignment->_name, SLOT(show_submissions(QObject*)), _assignment, this);
    _breadcrumb->add_to_back(export_csv_btn);
    _breadcrumb->add_to_back(export_pdf_btn);
    ui->verticalLayout->insertWidget(0, _breadcrumb);

    refresh_cards();
}

void SubmissionView::show_submissions(QObject* assignment) {
    dynamic_cast<Dashboard*>(_parent)->show_submissions(_section, assignment);
}

void SubmissionView::show_assignments() {
    dynamic_cast<Dashboard*>(_parent)->show_assignments(_section);
}

void SubmissionView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Student* student : *_section->_students) {
        if (student->get_submission(_assignment) != nullptr) {
            Submission* submission = student->get_submission(_assignment);
            Card* new_submission = new Card(student->_name,
                                        "Grade : " +
                                        QString::number(100*submission->get_grade()/_assignment->_rubric->total_grade()) +
                                        "% (" +
                                        QString::number(submission->get_grade()) +
                                        " out of " +
                                        QString::number(_assignment->_rubric->total_grade()) +
                                        ")",
                                        student->_color, submission);
            cards.push_back(new_submission);
            connect(new_submission, SIGNAL(clicked(QObject*)), _parent, SLOT(start_grading(QObject*)));
            add_card(new_submission);
        }
    }

}

/**
 * @brief SubmissionView::import_submission gets submissions
 * from a downloaded Moodle folder and saves them locally
 */
void SubmissionView::import_submission() {

    QString local_path = QCoreApplication::applicationDirPath()
            + "/data/"
            + QString::number(_section->_course->_id)
            + "/"
            + QString::number(_section->_id)
            + "/"
            + QString::number(_assignment->_id);

    DirTools::copy_dir_recursive( add_dialog->val("select_folder"), local_path);


    QDir dir;

    dir.setPath(local_path);

    foreach (QString submission_folder, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        std::cout<<"Adding submission by "<< submission_folder.toStdString() << std::endl;
        qDebug()<<"Adding submission by "<< submission_folder << endl;
        Student* added_student = _section->get_student(submission_folder);
        if (added_student == nullptr) {
            _section->add_student(-1, submission_folder, "-");
            added_student = _section->get_student(submission_folder);
        }
        added_student->add_submission(-1, _assignment);
    }

    refresh_cards();

}


void SubmissionView::export_csv() {
    QString folder = QFileDialog::getSaveFileName(this, tr("Save CSV as"));
    CSVGenerator g;
    g.printProfessor(_section, _assignment, folder);
}


void SubmissionView::export_all_pdf() {
    QString folder = QFileDialog::getExistingDirectory(this, tr("Save reports in..."), QString(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}

