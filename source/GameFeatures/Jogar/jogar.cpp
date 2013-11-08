#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


using namespace std;

void digitarip(Vetor_mouse *vetor, SDL_Surface *screen);


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
            //criar_servidor();
            fase1(screen);
            cout << "cliquei em criar" << endl;
        }
    }

        else if(compara_selecao(565, 710, vetor->x, 211, 281, vetor->y)){

            if(vetor->click == 1){
                cout << "cliquei em conectar" << endl;
                digitarip(vetor, screen);
                //conectar("192.168.1.10");

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

void digitarip(Vetor_mouse *vetor, SDL_Surface *screen){

    while(1){
        vetor = get_Input();
        if(vetor->number == 1){
            cout << "entrei em digitar ip" << endl;
            char texto[] = "1";
            char font[] = "KGFeeling22.ttf";
            desenha_texto(texto, screen, 0, 0, font, 10);
            break;
        }
    }


}
