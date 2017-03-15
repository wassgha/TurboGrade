#include "dbengine.h"

/**
 * @brief DBEngine::DBEngine Constructor, builds all the
 * required tables inside the database if they do not
 * already exist
 */
DBEngine::DBEngine()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/turbograde.sqlite");

    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    // Class Table

    sql_query("CREATE TABLE IF NOT EXISTS class (id INT PRIMARY KEY, \
              name VARCHAR(50))");

    // Student Table
    sql_query("CREATE TABLE IF NOT EXISTS student (id INT PRIMARY KEY, \
                class_id INT, name VARCHAR(50),\
                username VARCHAR(23),\
                FOREIGN KEY(class_id) REFERENCES class(id))");

    // Assignment Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment (id INT PRIMARY KEY, \
               name VARCHAR(50),\
               objective TEXT)");

    // AssignmentSection Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment_section (id INT PRIMARY KEY, \
               assignment INT,\
               section INT,\
               folder TEXT,\
              FOREIGN KEY(assignment) REFERENCES assignment(id),\
              FOREIGN KEY(section) REFERENCES section(id))");

    // Submission Table
    sql_query("CREATE TABLE IF NOT EXISTS submission (id INT PRIMARY KEY, \
               student INT,\
               assignment_section INT,\
              FOREIGN KEY(student) REFERENCES student(id),\
              FOREIGN KEY(assignment_section) REFERENCES assignment_section(id))");

    // File Table
    sql_query("CREATE TABLE IF NOT EXISTS file (id INT PRIMARY KEY, \
               submission INT,\
               filename VARCHAR(255),\
              FOREIGN KEY(submission) REFERENCES submission(id))");


    // CommentText Table
    sql_query("CREATE TABLE IF NOT EXISTS comment_text (id INT PRIMARY KEY, \
               comment_text TEXT)");

    // Comment Table
    sql_query("CREATE TABLE IF NOT EXISTS comment (id INT PRIMARY KEY, \
               file INT,\
               rubric INT,\
               comment_text INT,\
               grade INT,\
               position VARCHAR(255),\
              FOREIGN KEY(file) REFERENCES file(id),\
              FOREIGN KEY(rubric) REFERENCES rubric(id),\
              FOREIGN KEY(comment_text) REFERENCES comment_text(id))");

    // Rubric Table
    // Note: A rubric section is auto-suggested when it has no parent
    // Note: A rubric section is considered extra-credit if it is out of 0
    sql_query("CREATE TABLE IF NOT EXISTS rubric (id INT PRIMARY KEY, \
               rubric_name VARCHAR(100),\
               assignment INT,\
               parent INT,\
               grade_out_of INT,\
               FOREIGN KEY(assignment) REFERENCES assignment(id),\
               FOREIGN KEY(parent) REFERENCES rubric(id))");

    // Grades Table
    sql_query("CREATE TABLE IF NOT EXISTS grade (id INT PRIMARY KEY, \
               rubric INT,\
               submission INT,\
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
        qDebug() << query_text << endl << "SQL ERROR: " << query.lastError();

}
