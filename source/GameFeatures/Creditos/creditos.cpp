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

    string tela = "source/GameFeatures/Creditos/Images/tela_preta.png";
    SDL_Surface *telapreta = load_Image(tela, coisa);
    string imagem_sdl = "source/GameFeatures/Creditos/Images/2.png";
    SDL_Surface *sdl = load_Image(imagem_sdl, coisa);
    string imagem_ubuntu = "source/GameFeatures/Creditos/Images/3.png";
    SDL_Surface *ubuntu = load_Image(imagem_ubuntu, coisa);

    SDL_Flip(screen);


    for(int i = -680; i <= 680; i++){
		BlitImage(screen, sdl, 0, i);
		SDL_Flip(screen);
		BlitImage(screen, telapreta, 0, 0);
		SDL_Flip(screen);
		if(i==680){
            for(int j = -680; j <= 680; j++){
                BlitImage(screen, ubuntu, 0, j);
                SDL_Flip(screen);
            }
		}
    }
		SDL_Delay(2000);
    }

