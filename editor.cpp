#include "editor.h"
#include "ui_editor.h"
#include "author.h"
#include "essay.h"
#include "spending.h"
#include "review.h"
#include <QStringList>

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

    setFixedSize(900, 600);

    columns = new QString[4];
    columns[0] = "编号";
    columns[1] = "姓名";
    columns[2] = "审稿数";
    columns[3] = "email";

    tableChoose();
    operation();
    table();

}

Editor::~Editor()
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

void Editor::tableChoose()
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

    button2->setDisabled(true);

    button1->show();
    button2->show();
    button3->show();
    button4->show();
    button5->show();

    connect(button1, SIGNAL(clicked(bool)), this, SLOT(Page1()));
    connect(button3, SIGNAL(clicked(bool)), this, SLOT(Page3()));
    connect(button4, SIGNAL(clicked(bool)), this, SLOT(Page4()));
    connect(button5, SIGNAL(clicked(bool)), this, SLOT(Page5()));
}

void Editor::operation()
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
    connect(dele, SIGNAL(clicked(bool)), this, SLOT(info2()));
    connect(modi, SIGNAL(clicked(bool)), this, SLOT(info3()));
    connect(sele, SIGNAL(clicked(bool)), this, SLOT(info4()));


}

void Editor::table()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }

    tableView = new QTableView(this);
    model = new QSqlQueryModel(tableView);
    model->setHeaderData(0, Qt::Horizontal, tr("编号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, tr("审稿数"));
    model->setHeaderData(3, Qt::Horizontal, tr("email"));
    tableView->setModel(model);
    tableView->setGeometry(400, 80, 402, 470);
    tableView->show();

    if(database.open()) {
       /* QSqlQuery sql_query;
        QString create_sql = "create table editor ( 编号 varchar(12) primary key, "
                             "姓名 varchar(30), 审稿数 int, email varchar(50) check "
                             "(email like '%@%'))";
          sql_query.prepare(create_sql);

        if(!sql_query.exec())
        {
            qDebug() << "open??Error: Fail to create table." << sql_query.lastError();

        } else {
            qDebug() << "Table created!";
        }
      */

        model->setQuery(QString("select * from editor;"));
        database.close();

    } else {
        qDebug() << "Error: Fail to open database..." << database.lastError();
    }

}


void Editor::Page1()
{
    Author *author = new Author();
    author->show();
    this->close();
}

void Editor::Page3()
{
    Essay *essay = new Essay();
    essay->show();
    this->close();
}

void Editor::Page4()
{
    Spending *spending = new Spending();
    spending->show();
    this->close();
}

void Editor::Page5()
{
    Review *review = new Review();
    review->show();
    this->close();
}

void Editor::info1()
{
    hint = new QLabel(this);
    hint->setText("");
    hint->setFont(QFont(QString::fromLocal8Bit("宋体"), 10));

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

    lab1->setText("编号");
    lab2->setText("姓名");
    lab3->setText("审稿数");
    lab4->setText("email");

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

    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(Confirm1()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}

void Editor::info2()
{
    subWin = new QDialog();

    hint = new QLabel(subWin);
    hint->setText("目标记录筛选条件：");
    hint->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    hint->setGeometry(10, 10, 140, 20);
    hint->show();

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

    lab1->setText("编号");
    lab2->setText("姓名");
    lab3->setText("审稿数");
    lab4->setText("email");

    lab1->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab3->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab4->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    confirm->setText("删除");
    cancel->setText("取消");
    confirm->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    cancel->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    lab1->setGeometry(50, 50, 80, 30);
    lab2->setGeometry(50, 95, 100, 30);
    lab3->setGeometry(50, 140, 100, 30);
    lab4->setGeometry(50, 185, 100, 30);

    line1->setGeometry(120, 50, 200, 30);
    line2->setGeometry(120, 95, 200, 30);
    line3->setGeometry(120, 140, 200, 30);
    line4->setGeometry(120, 185, 200, 30);

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

    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(Confirm2()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));

}

void Editor::info3()
{
    subWin = new QDialog();

    hint = new QLabel(subWin);
    hint->setText("目标记录筛选条件：");
    hint->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    hint->setGeometry(20, 10, 140, 20);
    hint->show();

    hint2 = new QLabel(subWin);
    hint2->setText("修改属性：");
    hint2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    hint2->setGeometry(20, 210, 130, 20);
    hint2->show();

    lab1 = new QLabel(subWin);
    lab2 = new QLabel(subWin);
    lab3 = new QLabel(subWin);
    lab4 = new QLabel(subWin);
    lab5 = new QLabel(subWin);
    lab6 = new QLabel(subWin);
    lab7 = new QLabel(subWin);

    line1 = new QLineEdit(subWin);
    line2 = new QLineEdit(subWin);
    line3 = new QLineEdit(subWin);
    line4 = new QLineEdit(subWin);
    line5 = new QLineEdit(subWin);
    line6 = new QLineEdit(subWin);
    line7 = new QLineEdit(subWin);

    confirm = new QPushButton(subWin);
    cancel = new QPushButton(subWin);

    lab1->setText("编号");
    lab2->setText("姓名");
    lab3->setText("审稿数");
    lab4->setText("email");
    lab5->setText("姓名");
    lab6->setText("审稿数");
    lab7->setText("email");

    lab1->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab3->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab4->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab5->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab6->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab7->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    confirm->setText("修改");
    cancel->setText("取消");
    confirm->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    cancel->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    lab1->setGeometry(50, 40, 100, 30);
    lab2->setGeometry(50, 80, 100, 30);
    lab3->setGeometry(50, 120, 100, 30);
    lab4->setGeometry(50, 160, 100, 30);
    lab5->setGeometry(50, 240, 100, 30);
    lab6->setGeometry(50, 280, 100, 30);
    lab7->setGeometry(50, 320, 100, 30);

    line1->setGeometry(120, 40, 200, 30);
    line2->setGeometry(120, 80, 200, 30);
    line3->setGeometry(120, 120, 200, 30);
    line4->setGeometry(120, 160, 200, 30);
    line5->setGeometry(120, 240, 200, 30);
    line6->setGeometry(120, 280, 200, 30);
    line7->setGeometry(120, 320, 200, 30);

    confirm->setGeometry(60, 370, 80, 30);
    cancel->setGeometry(260, 370, 80, 30);

    lab1->show();
    lab2->show();
    lab3->show();
    lab4->show();
    lab5->show();
    lab6->show();
    lab7->show();
    line1->show();
    line2->show();
    line3->show();
    line4->show();
    line5->show();
    line6->show();
    line7->show();

    confirm->show();
    cancel->show();

    subWin->setFixedSize(400, 420);
    subWin->show();

    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(Confirm3()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel1()));

}

void Editor::info4()
{
    subWin = new QDialog();

    hint = new QLabel(subWin);
    hint->setText("目标记录筛选条件：");
    hint->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 12));
    hint->setGeometry(10, 10, 140, 20);
    hint->show();

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

    lab1->setText("编号");
    lab2->setText("姓名");
    lab3->setText("审稿数");
    lab4->setText("email");

    lab1->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab2->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab3->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    lab4->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    confirm->setText("筛选");
    cancel->setText("取消");
    confirm->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    cancel->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));

    lab1->setGeometry(50, 50, 80, 30);
    lab2->setGeometry(50, 95, 100, 30);
    lab3->setGeometry(50, 140, 100, 30);
    lab4->setGeometry(50, 185, 100, 30);

    line1->setGeometry(120, 50, 200, 30);
    line2->setGeometry(120, 95, 200, 30);
    line3->setGeometry(120, 140, 200, 30);
    line4->setGeometry(120, 185, 200, 30);

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

    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(Confirm4()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));

}


void Editor::Confirm1()
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

    QString s1 = "", s2 = "";
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        if(s[i] != "") {
            if(cnt == 0) {
               s1 += columns[i];
               s2 += "'" + s[i] + "'";
               cnt++;
            } else {
               s1 += "," + columns[i];
               s2 += ",'" + s[i] + "'";
            }
        }
    }

    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }

    if(database.open()) {
        QSqlQuery sql_query;
        QString insert_sql = "insert into editor (" + s1 + ") values (" + s2 +")";

        sql_query.prepare(insert_sql);
        sql_query.exec();

        model->setQuery(QString("select * from editor;"));

        database.close();
    }

    delete []s;

}

void Editor::Confirm2()
{
    QString *s = new QString[4];
    int flag = 0;
    s[0] = line1->text();
    s[1] = line2->text();
    s[2] = line3->text();
    s[3] = line4->text();

    Cancel();

    QString *dele = new QString[4];
    QString where = "";
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(s[i] != "") {
            if(flag == 0) {
                dele[cnt++] = columns[i] + "='" + s[i] + "'";
                flag = 1;
            } else {
               dele[cnt++] = "and " + columns[i] + "='" + s[i] + "'";
            }
        }
    }
    if(cnt != 0) {
        QString delete_sql = "delete from editor where ";
        for(int i = 0; i < cnt; i++) {
            where += dele[i];
        }
        delete_sql += where;

        where = "delete from review where review.审稿人编号 in (select "
                " editor.编号 from editor where " + where + ")";

        QSqlDatabase database;
        if (QSqlDatabase::contains("qt_sql_default_connection"))
        {
            database = QSqlDatabase::database("qt_sql_default_connection");
        }
        else
        {
            database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("MyDataBase.db");
        }

        if(database.open()) {
            QSqlQuery sql_query;
            sql_query.prepare(where);
            sql_query.exec();

            sql_query.prepare(delete_sql);
            sql_query.exec();

            model->setQuery(QString("select * from editor;"));

            database.close();
        }

    }

    delete []s;
    delete []dele;

}

void Editor::Confirm3()
{
    QString *s = new QString[7];
    int flag = 0;
    s[0] = line1->text();
    s[1] = line2->text();
    s[2] = line3->text();
    s[3] = line4->text();
    s[4] = line5->text();
    s[5] = line6->text();
    s[6] = line7->text();

    Cancel1();

    QString *modi = new QString[7];
    int cnt1, cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(s[i] != "") {
            if(flag == 0) {
                modi[cnt++] = columns[i] + "='" + s[i] + "'";
                flag = 1;
            } else {
               modi[cnt++] = "and " + columns[i] + "='" + s[i] + "'";
            }
        }
    }
    cnt1 = cnt;
    flag = 0;
    for(int i = 4; i < 7; i++) {
        if(s[i] != "") {
            if(flag == 0) {
                modi[cnt++] = columns[i - 3] + "='" + s[i] + "'";
                flag = 1;
            } else {
                modi[cnt++] = columns[i - 3] + "='" + s[i] + "',";
            }
        }
    }
    if(cnt1 != 0 && cnt1 != cnt ) {
        QString update_sql = "update editor set ";
        for(int i = cnt - 1; i >= cnt1; i--) {
            update_sql += modi[i];
        }
        update_sql += " where ";
        for(int i = 0; i < cnt1; i++) {
            update_sql +=modi[i];
        }

        QSqlDatabase database;
        if (QSqlDatabase::contains("qt_sql_default_connection"))
        {
            database = QSqlDatabase::database("qt_sql_default_connection");
        }
        else
        {
            database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("MyDataBase.db");
        }

        if(database.open()) {
            QSqlQuery sql_query;
            sql_query.prepare(update_sql);
            sql_query.exec();

            model->setQuery(QString("select * from editor;"));

            database.close();
        }

    }

    delete []s;
    delete []modi;

}

void Editor::Confirm4()
{
    QString *s = new QString[4];
    int flag = 0;
    s[0] = line1->text();
    s[1] = line2->text();
    s[2] = line3->text();
    s[3] = line4->text();

    Cancel();

    QString *sele = new QString[4];
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(s[i] != "") {
            if(flag == 0) {
                sele[cnt++] = columns[i] + "='" + s[i] + "'";
                flag = 1;
            } else {
               sele[cnt++] = "and " + columns[i] + "='" + s[i] + "'";
            }
        }
    }
    if(cnt != 0) {
        QString select_sql = "select * from editor where ";
        for(int i = 0; i < cnt; i++) {
            select_sql += sele[i];
        }

        QSqlDatabase database;
        if (QSqlDatabase::contains("qt_sql_default_connection"))
        {
            database = QSqlDatabase::database("qt_sql_default_connection");
        }
        else
        {
            database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("MyDataBase.db");
        }

        if(database.open()) {
            QSqlQuery sql_query;
            //sql_query.prepare(select_sql);
            //sql_query.exec();

            model->setQuery(QString(select_sql + ";"));

            database.close();
        }

    }

    delete []s;
    delete []sele;

}

void Editor::Cancel()
{
    subWin->close();
    delete hint;
    delete lab1;
    delete lab2;
    delete lab3;
    delete lab4;
    delete line1;
    delete line2;
    delete line3;
    delete line4;
    delete confirm;
    delete cancel;
}

void Editor::Cancel1()
{
    subWin->close();
    delete hint;
    delete hint2;
    delete lab1;
    delete lab2;
    delete lab3;
    delete lab4;
    delete lab5;
    delete lab6;
    delete lab7;
    delete line1;
    delete line2;
    delete line3;
    delete line4;
    delete line5;
    delete line6;
    delete line7;
    delete confirm;
    delete cancel;
}
