#include "mainwindow.h"
#include "logininterface.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

QSqlDatabase database;
QSqlQuery sql_query;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
        database.setUserName("StudyForum");
        database.setPassword("123456");
    }

    QSqlQuery sql_query;
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database";
    }
    QString create_sql = "create table user (id QString,username QString,password QString,level int)";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }

    logininterface l;
    l.show();

    return a.exec();
}
