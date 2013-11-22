#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

///REFATORAR ESSE ARQUIVO!!!!!!!!!!!!
///FAZER ENCADEAMENTO DE IF'S NA MOVIMENTAÇÃO

void mover_soldado(SDL_Surface *screen, int x, int y, int totalElapsedTime, int delay, int lastdt){

    Unidade *temp;

    temp = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
    hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade= NULL;
    hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade= 0;
    SDL_Rect cutBox = {32,0,32,32};

    int tempo_delay;

    if(temp->tipo=="helicoptero"){
        tempo_delay = 0;
    }   else{
            tempo_delay = 100;
        }

    int w = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->x;
    int s = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->y;

    cout << "w:" << w << endl;
    cout << "x:" << x << endl;


    while(w!=x || y != s) {
        blit_tela(screen,1);
        int dt = SDL_GetTicks() - lastdt;
        lastdt = SDL_GetTicks();
        cout << "w:" << w << endl;
        cout << "x:" << x << endl;
        //cout << "dt:" << dt << endl;
        //cout << "lastdt:" << lastdt << endl;
        //cout << "delay:" << delay << endl;
        //cout << "w:" << w << endl;
                if(w == x && s>y){
                    if(abs(y - s) == 1)
                        s = s - 1;
                    s = s - 2;
                }

                else if(w < x){
                     if(abs(w - x) == 1)
                        w = w + 1;
                     w = w + 2;
                }

                else if (w > x){
                     if(abs(w -y) == 1)
                        w = w -1;
                    w = w - 2;
                }

                if(s>y){
                     if(abs(y -s) == 1)
                        s = s - 1;
                    s = s - 2;
                }
                else if(s<y){
                    if(abs(y -s) == 1)
                        s = s + 1;
                    s = s + 2;
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
               /* cout<<"hex_selecaoantes_i= "<<hex_selecao->i_antes<<endl;
                cout<<"hex_selecaoantes_j= "<<hex_selecao->j_antes<<endl;
                cout<<"hex_selecao_i= "<<hex_selecao->i<<endl;
                cout<<"hex_selecao_j= "<<hex_selecao->j<<endl;*/
                //hexagonos[hex_selecao->i][hex_selecao->j]->unidade->nome
                if(hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade){
                    cout<<"WOLOLOLO"<<endl;
                }
                SDL_BlitSurface(temp->nome, &cutBox, screen, &dest);

                SDL_Delay(tempo_delay);
                SDL_Flip(screen);
            }



    //unidades_vermelhas[i]->x = x;
    //unidades_vermelhas[i]->y = y;
    hexagonos[hex_selecao->i][hex_selecao->j]->unidade = temp;
    hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade = 1;

}
