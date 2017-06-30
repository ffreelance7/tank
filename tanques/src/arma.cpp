#include "arma.h"

arma::arma(float x,float y){
    this->x=x;
    this->y=y;
    this->speed=9;
    image=al_load_bitmap("index.png");
    weigh=al_get_bitmap_width(image);
    //ex=al_load_bitmap("ex.gif");
    heigh=al_get_bitmap_height(image);
}
arma::~arma(){
    cout<<"delete"<<endl;
}
int arma::getX(){
    return this->x;
}
int arma::getY(){
    return this->y;
}
void arma::setX(int x){
    this->x=x;
}
void arma::setY(int y){
    this->y=y;
}
bool arma::collision(float x1,float y1,float weigh){

    float left1,right1,top1,bottom1;

    left1=this->x;
    right1=this->x+this->weigh;
    top1=this->y;
    bottom1=this->y+this->heigh;


    float left,right,top,bottom;

    left=x1;
    right=x1+weigh;
    top=y1;
    bottom=y1+weigh;

    if(right1>=left && left1<=right && top1<=bottom && bottom1>=top){
        return true;
    }else{
        return false;
    }
}
bool arma::printImage(vector<float>point_array){

    bool colison=false,state_bool=false;

    for(int i=0;i<point_array.size()-2;i+=2){
                colison=collision(point_array[i],point_array[i+1],80);
                if(colison==true){
                    state_bool=true;
                    break;
                }
            }
    if(state_bool==true){
        //state_bool=false;
        //cout<<"choco"<<endl;
        //this->~arma();

        return true;


    }else{
        al_draw_bitmap(image,this->x,this->y,0);
        //cout<<"no choco"<<endl;
        return false;
    }

}
