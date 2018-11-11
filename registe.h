#ifndef REGISTE_H
#define REGISTE_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QMessageBox>

extern QSqlDatabase database;

namespace Ui {
class registe;
}

class registe : public QWidget
{
    Q_OBJECT

public:
    explicit registe(QWidget *parent = 0);
    ~registe();
    Ui::registe *ui;

    QString id;
    QString username;
    QString password;

private slots:
    void on_back_clicked();

    void on_confirm_clicked();

private:
    QSqlQuery sql_query;

};

#endif // REGISTE_H
