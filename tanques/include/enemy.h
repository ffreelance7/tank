#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <game.h>

#include <math.h>
#include <time.h>
#include <vector>
#include <arma.h>

using namespace std;

class enemy
{
   public:
        enemy();

        enemy(float,float);
        int getX();
        int getY();
        void setX(int);
        void setY(int);
        bool colision(int,int,int);

        void atacar(float,float);
        virtual void printImage()=0;
        virtual void mover(float,float,vector<float>)=0;
    protected:
        static int  state_coli;
        int numx;
        bool coli;
        int numy;
        int weigh;
        int heigh;
        int speed;
        int state;
        ALLEGRO_BITMAP *ene_image;
        float score;
        float x;
        float y;
        float vida;
        //vector <arma*>bala_enemy;
};

class tank_basic:public enemy{

    public:

        tank_basic(float x,float y);
       // virtual void atacar(float,float);
        virtual void printImage();
        virtual void mover(float,float,vector<float>);
    private:
        vector<float>p_mov;
};
class tank_hard:public enemy
{

    public:
        tank_hard(float x,float y);
        //virtual void atacar(float,float);
        virtual void printImage();
        virtual void mover(float,float,vector<float>);
    private:
        vector<float>ph_mov;

};
#endif // ENEMY_H

