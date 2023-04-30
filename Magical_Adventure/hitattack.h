#ifndef HITATTACK_H
#define HITATTACK_H


#include <QPaintEvent>
#include <QPainter>
#include <QObject>
#include <QTimer>

#include <QGraphicsRectItem>
#include <QTimer>
#include <QLabel>
using namespace std ;

class HitAttack: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    HitAttack();
    ~HitAttack();
    QGraphicsRectItem* getFire();
    void update();
    void changePos(int x, int y, bool sensFire);
    void impact(int i);


private :
    bool isDelete = false ;
    QList <QGraphicsRectItem*> Fire;
    QList <int> distance;
    QList <bool> sens;
    QGraphicsRectItem*BigFire ;
    QList<QLabel*> gif ;
    QString title ;
    QList<QGraphicsProxyWidget*>pMyProxy ;
    QMovie * movie;

signals :
    void remove();





};

#endif // HITATTACK_H
