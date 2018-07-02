#include "message.h"
#include "ui_message.h"

Message::Message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);
    message = new QLabel(this);
    message->setGeometry(75, 20, 200, 70);
    message->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 13));
    message->show();

    ok = new QPushButton(this);
    ok->setText("OK");
    ok->setGeometry(120, 100, 60, 30);
    ok->setFont(QFont(QString::fromLocal8Bit("微软雅黑"), 10));
    ok->show();
    connect(ok, SIGNAL(clicked(bool)), this, SLOT(Close()));

    setFixedSize(300, 150);
}

Message::~Message()
{
    delete ui;
}

void Message::Close()
{
    this->close();
}

void Message::set_Text(QString ss) {
    message->setText(ss);
}
