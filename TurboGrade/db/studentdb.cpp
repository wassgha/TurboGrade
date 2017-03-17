#include "studentdb.h"

/**
 * @brief Default constructor
 */
StudentDB::StudentDB()
{

}

/**
 * @brief Destructor
 */

StudentDB::~StudentDB() {

}

/**
 * @brief StudentDB::add Insert a row to the database
 * @param name the name of the student (ex. Wassim Gharbi)
 * @param username the student's username (ex. gharbiw)
 * @return true if the query succeded
 */
bool StudentDB::add(int section_id, const QString name, const QString username) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO student (id, section_id, name, username) "
                  "VALUES (NULL, ?, ?, ?)");
    query.addBindValue(section_id);
    query.addBindValue(name);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'student' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief StudentDB::select Returns id of the row
 * that matches the given student name
 * @param course_name the name of the course (ex. CS 150)
 * @param section_name the name of the student (ex. 02)
 * @param name the name of the student (ex. Wassim Gharbi)
 * @param username the username of the student (ex. gharbiw)
 * @return the resulting ID
 */
int StudentDB::select(const QString course_name, const QString section_name, const QString name, const QString username) {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM student WHERE name = ? AND username = ? AND "
                  "section_id = (SELECT id FROM section WHERE name = ? AND "
                  "course_id = (SELECT id FROM course WHERE name=?)) ");
    query.addBindValue(name);
    query.addBindValue(username);
    query.addBindValue(section_name);
    query.addBindValue(course_name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'student' (select)" << endl << "SQL ERROR: " << query.lastError();
        return NULL;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    return NULL;
}

/**
 * @brief StudentDB::load_all loads all database records
 * to the controller
 */
void StudentDB::load_all() {
    QSqlQuery query(db);

    query.prepare("SELECT student.name, student.username, section.name AS section_name, course.name AS course_name "
                  "FROM student, section, course "
                  "WHERE section.course_id = course.id "
                  "AND student.section_id = section.id");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'student' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int course_name_field = query.record().indexOf("course_name");
    int section_name_field = query.record().indexOf("section_name");
    int name_field = query.record().indexOf("name");
    int username_field = query.record().indexOf("username");

    while(query.next()) {

        _courseController->add_student(query.value(course_name_field).toString(),
                                       query.value(section_name_field).toString(),
                                       query.value(name_field).toString(),
                                       query.value(username_field).toString(),
                                       true);

    }
}



/**
 * @brief StudentDB::load_section_students loads a specific section's
 * students to the controller
 * @param section_id the section students belong to
 */
void StudentDB::load_section_students(int section_id) {

    QSqlQuery query(db);

    query.prepare("SELECT student.name, section.name AS section_name, course.name AS course_name "
                  "FROM student, section, course "
                  "WHERE section.course_id = course.id "
                  "AND student.section_id = section.id"
                  "AND student.section_id = ?"
                  "AND course.id = section.course_id");


    query.addBindValue(section_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'student' (load_section_students)" << endl << "SQL ERROR: " << query.lastError();
        return;
    }

    int course_name_field = query.record().indexOf("course_name");
    int section_name_field = query.record().indexOf("section_name");
    int name_field = query.record().indexOf("name");
    int username_field = query.record().indexOf("username");

    while(query.next()) {

        _courseController->add_student(query.value(course_name_field).toString(),
                                       query.value(section_name_field).toString(),
                                       query.value(name_field).toString(),
                                       query.value(username_field).toString(),
                                       true);

    }
}
