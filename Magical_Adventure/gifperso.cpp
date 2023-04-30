#include "gifperso.h"
#include "vector"
GifPerso::GifPerso()
{
    x = 0 ;
    y = 0 ;
    move = 0 ;
    sens = false ; // (false <-) ---------- (true ->)
    FileNames.push_back(":/gif/sprite-unscreen.gif");
    FileNames.push_back(":/gif/sprite-2-unscreen.gif");
    FileNames.push_back(":/gif/sprite-run-unscreen.gif");
    FileNames.push_back(":/gif/sprite-run2-unscreen.gif");
    FilePicture.push_back(new QPixmap(":/gif/air.png"));
    FilePicture.push_back(new QPixmap(":/gif/air2.png"));
    FilePicture.push_back(new QPixmap(":/gif/jump.png"));
    FilePicture.push_back(new QPixmap(":/gif/jump2.png"));

    gif = new QLabel();
    init();
}

GifPerso::~GifPerso()
{

}

void GifPerso::check(int x1, int y1, int battle)
{
    if(x != x1 || y!=y1 || move !=battle){
        if(x1==0 && x<0){
            sens = false;
        }
        else if(x!=0){
            sens = true ;
        }
        x = x1 ;
        y = y1 ;
        move = battle ;
        stop_animation();
    }

}

void GifPerso::go_animation()
{
//---------jump picture-------------------

    if(y<0){
        gif->setFixedSize(70,70);
        if((x==0 && !sens)||x<0){
            gif->setPixmap(*FilePicture[3]);
        }
        else{
            gif->setPixmap(*FilePicture[2]);
        }
    }

//---------air picture-------------------

    else if(y>0){
        gif->setFixedSize(70,70);
        if((x==0 && !sens)||x<0){
            gif->setPixmap(*FilePicture[1]);
        }
        else{
            gif->setPixmap(*FilePicture[0]);
        }
    }

//---------run gif-------------------

    else if(x!=0 && y==0){
        gif->setFixedSize(70,70);
        if(x<0){
            gif->setMovie(allMovie[3]);
        }
        else{
            gif->setMovie(allMovie[2]);
        }
        gif->movie()->start();
    }
//---------stay gif-------------------
     else if(x==0 && y==0){
            gif->setFixedSize(50,66);
            if(sens){
                gif->setMovie(allMovie[0]);
            }
            else{
                gif->setMovie(allMovie[1]);
            }
            gif->movie()->start();
     }

    gif->setAttribute(Qt::WA_NoSystemBackground);
}

void GifPerso::stop_animation()
{
    for(int i = 0; i<4 ; i++){
        allMovie[i]->stop();
    }
    gif->repaint();
    go_animation();

}

void GifPerso::init()
{
    for(int i=0 ; i<4;i++){
        movie = new QMovie(FileNames[i]);
        allMovie.push_back(movie);
    }

}

QLabel *GifPerso::get_label()
{
    return gif ;
}
