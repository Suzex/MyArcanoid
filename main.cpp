#include "widget.h"
#include <QApplication>
#include <QTimer>
#include <QObject>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget * w=new Widget;
    QTimer * timer=new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),w,SLOT(Update()));
    QObject::connect(w,SIGNAL(win1(QString)),w,SLOT(win(QString)));
    QObject::connect(w,SIGNAL(game_over1(QString)),w,SLOT(game_over(QString)));
    timer->start(1);
    w->show();
    return a.exec();
}
