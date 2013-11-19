#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void fase1(SDL_Surface *screen){
    string pais_serv ("china");
    string pais_client ("eua");
    carregar_fase1(screen,pais_serv,pais_client);
    int lastdt = SDL_GetTicks();
    int totalElapsedTime = 0;
    int delay = 200;
    //BlitImage(screen, mapa1, 0, 0);

    Vetor_mouse *vetor = new Vetor_mouse;

    SDL_Flip(screen);

      while(1){
        vetor = get_Input();

        //cout << "x unidade vermelha 0:" << unidades_vermelhas[0]->x << endl;
        if(vetor->click == 1){
            verifica_hexagono(vetor->x,vetor->y);
            if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                cout << "cliquei unidade 0" << endl;
                    //cout << "cliquei no boneco certo e vetor click ="<< vetor->click << endl;
                    while(1){
                        vetor = get_Input();
                        if(vetor->click == 1){
                            mover_soldado(screen, 0, vetor->x, vetor->y, totalElapsedTime, delay, lastdt);
                            break;
                        }
                    }
                }
            if(compara_selecao(unidades_vermelhas[1]->x, unidades_vermelhas[1]->x+32, vetor->x, unidades_vermelhas[1]->y, unidades_vermelhas[1]->y+32, vetor->y)){
                cout << "cliquei unidade 1" << endl;
                while(1){
                        vetor = get_Input();
                        if(vetor->click == 1){
                            mover_soldado(screen, 1, vetor->x, vetor->y, totalElapsedTime, delay, lastdt);
                            break;
                        }
                    }

            }
            }
        }
}

