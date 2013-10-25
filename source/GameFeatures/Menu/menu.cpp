#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"


void load_menu(SDL_Surface *screen){

    SDL_Surface *borda;

    string path = "source/GameFeatures/Menu/Images/menu.png";
    load_Image(path, screen, 0, 0);
    path = "source/GameFeatures/Menu/Images/jogar.png";
    load_Image(path, screen, 476.5, 251); //h: 255, w: 78
    path = "source/GameFeatures/Menu/Images/opcoes.png";
    load_Image(path, screen, 453.5, 351);// ,w: 78
    path = "source/GameFeatures/Menu/Images/estatisticas.png";
    load_Image(path, screen, 357, 451);
    path = "source/GameFeatures/Menu/Images/creditos.png";
    load_Image(path, screen, 425.5, 551);

    while(1){
        SDL_Flip(screen);
        Vetor_mouse *vetor = new Vetor_mouse;
        vetor = get_Input();
        cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(476.5,731.5,vetor->x,251,329,vetor->y)){
            path = "source/GameFeatures/Menu/Images/borda.png";
            borda = load_Image(path,screen,357,251);
            if(vetor->click == 1){
                cout<<"Clicou em jogar"<<endl;
                //jogar();
            }
        }
        free_image(borda);

    }

    SDL_Delay(10000);
}
