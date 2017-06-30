#include "game.h"
game *game::instan_game=0;

game::game(){

    screenWidth = 600;
    screenHeight = 488;
    worldWidth = 1520;
    worldHeight = 1520;
    //MUSIC=load_midi("mario.mid");
    MUSIC=NULL;
    coin=al_load_bitmap("monedas.png");
    if(!al_init()) {
      fprintf(stderr, "failed to initiñŔ108uj7,i8alize allegro!\n");
    }
    if(!al_init_image_addon()){
      fprintf(stderr, "failed to initialize image!\n");
    }
    al_init_font_addon();
    al_init_ttf_addon();

    if(!al_install_audio()) {
      fprintf(stderr, "failed to initialize audio!\n");
    }
    if(!al_init_acodec_addon()){
       fprintf(stderr, "failed to initialize audio codec!\n");
    }

     MUSIC = al_load_sample("musclecar2.wav");

   if (!MUSIC){
      printf( "Audio clip sample not loaded!\n" );
      //printf("cerdos");
     // return -1;
   }

    font = al_load_ttf_font("ff.otf",30,0 );

    display = al_create_display(screenWidth, screenHeight);
    al_set_window_position(display,120,150);
    al_set_window_title(display,"Tanque");
}
int game::getHeight_Screen(){

    return screenHeight;
}
int game::getWidth_Screen(){
    return screenWidth;

}
/*
void game::load_coin(std::vector<float>cc){

    for(int i=0;cc.size();i++){
        al_draw_bitmap(coin,cc[i],cc[i+1],0);

    }
}
*/
ALLEGRO_DISPLAY *game::getdisplay(){
     return display;
}
ALLEGRO_FONT *game::getfont(){
    return font;
}
int game::getHeight_world(){

    return worldHeight;
}
int game::getWidth_world(){
       return worldWidth;

}
game *game::Get_instance_game(){
  if(instan_game==0){
        instan_game= new game();
    }
    return instan_game;
}
ALLEGRO_SAMPLE * game::getmusic(){
    return MUSIC;


}

