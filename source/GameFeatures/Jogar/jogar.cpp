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
    SDL_Surface *escolher = load_Image(opcao, screen);

    Vetor_mouse *vetor = new Vetor_mouse;

    while(1){
    vetor = get_Input();
    BlitImage(screen, escolher, 0, 0);
    SDL_Flip(screen);

    if(compara_selecao(560, 740, vetor->x, 111, 181, vetor->y)){

        if(vetor->click == 1){
            //criar_servidor();
            fase1(screen);
        }
    }

        else if(compara_selecao(565, 710, vetor->x, 211, 281, vetor->y)){
            if(vetor->click == 1){
                cout << "cliquei em conectar" << endl;
                digitarip(vetor, screen);
                //conectar("192.168.1.10");
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
    int xinicial = 20;
    int yinicial = 20;

    while(1){
        vetor = get_Input();
        char *texto;
            switch(vetor->number){
                case 1:
                    //cout << "entrei em digitar ip " << vetor->number << endl;
                    texto = "1";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 2:
                    texto = "2";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 3:
                    texto = "3";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 4:
                    texto = "4";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 5:
                    texto = "5";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 6:
                    texto = "6";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 7:
                    texto = "7";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 8:
                    texto = "8";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 9:
                    texto = "9";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 10:
                    texto = ".";
                    desenha_texto(texto, screen, xinicial, yinicial, 60);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                default:
                    break;
        }
    }
}

