#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "message.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(400, 200);
    this->setWindowTitle("Login");
    username = new QLabel(this);
    username->setText("Uername:");
    username->setGeometry(50, 30, 80, 20);
    username->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    username->show();

    password = new QLabel(this);
    password->setText("Password:");
    password->setGeometry(50, 80, 80, 20);
    password->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    password->show();

    name = new QLineEdit(this);
    name->setGeometry(135, 30, 200, 20);
    pwd = new QLineEdit(this);
    pwd->setGeometry(135, 80, 200, 20);
    pwd->setEchoMode(QLineEdit::Password);
    name->show();
    pwd->show();

    login = new QPushButton(this);
    login->setText("Login");
    login->setGeometry(100, 135, 80, 30);
    login->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    login->show();
    connect(login, SIGNAL(clicked(bool)), this, SLOT(Enter()));

    cancle= new QPushButton(this);
    cancle->setText("Cancle");
    cancle->setGeometry(240, 135, 80, 30);
    cancle->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    cancle->show();
    connect(cancle, SIGNAL(clicked(bool)), this, SLOT(Exit()));

}

Login::~Login()
{
    delete ui;
}

//检查用户名和姓名
bool Login::Check()
{
    QString Name = name->text();
    QString Pwd = pwd->text();
    if(Name == "admin" && Pwd == "admin") {
        return true;
    } else {
        return false;
    }

}


//登录
void Login::Enter()
{
    if(Check()) {   //用户名和密码均正确
        this->close();
        MainWindow *m = new MainWindow();
        m->show();
    } else {    //用户名或密码错误
        Message *message = new Message();
        message->show();
    }
}

//退出
void Login::Exit()
{
    this->close();
}

