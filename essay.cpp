#include "essay.h"
#include "ui_essay.h"

Essay::Essay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Essay)
{
    ui->setupUi(this);
}

Essay::~Essay()
{
    delete ui;
}
