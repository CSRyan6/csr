#ifndef CHANGEPSD_H
#define CHANGEPSD_H

#include <QWidget>

namespace Ui {
class Changepsd;
}

class Changepsd : public QWidget
{
    Q_OBJECT

public:
    explicit Changepsd(QWidget *parent = 0);
    ~Changepsd();
    Ui::Changepsd *ui;

private slots:
    void on_back_clicked();

private:

};

#endif // CHANGEPSD_H
