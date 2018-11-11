#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QWidget>

namespace Ui {
class Changename;
}

class Changename : public QWidget
{
    Q_OBJECT

public:
    explicit Changename(QWidget *parent = 0);
    ~Changename();
    Ui::Changename *ui;

private slots:
    void on_back_clicked();

private:

};

#endif // CHANGENAME_H
