#include "dbengine.h"

/**
 * @brief DBEngine::DBEngine Constructor, builds all the
 * required tables inside the database if they do not
 * already exist
 */
DBEngine::DBEngine()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/turbograde.sqlite");

    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    // Class Table

    sql_query("CREATE TABLE IF NOT EXISTS class (id INTEGER PRIMARY KEY, \
              name VARCHAR(50))");

    // Student Table
    sql_query("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY, \
                class_id INTEGER, name VARCHAR(50),\
                username VARCHAR(23),\
                FOREIGN KEY(class_id) REFERENCES class(id))");

    // Assignment Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment (id INTEGER PRIMARY KEY, \
               name VARCHAR(50),\
               objective TEXT)");

    // AssignmentSection Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment_section (id INTEGER PRIMARY KEY, \
               assignment INTEGER,\
               section INTEGER,\
               folder TEXT,\
              FOREIGN KEY(assignment) REFERENCES assignment(id),\
              FOREIGN KEY(section) REFERENCES section(id))");

    // Submission Table
    sql_query("CREATE TABLE IF NOT EXISTS submission (id INTEGER PRIMARY KEY, \
               student INTEGER,\
               assignment_section INTEGER,\
              FOREIGN KEY(student) REFERENCES student(id),\
              FOREIGN KEY(assignment_section) REFERENCES assignment_section(id))");

    // File Table
    sql_query("CREATE TABLE IF NOT EXISTS file (id INTEGER PRIMARY KEY, \
               submission INTEGER,\
               filename VARCHAR(255),\
              FOREIGN KEY(submission) REFERENCES submission(id))");


    // CommentText Table
    sql_query("CREATE TABLE IF NOT EXISTS comment_text (id INTEGER PRIMARY KEY, \
               comment_text TEXT)");

    // Comment Table
    sql_query("CREATE TABLE IF NOT EXISTS comment (id INTEGER PRIMARY KEY, \
               file INTEGER,\
               rubric INTEGER,\
               comment_text INTEGER,\
               grade INT,\
               position VARCHAR(255),\
              FOREIGN KEY(file) REFERENCES file(id),\
              FOREIGN KEY(rubric) REFERENCES rubric(id),\
              FOREIGN KEY(comment_text) REFERENCES comment_text(id))");

    // Rubric Table
    // Note: A rubric section is auto-suggested when it has no parent
    // Note: A rubric section is considered extra-credit if it is out of 0
    sql_query("CREATE TABLE IF NOT EXISTS rubric (id INTEGER PRIMARY KEY, \
               rubric_name VARCHAR(100),\
               assignment INTEGER,\
               parent INTEGER,\
               grade_out_of INT,\
               FOREIGN KEY(assignment) REFERENCES assignment(id),\
               FOREIGN KEY(parent) REFERENCES rubric(id))");

    // Grades Table
    sql_query("CREATE TABLE IF NOT EXISTS grade (id INTEGER PRIMARY KEY, \
               rubric INTEGER,\
               submission INTEGER,\
               grade INT,\
              FOREIGN KEY(rubric) REFERENCES rubric(id),\
              FOREIGN KEY(submission) REFERENCES submission(id))");
}

/**
 * @brief DBEngine::~DBEngine Frees all allocated
 * memory and quits
 */
DBEngine::~DBEngine()
{
    db.close();
}

/**
 * @brief Executes a SQL query on the database
 * @param query the SQL query to execute
 */
void DBEngine::sql_query(const QString &query_text) {
    // Create query
    QSqlQuery query;

    // Execute and show error if it exists
    if (!query.exec(query_text))
        qDebug() << query_text << endl << "SQL Error: " << query.lastError();

}
