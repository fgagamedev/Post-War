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
    string imagem_bryj = "source/GameFeatures/Creditos/Images/1.png";
    SDL_Surface *bryj = load_Image(imagem_bryj, coisa);
    string imagem_sdl = "source/GameFeatures/Creditos/Images/2.png";
    SDL_Surface *sdl = load_Image(imagem_sdl, coisa);
    string imagem_ubuntu = "source/GameFeatures/Creditos/Images/3.png";
    SDL_Surface *ubuntu = load_Image(imagem_ubuntu, coisa);
    string imagem_16 = "source/GameFeatures/Creditos/Images/4.png";
    SDL_Surface *dezesseis= load_Image(imagem_16, coisa);
    string creditos_path = "source/GameFeatures/Creditos/Images/creditos.png";
    SDL_Surface *creditos= load_Image(creditos_path, coisa);


    SDL_Flip(screen);


    for(int j = -680; j <= 680; j+=2){
        BlitImage(coisa, telapreta, 0, 0);
        BlitImage(coisa, creditos, 0, j);
        SDL_Flip(coisa);
    }

    for(int i = -680; i <= 680; i+=2){
		BlitImage(coisa, telapreta, 0, 0);
		BlitImage(coisa, bryj, 0, i);
		SDL_Flip(coisa);
    }


    for(int i = -680; i <= 680; i+=2){
		BlitImage(coisa, telapreta, 0, 0);
		BlitImage(coisa, sdl, 0, i);
		SDL_Flip(coisa);
    }

    for(int j = -680; j <= 680; j+=2){
        BlitImage(coisa, telapreta, 0, 0);
        BlitImage(coisa, ubuntu, 0, j);
        SDL_Flip(coisa);
    }


}

