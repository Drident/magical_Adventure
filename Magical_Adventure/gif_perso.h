#ifndef GIF_PERSO_H
#define GIF_PERSO_H
#include <QPaintEvent>
#include <QPainter>
#include <QObject>
#include <QTimer>

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMovie>
#include "vector"
#include <QLabel>
using namespace  std ;

class gif_perso: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:
    gif_perso();
    ~gif_perso();
    QLabel * go_animation();
    void stop_animation();

private :
    QMovie* movie ;
    QString test ;
    vector<QString> FileNames;
    vector<QPixmap*> img;
};

#endif // GIF_PERSO_H
