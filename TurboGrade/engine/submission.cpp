#include "submission.h"

/**
 * @brief Submission::Submission creates a submission and adds it to the
 * database if it doesn't exist
 * @param id the table id for the submission (-1 if this is a new entry)
 * @param assignment the assignment this submission belongs to
 * @param student the student this submission belongs to
 * @param status whether the submission has been graded or not
 * @param controller the current controller
 */
Submission::Submission(Assignment *assignment,
                       Student* student, Controller * controller, int status,
                       int id)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_submissionDB->add(student->_id, assignment->_id, status);
    else
        _id = id;

    _assignment = assignment;
    _student = student;
    _status = status;

    // Submission comments
    _comments = new std::vector<Comment*>();
    // Submission grades
    _grades = new std::map<Criterion*, int>();
    // Load grade and comments
    load_contents();

}


/**
 * @brief Submission::load_contents loads the comments
 * and the grades of the submission
 */
void Submission::load_contents() {
    std::cout<<"Loading grades..";
    _controller->_gradeDB->load_all(this, _assignment->_rubric->_criteria);
    std::cout<<"Loading comments..";
    _controller->_commentDB->load_all(this);
}


/**
 * @brief Submission::add_comment adds a comment made on this submission
 */
void Submission::add_comment(QString filename,
                             Criterion *criterion,
                             QString text, int grade,
                             int start_pos, int end_pos,
                             int id) {

    Comment *new_comment = new Comment(this, filename, criterion, text, grade, start_pos, end_pos, _controller, id);

    _comments->push_back(new_comment);

    _controller->_all_comments<<text;

}

/**
 * @brief Submission::get_comment returns a list of comments
 * on a specific file in the submission
 * @return the list of comments
 */
std::vector<Comment*> Submission::get_comment(QString filename) {

    std::vector<Comment*> result;

    for(Comment* comment : *_comments)
        if (comment->_filename == filename)
            result.push_back(comment);

    std::sort(result.begin(), result.end(), [] (Comment *a, Comment *b) { return a->_start_pos < b->_start_pos; } );


    return result;

}

/**
 * @brief Submission::add_grade adds a grade to a specific criterion,
 * @param criterion the criterion
 * @param grade the value to set the grade to
 */
void Submission::add_grade(Criterion *criterion, int grade, bool load){
    _grades->erase(criterion);
    _grades->emplace(std::make_pair(criterion, grade));
    if (!load)
        _controller->_gradeDB->add(criterion->_id, _id, grade);
}

/**
 * @brief Submission::update_grade updates the grade for a specific criterion,
 * @param criterion the criterion
 * @param grade the value to set the grade to
 */
void Submission::update_grade(Criterion *criterion, int grade, bool load){
    if (criterion == nullptr)
        return;
    _grades->erase(criterion);
    _grades->emplace(std::make_pair(criterion, grade));
    if (!load)
        _controller->_gradeDB->update(criterion->_id, _id, grade);
}


/**
 * @brief Submission::attribute_full_grade sets every criterion to the maximum
 * grade available
 */
void Submission::attribute_full_grade() {
    for (Criterion* criterion : *_assignment->_rubric->_criteria) {
        if (criterion->has_children()) {
            for (Criterion* child : criterion->children()) {
                update_grade(child, child->_out_of);
            }
        } else {
            update_grade(criterion, criterion->_out_of);
        }
    }
}

/**
 * @brief Submission::get_grades getter for the _grades map
 * @return the _grades map containing Criterion, grade mappings
 */
std::map<Criterion*, int> *Submission::get_grades(){
    return _grades;
}

/**
 * @brief Submission::get_grade retrieves the grade for the given criterion
 * @param criterion the criterion in question
 * @return the grade for that criterion, -1 if non existant
 */
int Submission::get_grade(Criterion *criterion){
    try {
        if (criterion == nullptr)
            return -1;

        if (!criterion->has_children()) {
            return _grades->at(criterion);
        }
        int grade = 0;
        for(Criterion* child : criterion->children()) {
            grade += get_grade(child);
        }
        return grade;
    }
    catch (const std::out_of_range& e) {
        qDebug() << "Tried to access grade for criterion not in map.";
        return -1;
    }
}

int Submission::get_out_of(){
    int sum = 0;
    for(Criterion *criterion: *_assignment->_rubric->_criteria){
        for(Criterion *sub_criterion: *criterion->_sub_criteria){
            sum+= sub_criterion->_out_of;
        }
        sum+= criterion->_out_of;
    }
    return sum;
}

/**
 * @brief Submission::get_grade retrieves the total grade
 * @return the grade for this submission
 */
int Submission::get_grade(){
    int grade = 0;
    for (Criterion* criterion :  *_assignment->_rubric->_criteria)  {
        if (get_grade(criterion) != -1)
            grade += get_grade(criterion);
    }
    return grade;
}

/**
 * @brief Submission::getPath
 * @return the path where the submission files are stored
 */
QString Submission::getPath() {

    return QCoreApplication::applicationDirPath()
    + "/data/"
    + QString::number(_student->_section->_course->_id)
    + "/"
    + QString::number(_student->_section->_id)
    + "/"
    + QString::number(_assignment->_id)
    + "/"
    + _student->_name
    + "/";

}

/**
 * @brief Submission::get_comments given a criterion, searches through each
 * comment and if there is a match, adds the Comment to the result.
 * @param criterion
 * @return the list of comments that match a criterion
 */
std::vector<Comment *> Submission::get_comments(Criterion *criterion){
    std::vector<Comment *> comment_vec;
    for(Comment *comment:*_comments){
        if(comment->_criterion == criterion){
            comment_vec.push_back(comment);
        }
    }
    return comment_vec;
}

Submission::~Submission()
{
    for (Comment* comment : *_comments)
        delete comment;
    delete _comments;
    delete _grades;
}


float Submission::grade_percent() {
    return (_assignment->_rubric->total_grade() == 0
         ?
         0
         :
         100*get_grade()/_assignment->_rubric->total_grade()
     );
}
