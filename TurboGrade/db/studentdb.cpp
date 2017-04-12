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
int StudentDB::add(int section_id, const QString name, const QString username) {

    SHOW_WHERE;

    db.transaction();
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

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();
    db.commit();

    return last_insert_id;
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

    db.transaction();
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
        return -1;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    db.commit();
    return -1;
}

/**
 * @brief StudentDB::load_all loads all database records
 * to the controller
 */
void StudentDB::load_all(Section* section) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT student.name, student.username, student.id "
                  "FROM student "
                  "WHERE student.section_id = ?");

    query.addBindValue(section->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'student' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int id_field = query.record().indexOf("id");
    int name_field = query.record().indexOf("name");
    int username_field = query.record().indexOf("username");

    while(query.next()) {
        section->add_student(query.value(id_field).toInt(),
                             query.value(name_field).toString(),
                             query.value(username_field).toString());
    }

    query.finish();
    db.commit();
}
