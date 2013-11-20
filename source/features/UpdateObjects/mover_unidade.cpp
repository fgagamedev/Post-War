#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

void mover_soldado(SDL_Surface *screen, int i, int x, int y, int totalElapsedTime, int delay, int lastdt){
    /*for(int h = unidades_vermelhas[i]->x, w = unidades_vermelhas[i]->y;h>x; h = h-25){
    cout << "entrei for com h = " << h << endl;
    cout << "entrei com w = " << w << endl;
    int posi = unidades_vermelhas[i]->x;

    for(int j = posi;j>x;j--){
    SDL_Rect pos = {j, y};
    unidades_vermelhas[i]->x = j;
    //SDL_BlitSurface(unidades_vermelhas[i]->nome, NULL, screen, &pos);
    blit_tela(screen);
    }*/

    hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade= NULL;
    hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade= 0;
    SDL_Rect cutBox = {32,0,32,32};
    int w = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->x;
    int s = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->y;

    cout << "w:" << w << endl;
    cout << "x:" << x << endl;
    while(w > x){

        blit_tela(screen);

        int dt = SDL_GetTicks() - lastdt;
        lastdt = SDL_GetTicks();
        //cout << "w:" << w << endl;
        //cout << "x:" << x << endl;
        //cout << "dt:" << dt << endl;
        //cout << "lastdt:" << lastdt << endl;
        //cout << "delay:" << delay << endl;
        //cout << "w:" << w << endl;
        if(w>x){
            w = w - 2;

            if(s>y){
                s = s - 2;
            }
            if(s<y){
                s = s + 2;
                //cout << "w:" << w << endl;
            }
                //cout << "w:" << w << endl;
                totalElapsedTime += dt;
                //cout << "totalElapsedTime:" << totalElapsedTime << endl;
                if(totalElapsedTime >= delay) {
                    totalElapsedTime -= delay;
                    //cout << "cutbotx:  " << cutBox.x << endl;
                    if(cutBox.x == 0){
                        //cout << "Entrei aqui" << endl;
                        cutBox.x = 32;
                    }
                    else {
                        cutBox.x -= 32;
                    }
                }

                SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};
                cout<<"hex_selecaoantes_i= "<<hex_selecao->i_antes<<endl;
                cout<<"hex_selecaoantes_j= "<<hex_selecao->j_antes<<endl;
                cout<<"hex_selecao_i= "<<hex_selecao->i<<endl;
                cout<<"hex_selecao_j= "<<hex_selecao->j<<endl;
                //hexagonos[hex_selecao->i][hex_selecao->j]->unidade->nome
                SDL_BlitSurface(unidades_vermelhas[0]->nome, &cutBox, screen, &dest);
                SDL_Delay(200);
                SDL_Flip(screen);
                unidades_vermelhas[i]->x = x;
                unidades_vermelhas[i]->y = y;




        }
    }



}
