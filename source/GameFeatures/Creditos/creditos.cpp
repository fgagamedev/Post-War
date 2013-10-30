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
    string imagem_ubuntu = "source/GameFeatures/Creditos/Images/3.png";
    SDL_Surface *ubuntu = load_Image(imagem_ubuntu, coisa);

    SDL_Flip(screen);


    for(int i = -680; i <= 680; i++){
		BlitImage(coisa, sdl, 0, i);
		SDL_Flip(coisa);
		if(i==680){
            for(int j = -680; j <= 680; j++){
                BlitImage(screen, ubuntu, 0, j);
                SDL_Flip(screen);
            }
		}
    }


    SDL_Delay(2000);

}
