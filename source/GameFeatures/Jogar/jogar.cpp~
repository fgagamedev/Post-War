#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


using namespace std;

void digitarip(Vetor_mouse *vetor, SDL_Surface *screen);
void digitarnome(Vetor_mouse *vetor, SDL_Surface *screen);


void inicio(SDL_Surface *screen){

    string opcao = "source/GameFeatures/Jogar/images/conexao.png";
    SDL_Surface *escolher = load_Image(opcao, screen);

    const char* musica = "tela_de_abertura.wav";

    //SDL_Thread *audio = SDL_CreateThread(testeaudio, (void*)musica);

    Vetor_mouse *vetor = new Vetor_mouse;

    while(1){
        vetor = get_Input();
        BlitImage(screen, escolher, 0, 0);
        SDL_Flip(screen);

        if(compara_selecao(560, 740, vetor->x, 111, 181, vetor->y)){

            if(vetor->click == 1){
                cout<<"cliquei em servidor"<<endl;
                criar_servidor();
                fase1(screen,"servidor");
            }
        }

            else if(compara_selecao(565, 710, vetor->x, 211, 281, vetor->y)){
                if(vetor->click == 1){
                    cout << "cliquei em conectar" << endl;
                    //digitarnome(vetor, screen);
                    //digitarip(vetor, screen);
                    char local[] = "localhost";
                    conectar(local);
                    fase1(screen,"cliente");
                }

            }
                else if(compara_selecao(580, 630, vetor->x, 311, 381, vetor->y)){
                    if(vetor->click == 1){
                        Mix_CloseAudio();
                        load_menu(screen);
                    }

                }
                SDL_Flip(screen);
    }
}



void digitarip(Vetor_mouse *vetor, SDL_Surface *screen){
    int xinicial = 20;
    int yinicial = 20;

    while(1){
        vetor = get_Input();
        string texto;
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
                case 38:
                xinicial = xinicial - 30;
                texto = " ";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                SDL_Flip(screen);
                break;
                default:
                    break;
        }
    }
}

void digitarnome(Vetor_mouse *vetor, SDL_Surface *screen){
    int xinicial = 40;
    int yinicial = 60;
    //cout << "Entrei funcao digitarnome" << endl;

    while(1){
        vetor = get_Input();
        string texto;
        //cout << "to no while" << endl;
        switch(vetor->number){
            case 11:
                texto = "a";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 12:
                texto = "b";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 13:
                texto = "c";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 14:
                texto = "d";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 15:
                texto = "e";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 16:
                texto = "f";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 17:
                texto = "g";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 18:
                texto = "h";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 19:
                texto = "i";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 20:
                texto = "j";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 21:
                texto = "k";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 22:
                texto = "l";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 23:
                texto = "m";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 24:
                texto = "n";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 25:
                texto = "o";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 26:
                texto = "p";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 27:
                texto = "q";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 28:
                texto = "r";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 29:
                texto = "s";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 30:
                texto = "t";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 31:
                texto = "u";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 32:
                texto = "v";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 33:
                texto = "x";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 34:
                texto = "w";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 35:
                texto = "y";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 36:
                texto = "z";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 37:
                texto = " ";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                xinicial = xinicial + 30;
                SDL_Flip(screen);
                break;
            case 38:
                xinicial = xinicial - 30;
                texto =" ";
                desenha_texto(texto, screen, xinicial, yinicial, 60);
                SDL_Flip(screen);
                break;
            default:
                break;
        }
    }
}
