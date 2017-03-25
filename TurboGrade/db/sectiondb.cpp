#include "sectiondb.h"

/**
 * @brief Destructor
 */

SectionDB::~SectionDB() {

}

/**
 * @brief SectionDB::add Insert a row to the database
 * @param name the name of the section (ex. 01)
 * @param course_id the id of the course (ex. 1)
 * @return true if the query succeded
 */
int SectionDB::add(int course_id, const QString name) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO section (id, course_id, name) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(course_id);
    query.addBindValue(name);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'section' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return query.lastInsertId().toInt();
}


/**
 * @brief SectionDB::select Returns id of the row
 * that matches given name
 * @param course_name the name of the course (ex. CS 150)
 * @param name the name of the section (ex. 01)
 * @return the resulting ID
 */
int SectionDB::select(const QString course_name, const QString name) {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM section WHERE course_id = (SELECT id FROM course WHERE name=?) AND name = ?");
    query.addBindValue(course_name);
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'section'" << endl << "SQL ERROR: " << query.lastError();
        return -1;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    return -1;
}

/**
 * @brief SectionDB::load_course_sections loads a specific course's
 * sections to the controller
 * @param course_id the course whose sections will be loaded
 */
void SectionDB::load_all(Course *course) {

    QSqlQuery query(db);

    query.prepare("SELECT section.id AS section_id, section.name AS section_name"
                  " FROM section, course WHERE section.course_id = course.id AND"
                  " course.id = ?");

    query.addBindValue(course->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'section'" << endl << "SQL ERROR: " << query.lastError();
        return;
    }

    int section_id_field = query.record().indexOf("section_id");
    int section_name_field = query.record().indexOf("section_name");

    while(query.next()) {

        course->add_section(query.value(section_id_field).toInt(),
                            query.value(section_name_field).toString());

    }
}
