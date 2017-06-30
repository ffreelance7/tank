#ifndef CHARACTER_H
#include <iostream>
#include <vector>
#include <list>
#include <arma.h>
#include <game.h>
#include <math.h>

#define CHARACTER_H
using namespace std;

class character{

    public:
        float getX();
        float getY();
        void setX(float);
        void setY(float);
        int getvida();
        int getscore();
        void setscore(int);
        void setvida(int);
        void atacar(float,float);
        void printImage(float,float,float,float,vector<float>);
        bool coliision(float,float,float);
        static character *getinstance(int,int);
        int speed;
        bool state;
    private:
        static character* instance;
        character(int,int);
        int weigh;
        int heigh;
        ALLEGRO_BITMAP *image;
        ALLEGRO_BITMAP *image_up;
        float score;
        float x;
        float y;
        float vida;
        vector <arma*> bala;
       // vector <arma*>::iterator it1;
};

#endif // CHARACTER_H
