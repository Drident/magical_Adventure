#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QList>
#include <QLabel>
#include <QGraphicsScene>
#include "hit_box.h"

class MainWindow : public QGraphicsScene
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);



private:
    QTimer timer;
    QTimer timer2;
    QString text;
    QLabel * backgroud ;
    QMovie * anime ;
    QString title ;
    Hit_Box * rec ;
    Hit_Box * rec2 ;
    Hit_Box * rec3 ;
    Hit_Box * rec4 ;
    Hit_Box * rec5 ;
    Hit_Box * platteforms [10];


public slots :
    void impact();
    void refresh();
    void remove();


};
#endif // MAINWINDOW_H
