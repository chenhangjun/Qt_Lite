#ifndef ESSAY_H
#define ESSAY_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTableView>
#include <QLineEdit>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <qdebug.h>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class Essay;
}

class Essay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Essay(QWidget *parent = 0);
    ~Essay();
private Q_SLOTS:
    void Page1();
    void Page2();
    //void Page3();
    void Page4();
    void Page5();

    void info1();
    void info2();
    void info3();
    void info4();

    void Confirm1();
    void Confirm2();
    void Confirm3();
    void Confirm4();
    void Cancel();
    void Cancel1();

private:
    Ui::Essay *ui;

    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;

    QPushButton *add;
    QPushButton *dele;
    QPushButton *modi;
    QPushButton *sele;

    QPushButton *confirm;
    QPushButton *cancel;

    QLabel *lab1;
    QLabel *lab2;
    QLabel *lab3;
    QLabel *lab4;
    QLabel *lab5;
    QLabel *lab6;
    QLabel *lab7;
    QLabel *lab8;
    QLabel *lab9;
    QLabel *hint;
    QLabel *hint2;
    QLabel *result;

    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;
    QLineEdit *line5;
    QLineEdit *line6;
    QLineEdit *line7;
    QLineEdit *line8;
    QLineEdit *line9;

    QTableView *tableView;
    QSqlQueryModel *model;

    QDialog *subWin;

    QString *columns;

    int cnt_all;

    void tableChoose();
    void operation();
    void table();

};

#endif // ESSAY_H
