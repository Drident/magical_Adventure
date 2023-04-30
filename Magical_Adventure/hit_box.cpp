#include "hit_box.h"
#include <QKeyEvent>
#include <QMovie>
#include <QGraphicsProxyWidget>
#include <QDebug>
#define speedX 10

using namespace std ;

Hit_Box::Hit_Box()
{
    jump = false ;
    up = -20;
    lock = false ;
    sens = true ;
    prioR = false ;
    prioL = false ;
    collision = false ;
}

Hit_Box::Hit_Box(int pt_x, int px_y, int large, int h, bool fix)
{
    this->setRect(pt_x,px_y,large,h);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    width = large ;
    heigth = h ;
    jump = false ;
    up = -20;
    lock = false ;
    sens = true ;
    prioR = false ;
    prioL = false ;
    collision = false ;
    fixed = fix ;
    vx = 1;
    vy = 0;

    pMyProxy = new QGraphicsProxyWidget(this);
    if(fix){
        this->setBrush(Qt::red);
    }
    else{
        this->setBrush(Qt::blue);
    }



}

Hit_Box::~Hit_Box()
{

}

//--------------------------------------------------------- Key Event------------------------------------------------------------------------

//--------------------------------------------------------- Key Pressed ---------------------------------------------------------------------
void Hit_Box::pressed(int touche)
{
    // go to the left
    if (touche == 0){
        if(!lock){
            vx = -speedX;
        }
        else if(vx==0){
            vx = -speedX;
        }   
        sens = false ;
        prioL = true ;
    }

    // go to the rigth
    else if (touche == 1){
        if(!lock){
            vx = speedX;
        }
        else if(vx==0){
            vx = speedX;
        }
        sens = false ;
        prioR = true ;
    }

    // jump
    else if (touche == 2){
        jump = true ;
        if(two_jump<2 && !stop_jump){
            up = -20 ;
        }
        stop_jump = true ;
        move();
    }

    // down fast
    else if(touche == 3){
        boost = 10 ;
    }

    //attack touch
    else if(touche == 4){

    }
}

//--------------------------------------------------------- Key Pressed ---------------------------------------------------------------------
void Hit_Box::release(int touche)
{
    if (touche == 0){
        if((y()+heigth)>= SIZE_Y && vx!=speedX && prioR == false){
            vx = 0;
        }
        prioL = false ;
        sens = true ;
    }
    else if (touche == 1){
        if((y()+heigth)>=SIZE_Y && vx!=-speedX && prioL == false){
            vx = 0;
        }
        prioR = false ;
        sens = true ;

    }
    else if(touche == 2){
        if(stop_jump && two_jump<2){
            two_jump++ ;
            stop_jump = false ;
        }
    }
    else if(touche == 3){
        boost = 0 ;
    }
    else if(touche == 4){
    }
}

void Hit_Box::doMove()
{
    int oldX = x();
   //vx = 10;
    /*if(x()<=-80){
        setPos(x()+SIZE_X+vx,y()+vy);
    }
    else if(x()>= SIZE_X){
        setPos(x()-SIZE_X+vx,y()+vy);
    }
    else{
       this->setX(x()+vx);
       this->setY(y()+vy);
    }*/
    setPos(x()+vx,y()+vy);

    if(jump && two_jump<3){
         if(up<=20){
             up++;
         }
    }
}


//--------------------------------------------------------- collision ------------------------------------------------------------------------
void Hit_Box::check(bool coll, int diff)
{
    collision = coll ;
    if(collision ){
        vy = 0 ;
        two_jump = 0 ;
        if(up>0){
            up = -20 ;
            jump = false ;
        }
        setPos(x(), y()-diff);
    }

}


//--------------------------------------------------------- Move The Body------------------------------------------------------------------------
void Hit_Box::move()
{
    emit impact();
    if(fixed){
//--------------------------------------------------------- Jump part------------------------------------------------------------------------

        if(jump && two_jump<3){
             if(up<=20){
                vy = up;
                //up++;
                if(up ==20){
                    up = -20;
                    jump = false ;
                    lock = false;
                    if(two_jump == 2){
                        two_jump++;
                    }
                }
            }

        }
//--------------------------------------------------------- gravity part------------------------------------------------------------------------

        else{
            if((y()+heigth)<SIZE_Y && !collision){
                vy = 10 + boost;
            }
            else if((y()+heigth)>= SIZE_Y && vy!=0){
                two_jump = 0 ;
                vy = 0;
            }
            if((sens && vy ==0)|| boost>0){
                vx = 0;
            }
            if(prioL && !prioR){
                vx = -speedX;
            }
            else if(prioR && !prioL){
                vx = speedX;
            }
        }

//-------------------------------------------------------moving part-----------------------------------------------------------------------------------
}
}

