#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


using namespace std;

void digitarip(Vetor_mouse *vetor, SDL_Surface *screen);


void inicio(SDL_Surface *screen){

    string opcao = "source/GameFeatures/Jogar/images/conexao.png";
    char *ip;
    SDL_Surface *escolher = load_Image(opcao, screen);

    Vetor_mouse *vetor = new Vetor_mouse;

    while(1){
    vetor = get_Input();
    BlitImage(screen, escolher, 0, 0);
    SDL_Flip(screen);


    if(compara_selecao(560, 740, vetor->x, 111, 181, vetor->y)){

        if(vetor->click == 1){
            criar_servidor();
            fase1(screen);
        }
    }

        else if(compara_selecao(565, 710, vetor->x, 211, 281, vetor->y)){
            if(vetor->click == 1){
                cout << "Digite o IP" << endl;
                cin>>ip;
                //digitarip(vetor, screen);
                conectar(ip);
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
        cout<<"to aqui"<<endl;
        if(vetor->number == 1){
            cout << "entrei em digitar ip " << vetor->number << endl;
            char texto[] = "1";
            char font[] = "KGFeeling22.ttf";
            desenha_texto(texto, screen, 10, 10, font, 60);
            SDL_Flip(screen);

        }
    }


}
