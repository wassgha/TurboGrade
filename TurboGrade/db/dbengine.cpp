#include "dbengine.h"

/**
 * @brief DBEngine::DBEngine Constructor, builds all the
 * required tables inside the database if they do not
 * already exist
 */

DBEngine::DBEngine(QString connectionName, QString dbname)
{

    _connectionName.append(connectionName);

    if( !QSqlDatabase::contains( _connectionName ) )
        db = QSqlDatabase::addDatabase("QSQLITE", _connectionName);
    else
        db = QSqlDatabase::database(_connectionName);

    db.setDatabaseName(dbname);
    QDir dir(QCoreApplication::applicationDirPath());

    if (!db.open()) {
        std::cerr<<"Cannot open database : "<<dir.absoluteFilePath(dbname).toStdString().c_str()<<std::endl;
        return;
    }

    // Course Table

    sql_query("CREATE TABLE IF NOT EXISTS course (id INTEGER PRIMARY KEY, \
              name VARCHAR(50) UNIQUE)");

    // Section Table

    sql_query("CREATE TABLE IF NOT EXISTS section (id INTEGER PRIMARY KEY, \
              course_id INTEGER,\
              name VARCHAR(50),\
              FOREIGN KEY(course_id) REFERENCES course(id))");

    // Student Table
    sql_query("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY, \
               section_id INTEGER, \
               name VARCHAR(50),\
               username VARCHAR(50),\
               FOREIGN KEY(section_id) REFERENCES section(id),\
               CONSTRAINT uniq UNIQUE (section_id, name))");

    // Assignment Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment (id INTEGER PRIMARY KEY, \
               name VARCHAR(50) UNIQUE,\
               objective TEXT)");

    // AssignmentSection Table
    sql_query("CREATE TABLE IF NOT EXISTS assignment_section (id INTEGER PRIMARY KEY, \
               assignment INTEGER,\
               section INTEGER,\
               FOREIGN KEY(assignment) REFERENCES assignment(id),\
               FOREIGN KEY(section) REFERENCES section(id))");

    // Submission Table
    sql_query("CREATE TABLE IF NOT EXISTS submission (id INTEGER PRIMARY KEY, \
               student INTEGER,\
               assignment INTEGER,\
               FOREIGN KEY(student) REFERENCES student(id),\
               FOREIGN KEY(assignment) REFERENCES assignment(id))");

    // Comment Table
    sql_query("CREATE TABLE IF NOT EXISTS comment (id INTEGER PRIMARY KEY, \
               submission INTEGER, \
               filename VARCHAR(50),\
               rubric INTEGER,\
               comment_text TEXT,\
               grade INT,\
               start_pos INT,\
               end_pos INT,\
               FOREIGN KEY(submission) REFERENCES submission(id),\
               FOREIGN KEY(rubric) REFERENCES rubric(id))");

    // Rubric Table
    // Note: A rubric section is auto-suggested when it has no parent
    // Note: A rubric section is considered extra-credit if it is out of 0
    sql_query("CREATE TABLE IF NOT EXISTS rubric (id INTEGER PRIMARY KEY, \
               name VARCHAR(100),\
               assignment INTEGER,\
               parent INTEGER,\
               grade_out_of INT,\
               FOREIGN KEY(assignment) REFERENCES assignment(id),\
               FOREIGN KEY(parent) REFERENCES rubric(id))");

    // Grades Table
    sql_query("CREATE TABLE IF NOT EXISTS grade (id INTEGER PRIMARY KEY, \
               rubric INTEGER,\
               submission INTEGER,\
               score INT,\
               FOREIGN KEY(rubric) REFERENCES rubric(id),\
               FOREIGN KEY(submission) REFERENCES submission(id),\
               CONSTRAINT unq UNIQUE (rubric, submission))");
}

/**
 * @brief DBEngine::~DBEngine Frees all allocated
 * memory and quits
 */
DBEngine::~DBEngine()
{
    QSqlDatabase::database(_connectionName).close();
}

/**
 * @brief Executes a SQL query on the database
 * @param query the SQL query to execute
 */
void DBEngine::sql_query(const QString &query_text) {
    // Create query
    db.transaction();
    QSqlQuery query(db);


    // Execute and show error if it exists
    if (!query.exec(query_text))
        qDebug() << query_text << endl << "SQL Error: " << query.lastError();

    query.finish();
    db.commit();

}

/**
 * @brief DBEngine::drop_tables (CAUTION!) deletes all
 * information stored in the database.
 */
void DBEngine::drop_tables()
{
    // Drop all tables
    sql_query("DROP TABLE course;");
    sql_query("DROP TABLE section;");
    sql_query("DROP TABLE student;");
    sql_query("DROP TABLE assignment;");
    sql_query("DROP TABLE assignment_section;");
    sql_query("DROP TABLE submission;");
    sql_query("DROP TABLE comment;");
    sql_query("DROP TABLE grade;");
    sql_query("DROP TABLE rubric;");
}
