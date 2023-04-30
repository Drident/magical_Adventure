#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = new MainWindow();
    QGraphicsView * v = new QGraphicsView(w);
    v->setGeometry(150,150,1700,700);
    w->setSceneRect(0,0,1690,690);
    v->setFixedSize(1700,700);
    v->show();
    return a.exec();
}
