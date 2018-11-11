#include "changepsd.h"
#include "ui_changepsd.h"

Changepsd::Changepsd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Changepsd)
{
    ui->setupUi(this);
}

Changepsd::~Changepsd()
{
    delete ui;
}

void Changepsd::on_back_clicked()
{
    this->close();
}
