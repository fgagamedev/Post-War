#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void fase1(SDL_Surface *screen){

    carregar_fase1(screen);

    //BlitImage(screen, mapa1, 0, 0);



    SDL_Flip(screen);

}
