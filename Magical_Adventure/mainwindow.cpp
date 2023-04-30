#include "mainwindow.h"
#include <QWidget>
#include <QPalette>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsRectItem>


#define WIDTH       1700
#define LENGTH      700
#define FPMS      100

using namespace std;

MainWindow::MainWindow()
    : QGraphicsScene()
{
   /* backgroud = new QLabel();
    backgroud->setFixedSize(1700,700);
    title.sprintf(":/gif/forest.gif");
    anime = new QMovie(title);
    anime->setScaledSize(backgroud->size());
    backgroud->setMovie(anime);
    backgroud->movie()->start();
    this->addWidget(backgroud);*/
    backgroud = new QLabel();
    text.sprintf("lol");

    backgroud->setText(text);
    backgroud->setGeometry(0,0,70,70);
    backgroud->setFixedSize(100,100);
    this->addWidget(backgroud);

    rec = new Hit_Box(0,0,46,66,true);
    this->addItem(rec);
    rec->setX(60);
    rec->setY(150);

    rec2 = new Hit_Box(0,0,46,66,true);
    this->addItem(rec2);
    rec2->setX(1600);
    rec2->setY(150);

    rec->setVisible(true);
    rec2->setVisible(true);

    rec3 = new Hit_Box(0,0,400,10,false);
    this->addItem(rec3);
    rec3->setPos(rec3->x()+200,rec3->y()+470);

    rec4 = new Hit_Box(0,0,400,10,false);
    this->addItem(rec4);
    rec4->setPos(rec4->x()+1000,rec4->y()+470);

    rec5 = new Hit_Box(0,0,400,10,false);
    this->addItem(rec5);
    rec5->setPos(rec5->x()+600,rec5->y()+200);

    platteforms[0] = rec3 ;
    platteforms[1] = rec4 ;
    platteforms[2] = rec5 ;

    connect(rec,SIGNAL(impact()), this, SLOT(impact()));
    connect(&timer,SIGNAL(timeout()), this, SLOT(remove()));

    connect(rec2,SIGNAL(impact()), this, SLOT(impact()));
    connect(&timer2,SIGNAL(timeout()), this, SLOT(refresh()));
    timer.setTimerType(Qt::PreciseTimer);
    timer2.setTimerType(Qt::PreciseTimer);
    timer.start(1);
    timer2.start(17);


}
//----------------------------------------------------destructor-------------------------------------------------------------
MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//----------------------------------------------------control player 1-------------------------------------------------------------
    if (event->key() == Qt::Key_S){
        rec->pressed(0);
    }
    else if (event->key() == Qt::Key_F){
        rec->pressed(1);
    }
    else if (event->key() == Qt::Key_Space){
        rec->pressed(2);
    }
    else if (event->key() == Qt::Key_D){
        rec->pressed(3);
    }
    else if (event->key() == Qt::Key_G){
        rec->pressed(4);
    }
//----------------------------------------------------control player 2-------------------------------------------------------------
    if (event->key() == Qt::Key_4){
        rec2->pressed(0);
    }
    else if (event->key() == Qt::Key_6){
        rec2->pressed(1);
    }
    else if (event->key() == Qt::Key_Enter){
        rec2->pressed(2);
    }
    else if (event->key() == Qt::Key_5){
        rec2->pressed(3);
    }
    else if(event->key() == Qt::Key_7){

        rec2->setX(1600);
        rec2->setY(60);
    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_S){
        rec->release(0);
    }
    else if (event->key() == Qt::Key_F){
        rec->release(1);
    }
    else if (event->key() == Qt::Key_Space){
        rec->release(2);
    }
    else if (event->key() == Qt::Key_D){
        rec->release(3);
    }
    else if (event->key() == Qt::Key_G){
        rec->release(4);
    }
    if (event->key() == Qt::Key_4){
        rec2->release(0);
    }
    else if (event->key() == Qt::Key_6){
        rec2->release(1);
    }
    else if (event->key() == Qt::Key_Enter){
        rec2->release(2);
    }
    else if (event->key() == Qt::Key_5){
        rec2->release(3);
    }



}

void MainWindow::impact()
{

    for (int i = 0; i<3;i ++) {
        qreal check = platteforms[i]->pos().y();
        qreal check2 = rec->pos().y()+66;
        qreal check_x = rec->pos().x()+26;
        qreal check_x2 = platteforms[i]->pos().x();
        if((check_x >= check_x2 && check_x <=check_x2+400)){
            if(check2>=(check-10) && check2<=check+10){
                rec->check(true, (check2-check));
                break ;
            }
        }
        else{
            rec->check(false,0);
        }
    }

    for (int i = 0; i<3;i ++) {
        qreal check = platteforms[i]->pos().y();
        qreal check2 = rec2->pos().y()+66;
        qreal check_x = rec2->pos().x()+26;
        qreal check_x2 = platteforms[i]->pos().x();
        if((check_x >= check_x2 && check_x <=check_x2+400)){
            if(check2>=(check-10) && check2<=check+10){
                rec2->check(true, (check2-check));
                break ;
            }
        }
        else{
            rec2->check(false,0);
        }
    }


}

void MainWindow::refresh()
{
    rec->doMove();
    rec2->doMove();
    update();

}



void MainWindow::remove()
{
    rec->move();
    rec2->move();
    text = text.sprintf(":%02d",rec->x());
    backgroud->setText(text);
}






