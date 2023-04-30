#include "gif_perso.h"

gif_perso::gif_perso()
{

}

gif_perso::~gif_perso()
{

}

QLabel * gif_perso::go_animation()
{
    QLabel * label = new QLabel();
    movie = new QMovie(":/gif/sprite.gif");
    label->setMovie(movie);
    movie->start();
    return label ;

}

void gif_perso::stop_animation()
{

}
