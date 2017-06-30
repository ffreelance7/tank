#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <vector>
#include <game.h>
#include <enemy.h>
using namespace std;

class arma
{
     public:
        arma(float,float);
        ~arma();
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        bool printImage(vector<float>);
        bool collision(float,float,float);
        int speed;
        int x1;
        int y1;
    private:
        ALLEGRO_BITMAP * image;
//        ALLEGRO_ANIMATION * ex;
        int x;
        int y;
        int weigh;
        int heigh;
};

#endif // ARMA_H
