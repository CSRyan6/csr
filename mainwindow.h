#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "userwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    userwindow u;
    Ui::MainWindow *ui;

private slots:
    void on_me_clicked();
    void on_change_clicked();

private:

};

#endif // MAINWINDOW_H
