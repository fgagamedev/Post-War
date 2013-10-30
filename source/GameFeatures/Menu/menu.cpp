#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void load_menu(SDL_Surface *screen){

    SDL_Surface *jogar_selecionado;
    SDL_Surface *creditos_selecionado;
    //carregando imagens
    string path_jogo = "source/GameFeatures/Menu/Images/jogar_selecionado.png";
    jogar_selecionado = load_Image(path_jogo,screen);
    string path_creditos = "source/GameFeatures/Menu/Images/creditos_selecionado.png";
    creditos_selecionado = load_Image(path_creditos, screen);
    string path = "source/GameFeatures/Menu/Images/menu.png";
    SDL_Surface *menu = load_Image(path, screen);


    SDL_Flip(screen);
    int cont=0;
    Vetor_mouse *vetor = new Vetor_mouse;


    while(1){

        vetor = get_Input();

        //cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        //cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(478.5,731.5,vetor->x,211,275,vetor->y)){
            BlitImage(screen, jogar_selecionado, 478.5, 211);
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

         if(compara_selecao(425,798,vetor->x,511,575,vetor->y)){
            BlitImage(screen, creditos_selecionado, 425.5, 511);
            SDL_Flip(screen);
            //cout<<"Entrei aqui"<<endl;
            if(vetor->click == 1){
                //cout<<"Clicou em jogar"<<endl;
                creditos(screen);
            }

        }   else{
                 BlitImage(screen, menu, 0, 0);
                 SDL_Flip(screen);
            }


    }

    SDL_Delay(10000);
}
