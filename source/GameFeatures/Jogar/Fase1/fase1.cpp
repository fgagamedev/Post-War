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

        if(vetor->click == 1){

            if(verifica_hexagono(vetor->x,vetor->y)){
            cout<<"lets go"<<endl;
            //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
            hex_selecao->i_antes = hex_selecao->i;
            hex_selecao->j_antes = hex_selecao->j;
                    while(1){
                        vetor = get_Input();
                        if(vetor->click == 1){
                            verifica_hexagono(vetor->x,vetor->y);
                            mover_soldado(screen, 0, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                            break;
                        }
                    }
            }
                //}
            /*
            if(compara_selecao(unidades_vermelhas[1]->x, unidades_vermelhas[1]->x+32, vetor->x, unidades_vermelhas[1]->y, unidades_vermelhas[1]->y+32, vetor->y)){
                //cout << "cliquei unidade 1" << endl;
                while(1){
                    vetor = get_Input();
                    if(vetor->click == 1){
                        mover_soldado(screen, 1, hexagonos[hex_selecao->i][hex_selecao->j]->x, hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                        break;
                    }
                }
            }
            if(compara_selecao(unidades_vermelhas[2]->x, unidades_vermelhas[2]->x+32, vetor->x, unidades_vermelhas[2]->y, unidades_vermelhas[2]->y+32, vetor->y)){
                //cout << "cliquei unidade 2" << endl;
                while(1){
                    vetor = get_Input();
                    if(vetor->click == 1){
                        mover_soldado(screen, 2, hexagonos[hex_selecao->i][hex_selecao->j]->x, hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                        break;
                    }
                }
            }*/
        }
    }
}

