#include "enemy.h"


enemy::enemy()
{
    coli=false;

}
enemy::enemy(float x,float y)
{

}
bool enemy::colision(int x1,int y1,int weight){

    float left1,right1,top1,bottom1;

    left1=this->x;
    right1=this->x+this->weigh;
    top1=this->y;
    bottom1=this->y+this->heigh;
    float left,right,top,bottom;
    left=x1;
    right=x1+weight;
    top=y1;
    bottom=y1+weight;

    if((right1>=left && left1<=right) && (top1<=bottom && bottom1>=top)){
        return true;
    }else{
        return false;
    }
}
void enemy::atacar(float xd,float yd){

    arma *bala=new arma(this->x,this->y);
    bala->x1=xd;
    bala->y1=yd;
//    bala_enemy.push_back(bala);
    state=true;
}
int enemy::getX(){
    return this->x;
}
int enemy::getY(){
    return this->y;
}
void enemy::setX(int x){
    this->x=x;
}
void enemy::setY(int y){
    this->y=y;
}
tank_basic::tank_basic(float x,float y){

    this->x=x;
    this->y=y;
    speed=3;
    vida=100;
    score=0;
    state=false;
    ene_image=al_load_bitmap("tank22.png");
    heigh=al_get_bitmap_height(ene_image);
    weigh=al_get_bitmap_width(ene_image);

}
tank_hard::tank_hard(float x,float y){

    this->x=x;
    this->y=y;
    speed=3;
    vida=100;
    score=0;
    state=false;
    ene_image=al_load_bitmap("tank33.png");
    heigh=al_get_bitmap_height(ene_image);
    weigh=al_get_bitmap_width(ene_image);

}
//enemy::state_coli=0;
int enemy::state_coli=0;
void tank_basic::mover(float n_x,float n_y,vector<float>cc){

    //state_coli=0;
    if(p_mov.empty()){
        this->numx=n_x;
        this->numy=n_y;
        p_mov.push_back(numx);
        p_mov.push_back(numy);
        //state_coli=0;
    }else{
        if(this->x>=numx && this->y>=numy){
            p_mov.pop_back();
            p_mov.pop_back();

        }else{
            if(state_coli==1){
                p_mov.pop_back();
                p_mov.pop_back();
     //
            }else{
                /*for(int i=0;i<cc.size();i++){
                    coli=colision(cc[i],cc[i+1],70);
                    if(coli==true){
                        state_coli+=1;
                        break;
                        }
                }*/
                setX(this->x+cos(atan2(numy-this->y,numx-this->x))*3);
                setY(this->y+sin(atan2(numy-this->y,numx-this->x))*3);
            }
        }
    }
    /*if(state_coli==0){
         for(int i=0;i<cc.size();i++){
            coli=colision(cc[i],cc[i+1],70);
            if(coli==true){
                state_coli+=1;
                break;
                }
        }
    }*/

}

void tank_basic:: printImage(){
     al_draw_rotated_bitmap(ene_image,0,0,this->x,this->y,0,NULL);

}

void tank_hard:: printImage(){
     al_draw_rotated_bitmap(ene_image,0,0,this->x,this->y,0,NULL);

}
void tank_hard::mover(float n_x,float n_y,vector<float>cc){

    if(ph_mov.empty()){
        this->numx=n_x;
        this->numy=n_y;
        ph_mov.push_back(numx);
        ph_mov.push_back(numy);
    }else{
        if(this->x>=numx && this->y>=numy){
            ph_mov.pop_back();
            ph_mov.pop_back();

        }else{
              /*  int state_coli=0;
                for(int i=0;i<cc.size();i++){
                     coli=colision(cc[i],cc[i+1],70);
                    if(coli==true){

                        state_coli+=1;
                        break;
                    }
                }
                if(state_coli==1){
                    ph_mov.pop_back();
                    ph_mov.pop_back();
                }else{*/
                    setX(this->x+cos(atan2(numy-this->y,numx-this->x))*3);
                    setY(this->y+sin(atan2(numy-this->y,numx-this->x))*3);
               // }


        }

    }
}


