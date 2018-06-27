#include "review.h"
#include "ui_review.h"

Review::Review(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Review)
{
    ui->setupUi(this);
}

Review::~Review()
{
    delete ui;
}
