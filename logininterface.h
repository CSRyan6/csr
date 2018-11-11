#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H

#include <QWidget>
#include "mainwindow.h"
#include "registe.h"
#include "QKeyEvent"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QSettings>

extern QSqlDatabase database;

namespace Ui {
class logininterface;
}

class logininterface : public QWidget
{
    Q_OBJECT

public:
    explicit logininterface(QWidget *parent = 0);
    ~logininterface();
    MainWindow w;
    registe r;

    QString id;
    QString password;
    bool rememberflag;
    void save();

private slots:
    void on_login_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_registe_clicked();
    void on_remember_clicked();

private:
    Ui::logininterface *ui;
    QSqlQuery sql_query;

};

#endif // LOGININTERFACE_H
