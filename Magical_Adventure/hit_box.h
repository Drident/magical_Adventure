#ifndef HIT_BOX_H
#define HIT_BOX_H

#include <QPaintEvent>
#include <QPainter>
#include <QObject>
#include <QTimer>

#include <QGraphicsRectItem>
#include <QTimer>
#include <QLabel>
#define SIZE_Y 695
#define SIZE_X 1700

using namespace std ;

class Hit_Box: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    Hit_Box();                                                  //constructor
    ~Hit_Box();                                                 //destructor
    Hit_Box(int pt_x,int px_y,int large, int h, bool fix);      //constructor with options
    void check(bool coll,int diff);                             //if collision detected --> set the y speed to 0                                    //


private:
    int vx ;
    int vy ;
    int width ;
    int heigth ;
    int up ;
    int two_jump = 0 ;
    int boost = 0 ;

    bool collision;
    bool jump;
    bool lock;
    bool sens;
    bool prioR;
    bool prioL;
    bool fixed ;
    bool stop_jump = false ;


    QGraphicsProxyWidget *pMyProxy ;



public slots :
    void move();
    void pressed(int touche);
    void release(int touche);
    void doMove();


signals :
    void impact();





};

#endif // HIT_BOX_H
