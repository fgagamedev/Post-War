#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void load_menu(SDL_Surface *screen){

    SDL_Surface *borda;
    //carregando imagens
    string path = "source/GameFeatures/Menu/Images/borda.png";
    borda = load_Image(path,screen);
    path = "source/GameFeatures/Menu/Images/menu.png";
    SDL_Surface *menu = load_Image(path, screen);


    SDL_Flip(screen);
    int cont=0;
    Vetor_mouse *vetor = new Vetor_mouse;
    while(1){



        vetor = get_Input();

        //cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        //cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(476.5,731.5,vetor->x,251,329,vetor->y)){
            BlitImage(screen, borda, 476.5, 251);
            SDL_Flip(screen);
            //cout<<"Entrei aqui"<<endl;
            if(vetor->click == 1){
                //cout<<"Clicou em jogar"<<endl;
                inicio(screen);
            }

        }   else{
                 BlitImage(screen, menu, 0, 0);
                SDL_Flip(screen);
            }

    }

    SDL_Delay(10000);
}
