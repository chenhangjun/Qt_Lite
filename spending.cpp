#include "spending.h"
#include "ui_spending.h"

Spending::Spending(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Spending)
{
    ui->setupUi(this);
}

Spending::~Spending()
{
    delete ui;
}
