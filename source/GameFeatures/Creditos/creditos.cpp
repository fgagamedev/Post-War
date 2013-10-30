#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"



using namespace std;

void creditos(SDL_Surface *screen){

    SDL_Surface *coisa = setup_video();

    string imagem_sdl = "source/GameFeatures/Creditos/Images/2.png";
    SDL_Surface *sdl = load_Image(imagem_sdl, coisa);

    SDL_Flip(coisa);

    SDL_Delay(2000);

}
