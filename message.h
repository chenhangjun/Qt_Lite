#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = 0);
    ~Message();

private Q_SLOTS:
    void Close();

private:
    Ui::Message *ui;
    QPushButton *ok;
};

#endif // MESSAGE_H
