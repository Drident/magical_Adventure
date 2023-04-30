#ifndef GIFPERSO_H
#define GIFPERSO_H
#include <QLabel>
#include <QMovie>

using namespace std ;
class GifPerso
{
public:
    GifPerso();
    ~GifPerso();
    void check(int x1, int y1, int battle);
    void go_animation();
    void stop_animation();
    void init();
    QLabel* get_label();

private :
    int x ;
    int y ;
    int move ;
    bool sens ;
    QLabel * gif ;
    QMovie * movie;
    vector<QString> FileNames;
    vector<QMovie*> allMovie;
    vector<QPixmap*> FilePicture ;
};

#endif // GIFPERSO_H
