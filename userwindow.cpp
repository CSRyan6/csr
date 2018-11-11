#include "userwindow.h"
#include "ui_userwindow.h"
#include "logininterface.h"
#include "ui_changename.h"
#include "ui_changepsd.h"

userwindow::userwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwindow)
{
    ui->setupUi(this);
//    ui->username->setText();
//    connect(ui->change，SIGNAL(clicked()),this,SIGNAL( show() ));
    connect(this->cn.ui->back,SIGNAL(clicked()),this,SLOT(show()));
    connect(this->cp.ui->back,SIGNAL(clicked()),this,SLOT(show()));
}

userwindow::~userwindow()
{
    delete ui;
}

void userwindow::on_back_clicked()
{
    this->close();
}

void userwindow::on_changename_clicked()
{
    this->hide();
    cn.show();
}

void userwindow::on_changepsw_clicked()
{
    this->hide();
    cp.show();
}
