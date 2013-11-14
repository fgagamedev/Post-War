#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../include/draw.h"
#include "../../include/video.h"
#include "../../include/loop.h"
#include "../../include/gamefeatures.h"

extern SDL_Surface *mapa1;

using namespace std;
void blit_tela(SDL_Surface *screen){

    BlitImage(screen, mapa1, 0, 0);

     for(int i=0;i<unidades_azul.size();i++){
            BlitImage(screen,unidades_azul[i]->nome,unidades_azul[i]->x,unidades_azul[i]->y);

    }

    for(int i=0;i<unidades_vermelhas.size();i++){
            BlitImage(screen,unidades_vermelhas[i]->nome,unidades_vermelhas[i]->x,unidades_vermelhas[i]->y);

    }

cout<<"ioa"<<endl;
}
