#ifndef AUTHOR_H
#define AUTHOR_H

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
class Author;
}

class Author : public QMainWindow
{
    Q_OBJECT

public:
    explicit Author(QWidget *parent = 0);
    ~Author();

private Q_SLOTS:
    //void Page1();
    void Page2();
    void Page3();
    void Page4();
    void Page5();

    void info1();

    void Confirm();
    void Cancel();

private:
    Ui::Author *ui;

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

    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;

    QSqlDatabase database;
    QSqlQuery sql_query;

    QTableView *tableView;
    QSqlQueryModel *model;

    QDialog *subWin;

    void tableChoose();
    void operation();
    void table();

};

#endif // AUTHOR_H
