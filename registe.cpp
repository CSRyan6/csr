#include "registe.h"
#include "ui_registe.h"

registe::registe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registe)
{
    ui->setupUi(this);
}

registe::~registe()
{
    delete ui;
}

void registe::on_confirm_clicked()
{
    bool flag = 1;
    id = ui->id->text();
    username = ui->username->text();
    password = ui->password->text();
    if(id != NULL)
    {
        if(username != NULL)
        {
            if(password != NULL)
            {
                while(sql_query.next())
                {
                    if(sql_query.value(0).toString() == id)
                    {
                        flag = 0;
                        break;
                    }
                    qDebug() << "registe";
                }
                if(flag)
                {
                    QString insert_sql = "insert into user values (?, ?, ?, ?)";
                    sql_query.prepare(insert_sql);
                    sql_query.addBindValue(id);
                    sql_query.addBindValue(username);
                    sql_query.addBindValue(password);
                    sql_query.addBindValue(1);
                    QMessageBox::information(NULL,tr("提示"),tr("注册成功"));
                }
            }
            else
            {
                QMessageBox::information(NULL,tr("提示"),tr("请输入密码"));
            }
        }
        else
        {
            QMessageBox::information(NULL,tr("提示"),tr("请输入用户名"));
        }
    }
    else
    {
        QMessageBox::information(NULL,tr("提示"),tr("请输入账号"));
    }
}

void registe::on_back_clicked()
{
    this->close();
}
