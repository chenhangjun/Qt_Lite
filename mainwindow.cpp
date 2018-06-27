#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "author.h"
#include "editor.h"
#include "essay.h"
#include "spending.h"
#include "review.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button1 = new QPushButton(this);
    button2 = new QPushButton(this);
    button3 = new QPushButton(this);
    button4 = new QPushButton(this);
    button5 = new QPushButton(this);

    button1->setText("作者信息");
    button2->setText("审阅人信息");
    button3->setText("稿件基本信息");
    button4->setText("稿件费用信息");
    button5->setText("审阅记录");

    button1->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    button2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    button3->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    button4->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    button5->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));

    button1->setGeometry(375, 135, 150, 50);
    button2->setGeometry(375, 205, 150, 50);
    button3->setGeometry(375, 275, 150, 50);
    button4->setGeometry(375, 345, 150, 50);
    button5->setGeometry(375, 415, 150, 50);

    button1->show();
    button2->show();
    button3->show();
    button4->show();
    button5->show();

    setFixedSize(900, 600);

    connect(button1, SIGNAL(clicked(bool)), this, SLOT(Page1()));
    connect(button2, SIGNAL(clicked(bool)), this, SLOT(Page2()));
    connect(button3, SIGNAL(clicked(bool)), this, SLOT(Page3()));
    connect(button4, SIGNAL(clicked(bool)), this, SLOT(Page4()));
    connect(button5, SIGNAL(clicked(bool)), this, SLOT(Page5()));

}

MainWindow::~MainWindow()
{
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete button5;

    delete ui;
}

void MainWindow::Page1()
{
    Author *author = new Author();
    author->show();
    this->close();
}

void MainWindow::Page2()
{
    Editor *editor = new Editor();
    editor->show();
    this->close();
}

void MainWindow::Page3()
{
    Essay *essay = new Essay();
    essay->show();
    this->close();
}

void MainWindow::Page4()
{
    Spending *spending = new Spending();
    spending->show();
    this->close();
}

void MainWindow::Page5()
{
    Review *review = new Review();
    review->show();
    this->close();
}
