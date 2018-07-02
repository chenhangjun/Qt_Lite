#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = 0);
    ~Message();
    void set_Text(QString);

private Q_SLOTS:
    void Close();

private:
    Ui::Message *ui;
    QPushButton *ok;
    QLabel *message;

};

#endif // MESSAGE_H
