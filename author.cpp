#include "author.h"
#include "ui_author.h"
#include "editor.h"
#include "essay.h"
#include "spending.h"
#include "review.h"
#include <QStringList>

Author::Author(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Author)
{
    ui->setupUi(this);

    tableView = new QTableView(this);
    model = new QSqlQueryModel(tableView);

    setFixedSize(900, 600);

    tableChoose();
    operation();
    table();

}

Author::~Author()
{
    delete button1;
    delete button2;
    delete button3;
    delete button4;
    delete button5;

    delete add;
    delete dele;
    delete modi;
    delete sele;

    delete tableView;
    delete model;

   // database.close();

    delete ui;
}

void Author::tableChoose()
{
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

    button1->setGeometry(75, 20, 150, 40);
    button2->setGeometry(225, 20, 150, 40);
    button3->setGeometry(375, 20, 150, 40);
    button4->setGeometry(525, 20, 150, 40);
    button5->setGeometry(675, 20, 150, 40);

    button1->setDisabled(true);

    button1->show();
    button2->show();
    button3->show();
    button4->show();
    button5->show();

    connect(button2, SIGNAL(clicked(bool)), this, SLOT(Page2()));
    connect(button3, SIGNAL(clicked(bool)), this, SLOT(Page3()));
    connect(button4, SIGNAL(clicked(bool)), this, SLOT(Page4()));
    connect(button5, SIGNAL(clicked(bool)), this, SLOT(Page5()));
}

void Author::operation()
{
    add = new QPushButton(this);
    dele = new QPushButton(this);
    modi = new QPushButton(this);
    sele = new QPushButton(this);

    add->setText("添加记录");
    dele->setText("删除记录");
    modi->setText("修改记录");
    sele->setText("筛选记录");

    add->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    dele->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    modi->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    sele->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));

    add->setGeometry(100, 100, 130, 50);
    dele->setGeometry(100, 200, 130, 50);
    modi->setGeometry(100, 300, 130, 50);
    sele->setGeometry(100, 400, 130, 50);

    add->show();
    dele->show();
    modi->show();
    sele->show();

    connect(add, SIGNAL(clicked(bool)), this, SLOT(info1()));

}

void Author::table()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
        database.setUserName("Chen");
        database.setPassword("1030416518");
    }

    if(database.open()) {
        QString create_sql = "create table author ( 作者编号 varchar(12) primary key, "
                             "姓名 varchar(30), 投稿数 int, email varchar(50) check "
                             "(email like '%@%'))";
        sql_query.prepare(create_sql);
        if(sql_query.exec())
        {
            qDebug() << "Error: Fail to create table." << sql_query.lastError();
            sql_query.exec("insert into author values( "
                           " 'H023', '张三', 40, '123@qq.com' )");
        } else {
            qDebug() << "Table created!";
        }
    } else {
        qDebug() << "Error: Fail to connect database." << database.lastError();
    }


    model->setQuery(QString("select * from author;"));
    model->setHeaderData(0, Qt::Horizontal, tr("作者编号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("投稿数"));
    model->setHeaderData(3, Qt::Horizontal, tr("email"));
    tableView->setModel(model);
    tableView->setGeometry(400, 80, 402, 470);
    tableView->show();

}


void Author::Page2()
{
    Editor *editor = new Editor();
    editor->show();
    this->close();
}

void Author::Page3()
{
    Essay *essay = new Essay();
    essay->show();
    this->close();
}

void Author::Page4()
{
    Spending *spending = new Spending();
    spending->show();
    this->close();
}

void Author::Page5()
{
    Review *review = new Review();
    review->show();
    this->close();
}

void Author::info1()
{
    subWin = new QDialog();
    lab1 = new QLabel(subWin);
    lab2 = new QLabel(subWin);
    lab3 = new QLabel(subWin);
    lab4 = new QLabel(subWin);

    line1 = new QLineEdit(subWin);
    line2 = new QLineEdit(subWin);
    line3 = new QLineEdit(subWin);
    line4 = new QLineEdit(subWin);

    confirm = new QPushButton(subWin);
    cancel = new QPushButton(subWin);

    lab1->setText("作者编号");
    lab2->setText("姓名");
    lab3->setText("投稿数");
    lab4->setText("emal");

    lab1->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab3->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab4->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    confirm->setText("插入");
    cancel->setText("取消");
    confirm->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    cancel->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    lab1->setGeometry(50, 20, 80, 30);
    lab2->setGeometry(50, 70, 100, 30);
    lab3->setGeometry(50, 120, 100, 30);
    lab4->setGeometry(50, 170, 100, 30);

    line1->setGeometry(120, 20, 200, 30);
    line2->setGeometry(120, 70, 200, 30);
    line3->setGeometry(120, 120, 200, 30);
    line4->setGeometry(120, 170, 200, 30);

    confirm->setGeometry(60, 230, 80, 30);
    cancel->setGeometry(260, 230, 80, 30);

    lab1->show();
    lab2->show();
    lab3->show();
    lab4->show();
    line1->show();
    line2->show();
    line3->show();
    line4->show();

    confirm->show();
    cancel->show();

    subWin->setFixedSize(400, 300);
    subWin->show();

    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(Confirm()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}


void Author::Confirm()
{

    QString *s = new QString[4];
    s[0] = line1->text();
    s[1] = line2->text();
    s[2] = line3->text();
    s[3] = line4->text();
/*
    QStringList list;
    list << line1->text() << line2->text() << line3->text() << line4->text();
*/
    Cancel();

    sql_query.exec("insert into author values( "
                   " s[0], s[1], s[2].toInt(), s[3] )");

    model->setQuery(QString("select * from author;"));
    tableView->setModel(model);


}

void Author::Cancel()
{
    subWin->close();
    delete lab1;
    delete lab2;
    delete lab3;
    delete lab4;
    delete line1;
    delete line2;
    delete line3;
    delete line4;
}
