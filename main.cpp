#include "login.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


    /* delete
     * author->essay;  ! !
     * author->essay->spending;  ! !
     * author->essay->review;   ! ???
     * essay->spending;   !  !
     * essay->review;   !  !
     * editor->review;  !  !
     * */
}
