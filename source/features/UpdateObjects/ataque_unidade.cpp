#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;
void ataque_unidade(SDL_Surface *screen, int x, int y, int totalElapsedTime, int delay, int lastdt){

for(int i=0; i<5;i++){
        string tipoquartel = "quartel";
        Unidade *temp;
        SDL_Surface *temp_s;
        int n_sprites = 0;
        int tamanho_sprites = 0;

        int w = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->x;
        int s = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->y;

        if(hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade == 0){
            break;
        }

        temp = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
        if(temp->tipo == tipoquartel){
            cout << "Nao pode atacar" << endl;
            return;
        }
        string cor = "vermelho";
        string cor2 = "azul";
        string tipo = "metralhadora";
        string tipo2 = "soldado";
        string tipo3 = "helicoptero";
        string tipo4 = "tanque";
        cout << "cor da unidade atual:" << temp->cor << endl;
        cout << "Tipo unidade atual:" << temp->tipo << endl;

        SDL_Rect cutBox = {0,0,32,32};
        //Acha tanque azul
        if(temp->tipo == tipo4 && temp->cor == cor2){
            n_sprites = 4;
            if(s<y && w==x){
                temp_s = temp->ataque_baixo;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;

                tamanho_sprites = 32;
            }
            else if(s>y && w==x){
                temp_s = temp->ataque_cima;
                cutBox.x = 0;
                cutBox.y = 32;
                cutBox.w = 32;
                cutBox.h = 32;

                tamanho_sprites = 32;
            }
            else{
                temp_s = temp->ataque;
                cutBox.x = 32;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 64;
            }
        }
        //Acha tanque vermelho
        if(temp->tipo == tipo4 && temp->cor == cor){
            n_sprites = 4;
            if(s<y && w==x){
                temp_s = temp->ataque_baixo;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else if(s>y && w==x){
                temp_s = temp->ataque_cima;
                cutBox.x = 0;
                cutBox.y = 32;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else{
                temp_s = temp->ataque;
                cutBox.x = 32;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 64;
            }
        }
        //Acha helicoptero vermelho
        if(temp->tipo == tipo3 && temp->cor == cor){
        //Por enquanto nunca vai achar, hu3
        }
        //Acha helicoptero azul
        if(temp->tipo == tipo3 && temp->cor == cor2){
            cout << "Achei helicoptero azul" << endl;
            if(s<y && w==x){
                temp_s = temp->ataque_baixo;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
                n_sprites = 4;
            }
            else if(s>y && w==x){
                temp_s = temp->ataque_cima;
                cutBox.x = 0;
                cutBox.y = 32;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
                n_sprites = 4;
            }
            else{
                temp_s = temp->ataque;
                cutBox.x = 32;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 64;
                n_sprites = 9;
            }

        }
        //Acha metralhadora azul
        if(temp->tipo == tipo && temp->cor == cor2){
            temp_s = temp->ataque;
            cout << "Achei metralhadora" << endl;;
                cutBox.x = 64;
                cutBox.y = 0;
                cutBox.w = 64;
                cutBox.h = 64;
            tamanho_sprites = 64;
            n_sprites = 5;
        }
        //Acha metralhadora vermelha
        if(temp->tipo == tipo && temp->cor == cor){
            cout << "Achei metralhadora" << endl;
            temp_s = temp->ataque;
            cutBox.x = 0;
            cutBox.y = 0;
            cutBox.w = 64;
            cutBox.h = 64;
            tamanho_sprites = 64;
            n_sprites = 5;
        }
        //Acha soldado vermelho
        if(temp->cor == cor && temp->tipo == tipo2){
            cout << "Achei vermelho" << endl;
            n_sprites = 5;
            if(s<y && w==x){
                temp_s = temp->ataque_baixo;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else if(s>y && w==x){
                temp_s = temp->ataque_cima;
                cutBox.x = 0;
                cutBox.y = 32;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else{
                temp_s = temp->ataque;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 64;
            }
        }

        //Acha soldado azul
        if(temp->cor == cor2 && temp->tipo == tipo2){
            cout << "Achei azul" << endl;
            n_sprites = 5;
            if(s<y && w==x){
                temp_s = temp->ataque_baixo;
                cutBox.x = 0;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else if(s>y && w==x){
                temp_s = temp->ataque_cima;
                cutBox.x = 0;
                cutBox.y = 32;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 32;
            }
            else{
                temp_s = temp->ataque;
                cutBox.x = 32;
                cutBox.y = 0;
                cutBox.w = 32;
                cutBox.h = 32;
                tamanho_sprites = 64;
            }
        }


        int tempo_delay = 50;
        cout << "w:" << w << endl;
        cout << "s:" << s << endl;

        while(cutBox.x <n_sprites*tamanho_sprites){
            cout << "w:" << w << endl;
            cout << "s:" << s << endl;
            blit_tela_ataque(screen,1, w, s);
            int dt = SDL_GetTicks() - lastdt;
            lastdt = SDL_GetTicks();

            totalElapsedTime += dt;

             if(totalElapsedTime >= delay) {
                        totalElapsedTime -= delay;
                        //cout << "cutbotx:  " << cutBox.x << endl;
                        cutBox.x +=tamanho_sprites;
                    }

                    SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};

                    SDL_BlitSurface(temp_s, &cutBox, screen, &dest);

                    SDL_Delay(tempo_delay);
                    SDL_Flip(screen);


        }
    }
}
