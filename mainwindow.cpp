#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userwindow.h"
#include "ui_userwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->u.ui->back,SIGNAL(clicked()),this,SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_me_clicked()
{
    this->hide();
    u.show();
}

void MainWindow::on_change_clicked()
{
    this->close();
}
