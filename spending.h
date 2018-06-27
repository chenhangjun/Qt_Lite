#ifndef SPENDING_H
#define SPENDING_H

#include <QMainWindow>

namespace Ui {
class Spending;
}

class Spending : public QMainWindow
{
    Q_OBJECT

public:
    explicit Spending(QWidget *parent = 0);
    ~Spending();

private:
    Ui::Spending *ui;
};

#endif // SPENDING_H
