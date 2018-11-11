#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <changename.h>
#include <changepsd.h>

namespace Ui {
class userwindow;
}

class userwindow : public QWidget
{
    Q_OBJECT

public:
    explicit userwindow(QWidget *parent = 0);
    ~userwindow();
    Ui::userwindow *ui;
    Changename cn;
    Changepsd cp;

private slots:
    void on_back_clicked();

    void on_changename_clicked();

    void on_changepsw_clicked();

private:

};

#endif // USERWINDOW_H
