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
//    id = ui->id->text();
//    username = ui->username->text();
//    password = ui->password->text();
//    while(sql_query.next())
//    {
//        qDebug() << "registe";
//    }
}

void registe::on_back_clicked()
{
    this->close();
}
