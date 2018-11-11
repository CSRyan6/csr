#include "logininterface.h"
#include "ui_logininterface.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registe.h"
#include "ui_registe.h"
#include "QDebug"
#include "QKeyEvent"
#include "QMessageBox"

logininterface::logininterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logininterface)
{
    ui->setupUi(this);

    connect(this->w.ui->change,SIGNAL(clicked()),this,SLOT(show()) );
    connect(this->r.ui->back,SIGNAL(clicked()),this,SLOT(show()) );

    ui->password->setEchoMode(QLineEdit::Password);                 //密码栏不显示

    QSettings cfg("user.ini",QSettings::IniFormat);                 //从配置文件中读取记录信息完成记住密码功能
    id = cfg.value("id").toString();
    rememberflag = cfg.value("rememberflag").toBool();
    ui->id->setText(id);
    if(rememberflag == true)
    {
        ui->remember->setChecked(true);
        password = cfg.value("password").toString();
        ui->password->setText(password);
    }

//    QString create_sql = "create table user (id QString,username QString,password QString,level int)";
//    sql_query.prepare(create_sql);

    QString insert_sql = "insert into user values (?, ?, ?, ?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue("a");
    sql_query.addBindValue("ab");
    sql_query.addBindValue("abc");
    sql_query.addBindValue(1);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "inserted!";
    }

    QString select_sql = "select id from user";
    sql_query.exec(select_sql);
    while(sql_query.next())
    {
        qDebug() << "1";
        qDebug() << sql_query.value(0).toString();
    }

    QString clear_sql = "delete from user";
    sql_query.prepare(clear_sql);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "table cleared";
    }
}

logininterface::~logininterface()
{
    delete ui;
}

void logininterface::on_login_clicked()
{
    if(ui->id->text() == NULL)
    {
        QMessageBox::information(NULL,tr("提示"),tr("请输入账号"));
        qDebug() << "wrong";
    }
    else
    {
        if(ui->id->text() == "123")
        {
            if(ui->password->text() == NULL)
            {
                QMessageBox::information(NULL,tr("提示"),tr("请输入密码"));
                qDebug() << "nil password";
            }
            else
            {
                if(ui->password->text() == "456")
                {
                    w.show();
                    save();
                    this->hide();
                }
                else
                {
                    QMessageBox::information(NULL,tr("提示"),tr("密码错误请重新输入"));
                }
            }
        }
    }
}

void logininterface::keyPressEvent(QKeyEvent *event)
{
    on_login_clicked();
}

void logininterface::on_registe_clicked()
{
    this->hide();
    r.show();
}

void logininterface::on_remember_clicked()
{
    if(ui->remember->isChecked())
    {
        rememberflag = true;
        qDebug() << "true";
    }
    else
    {
        qDebug() << "false";
        rememberflag = false;
    }
}

void logininterface::save()
{
    QSettings cfg("user.ini",QSettings::IniFormat);
    id = ui->id->text();
    password = ui->password->text();
    cfg.setValue("id",id);
    cfg.setValue("password",password);
    cfg.setValue("rememberflag",rememberflag);
    cfg.sync();
}
