#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void mover_soldado(SDL_Surface *screen, int i, int x, int y){
    //for(int h = unidades_vermelhas[i]->x, w = unidades_vermelhas[i]->y;h>x; h = h-25){
    //cout << "entrei for com h = " << h << endl;
    //cout << "entrei com w = " << w << endl;
    SDL_Rect pos = {x, y};
    SDL_BlitSurface(unidades_vermelhas[i]->nome, NULL, screen, &pos);
    SDL_Flip(screen);
    //}
}
