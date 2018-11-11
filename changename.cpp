#include "changename.h"
#include "ui_changename.h"

Changename::Changename(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Changename)
{
    ui->setupUi(this);
}

Changename::~Changename()
{
    delete ui;
}

void Changename::on_back_clicked()
{
    this->close();
}
