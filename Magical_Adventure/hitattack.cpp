#include "hitattack.h"
#include <QKeyEvent>
#include <QMovie>
#include <QGraphicsProxyWidget>

using namespace std ;

HitAttack::HitAttack()
{
    title.sprintf(":/gif/fire.gif");
    movie = new QMovie(title);
}

HitAttack::~HitAttack()
{
    for (int i = 0 ;Fire.length(); i ++) {

        delete Fire[i] ;

    }

}


QGraphicsRectItem *HitAttack::getFire()
{
    if(isDelete){
        isDelete = false ;
        return (*(Fire.begin()));
    }
    else{
        return (*(Fire.end()-1));
    }
}

void HitAttack::update()
{

     for (int i = 0; i<Fire.size();i++)  {
            if(sens[i]){
                Fire[i]->setPos(Fire[i]->x()+15,Fire[i]->y());
                distance[i] = distance[i]+15;
            }
            else{
                Fire[i]->setPos(Fire[i]->x()-15,Fire[i]->y());
                distance[i] = distance[i]-15;
            }
            if(distance[i]==750||distance[i]==-750){
                isDelete = true ;
                emit remove();
                Fire.removeAt(i);
                distance.removeAt(i);
                sens.removeAt(i);
            }
     }
    //(*(Fire.end()-1))->setPos((*(Fire.end()-1))->x()+1,(*(Fire.end()-1))->y());
}

void HitAttack::changePos(int x, int y, bool sensFire)
{
    Fire.push_back(new QGraphicsRectItem());
    sens.push_back(sensFire);
    if(sensFire){
        (*(Fire.end()-1))->setRect(46,-17,170,100);
    }
    else{
        (*(Fire.end()-1))->setRect(0,-17,170,100);
    }
    (*(Fire.end()-1))->setFlag(QGraphicsItem::ItemIsFocusable);
    (*(Fire.end()-1))->setPos(x,y);
    distance.push_back(0);
    gif.push_back(new QLabel());

    (*(gif.end()-1))->setFixedSize(180,170);

    (*(gif.end()-1))->setAttribute(Qt::WA_NoSystemBackground);
     movie->setScaledSize((*(gif.end()-1))->size());
    (*(gif.end()-1))->setMovie(movie);
    (*(gif.end()-1))->movie()->start();

     pMyProxy.push_back(new QGraphicsProxyWidget(*(Fire.end()-1)));
     (*(pMyProxy.end()-1))->setWidget(*(gif.end()-1));
     (*(pMyProxy.end()-1))->setY(-50);
     (*(pMyProxy.end()-1))->setX(30);

    /* backgroud = new QLabel();
     backgroud->setFixedSize(1700,700);
     title.sprintf(":/gif/forest.gif");
     anime = new QMovie(title);
     anime->setScaledSize(backgroud->size());
     backgroud->setMovie(anime);
     backgroud->movie()->start();
     this->addWidget(backgroud);*/
}

void HitAttack::impact(int i)
{
    Fire.removeAt(i);
    distance.removeAt(i);
    sens.removeAt(i);

}


