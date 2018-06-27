#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private Q_SLOTS:
    void Enter();
    void Exit();

private:
    Ui::Login *ui;
    QLabel *username;
    QLabel *password;
    QLineEdit *name;
    QLineEdit *pwd;
    QPushButton *login;
    QPushButton *cancle;

    bool Check();
};

#endif // LOGIN_H
