#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"


void load_menu(SDL_Surface *screen){

    SDL_Surface *borda;
    //carregando imagens
    string path = "source/GameFeatures/Menu/Images/borda.png";
    borda = load_Image(path,screen);
    path = "source/GameFeatures/Menu/Images/menu.png";
    SDL_Surface *menu = load_Image(path, screen);
    path = "source/GameFeatures/Menu/Images/jogar.png";
    SDL_Surface *jogar =load_Image(path, screen); //h: 255, w: 78
    path = "source/GameFeatures/Menu/Images/opcoes.png";
    SDL_Surface *opcoes =load_Image(path, screen);// ,w: 78
    path = "source/GameFeatures/Menu/Images/sair.png";
    SDL_Surface *sair =load_Image(path, screen);
    path = "source/GameFeatures/Menu/Images/creditos.png";
    SDL_Surface *creditos =load_Image(path, screen);
    BlitImage(screen, menu, 0, 0);
    BlitImage(screen, jogar, 476.5, 251);
    BlitImage(screen, opcoes, 453.4, 351);
    BlitImage(screen, creditos, 425.5, 451);
    BlitImage(screen, sair, 360.5, 551);


    Vetor_mouse *vetor = new Vetor_mouse;
    while(1){
        SDL_Flip(screen);

        vetor = get_Input();

        //cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        //cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(476.5,731.5,vetor->x,251,329,vetor->y)){
            BlitImage(screen, borda, 357, 251);
            SDL_Flip(screen);
            cout<<"Entrei aqui"<<endl;
            if(vetor->click == 1){
                cout<<"Clicou em jogar"<<endl;
                //jogar();
            }
        }
        //free_image(borda);

    }

    SDL_Delay(10000);
}
