#ifndef ESSAY_H
#define ESSAY_H

#include <QMainWindow>

namespace Ui {
class Essay;
}

class Essay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Essay(QWidget *parent = 0);
    ~Essay();

private:
    Ui::Essay *ui;
};

#endif // ESSAY_H
