#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void mover_soldado(SDL_Surface *screen, int i, int x, int y){
    SDL_Rect pos = {x, y};
    SDL_BlitSurface(unidades_vermelhas[i]->nome, NULL, screen, &pos);
    SDL_Flip(screen);
}
