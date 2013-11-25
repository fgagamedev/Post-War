#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void fase1(SDL_Surface *screen,string qual_maquina){
    string pais_serv ("china");
    string pais_client ("eua");
    carregar_fase1(screen,pais_serv,pais_client);
    int lastdt = SDL_GetTicks();
    int totalElapsedTime = 0;
    int delay = 200;
    //BlitImage(screen, mapa1, 0, 0);

    Vetor_mouse *vetor = new Vetor_mouse;

    SDL_Flip(screen);

    string opcao = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_mouse.png";
    SDL_Surface *mouse = load_Image(opcao, screen);

    if(qual_maquina.compare("cliente")){
      cout<<"Sou servidor interessante"<<endl;
      while(1){
        char codigo_s[100];
        memset (codigo_s,'0',100);
        vetor = get_Input();

        if(vetor->click == 1){

            if(verifica_hexagono(vetor->x,vetor->y)){

            //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                hex_selecao->i_antes = hex_selecao->i;
                hex_selecao->j_antes = hex_selecao->j;
                if(possui_unidade()){
                    blit_tela(screen,1);
                    SDL_Flip(screen);
                            while(1){
                                vetor = get_Input();
                                if(vetor->click == 1){
                                    verifica_hexagono(vetor->x,vetor->y);
                                    if(!possui_unidade()){
                                        break;
                                    }
                                    if(alcance_movimento_soldado()){
                                        strcpy (codigo_s,"00");
                                        codigo_s[2] = (char)(((int)'0')+hex_selecao->i_antes);
                                        codigo_s[3] = (char)(((int)'0')+hex_selecao->j_antes);
                                        codigo_s[4] = (char)(((int)'0')+hex_selecao->i);
                                        codigo_s[5] = (char)(((int)'0')+hex_selecao->j);
                                        cout<<"Enviando msg..."<<endl;
                                        enviar_msg(Sclient,codigo_s);
                                        cout<<"Mensagem enviada foi: !!..."<<codigo_s<<endl;
                                        mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);

                                        break;
                                    }
                                        else{
                                                blit_tela(screen,0);
                                                break;
                                        }
                                }
                            }
                }
                blit_tela(screen,0);

            }

        }
        //blit_tela(screen);
        //BlitImage(screen,mouse,vetor->x-13,vetor->y-13 );
            SDL_Flip(screen);
        }

    }



    else{
        while(1){
            cout<<"Sou cliente zuero"<<endl;
            vetor = get_Input();
            char *code_recv;
            receber_msg(Cserver,code_recv);
            cout<<"Recebi a msg: "<<code_recv<<endl;

            if(vetor->click == 1){

                if(verifica_hexagono(vetor->x,vetor->y)){


                //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                    hex_selecao->i_antes = hex_selecao->i;
                    hex_selecao->j_antes = hex_selecao->j;
                    if(possui_unidade()){
                        blit_tela(screen,1);
                        SDL_Flip(screen);
                                while(1){
                                    vetor = get_Input();
                                    if(vetor->click == 1){
                                        verifica_hexagono(vetor->x,vetor->y);
                                        if(!possui_unidade()){
                                            break;
                                        }
                                        if(alcance_movimento_soldado()){
                                            mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);

                                            break;
                                        }
                                            else{
                                                    blit_tela(screen,0);
                                                    break;
                                            }
                                    }
                                }
                    }
                    blit_tela(screen,0);

                }

            }
            //blit_tela(screen);
            //BlitImage(screen,mouse,vetor->x-13,vetor->y-13 );
            SDL_Flip(screen);
        }
    }




}

