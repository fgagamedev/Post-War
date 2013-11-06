#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


using namespace std;

void inicio(SDL_Surface *screen){

    SDL_Surface *escolha = setup_video();

    string opcao = "source/GameFeatures/Jogar/images/conexao.png";
    SDL_Surface *escolher = load_Image(opcao, escolha);

    Vetor_mouse *vetor = new Vetor_mouse;

    while(1){

    vetor = get_Input();
    BlitImage(escolha, escolher, 0, 0);
    SDL_Flip(escolha);


    if(compara_selecao(560, 740, vetor->x, 111, 181, vetor->y)){

        if(vetor->click == 1){
            criar_servidor();
            cout << "cliquei em criar" << endl;
        }
    }

        else if(compara_selecao(565, 710, vetor->x, 211, 281, vetor->y)){

            if(vetor->click == 1){
                conectar("192.168.1.10");
                cout << "cliquei em conectar" << endl;
            }

        }

            else if(compara_selecao(580, 630, vetor->x, 311, 381, vetor->y)){

                if(vetor->click == 1){
                        break;
                }

            }
    }





}
