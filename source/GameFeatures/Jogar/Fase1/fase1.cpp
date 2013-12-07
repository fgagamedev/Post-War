#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

int pontos_jogador1 = 20;
int pontos_jogador2 = 20;
int vermelhoperde = 0;
int azulperde = 0;
string cor2 = "azul";
string cor1 = "vermelho";



void fase1(SDL_Surface *screen,string qual_maquina){
    Pais *china = new Pais();
    string nome = "China";
    setar_pais(china, 50, 100, 50, nome);
    Pais *eua = new Pais();
    nome = "EUA";
    setar_pais(eua, 100, 50, 50, nome);

    char pais_serv[100] = "china";
    char pais_client[100] = "eua";


    carregar_fase1(screen,pais_serv,pais_client);
    int lastdt = SDL_GetTicks();
    int totalElapsedTime = 0;
    int delay = 200;
    char codigo_s[100];
    //BlitImage(screen, mapa1, 0, 0);
    int minha_vez;

    Vetor_mouse *vetor = new Vetor_mouse;

    SDL_Flip(screen);

    //string opcao = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_mouse.png";
    //SDL_Surface *mouse = load_Image(opcao, screen);

    if(qual_maquina.compare("cliente")){
        minha_vez=1;
        cout << "Setei vez 1" << endl;
        cout<<"Sou servidor"<<endl;
        while(1){

            //memset (codigo_s,'0',100);
            if(minha_vez){
                blit_cima(china,screen);
                desenha_pontos(pontos_jogador1, screen);
                vetor = get_Input();
                string palavra = "Sua vez.";
                red = 255;
                green = 0;
                blue = 0;
                desenha_texto(palavra,screen,200, 200, 60);

                if(vetor->click == 1){

                    if(verifica_hexagono(vetor->x,vetor->y)){

                    //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                        hex_selecao->i_antes = hex_selecao->i;
                        hex_selecao->j_antes = hex_selecao->j;
                        if(possui_unidade("vermelho")){
                            blit_tela(screen,1);
                            blit_lateral(hexagonos[hex_selecao->i][hex_selecao->j]->unidade,screen);
                            blit_cima(china,screen);
                            while(1){
                                vetor = get_Input();
                                if(vetor->click == 1){
                                    //cout<<"What?"<<endl;
                                    verifica_hexagono(vetor->x,vetor->y);

                                    if(possui_unidade("vermelho")){
                                        //cout<<"VÉSH"<<endl;
                                        break;
                                    }
                                    cout<<"ETA"<<endl;
                                    if(alcance_ataque_soldado()){
                                        dano_ataque(screen);
                                        codifica_ataque(codigo_s);
                                        //cout << "passei codifica" << endl;
                                        enviar_msg(Sclient,codigo_s);
                                        //cout << "enviei" << endl;
                                        ataque_unidade(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                        //cout << "animei ataque" << endl;
                                        cout << "derrotado:" << derrotado << endl;
                                        if(derrotado.compare(cor1) == 0){
                                            cout << "Vermelho perdeu" << endl;
                                            vermelhoperde = 1;
                                            perdeu_jogo(screen);
                                        }
                                        if(azulperde == 1){
                                            cout << "Vermelho venceu" << endl;
                                        }
                                        pontos_jogador1 -= 6;
                                        cout << "Substrai do pontos jogador 1:" << pontos_jogador1 << endl;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            cout << "Sai do jogador 1" << endl;
                                            pontos_jogador1 = 20;
                                        }
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
                                        cout<<"A mensagem enviada foi: "<<codigo_s  <<endl;
                                        mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                        pontos_jogador1 -= 3;
                                        cout << "Substrai do pontos jogador 1:" << pontos_jogador1 << endl;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            cout << "Sai do jogador 1" << endl;
                                            pontos_jogador1 = 20;
                                        }
                                        break;
                                    }
                                        else{
                                            blit_tela(screen,0);
                                            blit_cima(china,screen);
                                            break;
                                        }
                                }
                            }
                        }
                        //verifica_derrota(screen);
                        blit_tela(screen,0);
                        blit_cima(china,screen);
                    }


                }
            SDL_Flip(screen);
            }

                else{
                    blit_cima(china,screen);
                    string palavra = "Vez do outro jogador.";
                    blit_tela(screen,0);
                    desenha_texto(palavra,screen,200, 200, 60);
                    SDL_Flip(screen);
                    char code_recv[100];
                    receber_msg(Sclient,code_recv);
                    cout<<"Recebi a msg: "<<code_recv<<endl;
                    amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
                    if(code_recv[0] == '0' && code_recv[1] == '0'){
                        pontos_jogador2 -=3;
                    }
                    if(code_recv[0] == '0' && code_recv[1] == '1'){
                        pontos_jogador2 -=6;
                        cout << "Derrotado:" << derrotado << endl;
                        if(derrotado.compare(cor2) == 0){
                            cout << "Azul perdeu" << endl;
                            azulperde = 1;
                        }
                        if(vermelhoperde == 1){
                            cout << "Azul venceu" << endl;
                        }
                    }
                    cout << "Pontos jogador 2:" << pontos_jogador2 << endl;
                    if(pontos_jogador2<3){
                        cout << "Pulei para o jogador 1" << endl;
                        minha_vez = 1;
                        pontos_jogador2 = 20;
                    }
                }
        }
    }


    else{
        blit_cima(eua,screen);
        minha_vez = 0;
        cout << "Setei minha vez 0" << endl;
        red = 0;
        green = 200;
        blue = 200;

        while(1){

        if(minha_vez == 0){

            blit_cima(eua,screen);
            string palavra = "Vez do outro jogador.";
            blit_tela(screen,0);
            desenha_texto(palavra,screen,200, 200, 60);
            SDL_Flip(screen);
            cout<<"Sou cliente"<<endl;
            vetor = get_Input();
            char code_recv[100];
            receber_msg(Cserver,code_recv);
            cout<<"Recebi a msg: "<<code_recv<<endl;
            amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
            if(code_recv[0] == '0' && code_recv[1] == '0'){
                    pontos_jogador1 -=3;
            }
            if(code_recv[0] == '0' && code_recv[1] == '1'){
                pontos_jogador1 -=6;
                cout << "Derrotado:" << derrotado << endl;
                if(derrotado.compare(cor1) == 0){
                    cout << "Vermelho perdeu" << endl;
                    vermelhoperde = 1;
                }
                if(azulperde == 1){
                    cout << "Vermelho venceu" << endl;
                }
            }
            cout << "Pontos jogador 1:" << pontos_jogador1 << endl;
            if(pontos_jogador1<3){
                cout << "Pulei para o jogador 2" << endl;
                minha_vez = 1;
                pontos_jogador1 = 20;
            }

        }
            else{
                blit_cima(eua,screen);
                desenha_pontos(pontos_jogador2, screen);
                //cout<<"eu cliente, fui até aqui"<<endl;
                vetor = get_Input();
                string palavra = "Sua vez.";
                desenha_texto(palavra,screen,200, 200, 60);

                if(vetor->click == 1){

                    if(verifica_hexagono(vetor->x,vetor->y)){


                    //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                        hex_selecao->i_antes = hex_selecao->i;
                        hex_selecao->j_antes = hex_selecao->j;
                        if(possui_unidade("azul")){
                            blit_cima(eua,screen);
                            blit_tela(screen,1);
                            blit_lateral(hexagonos[hex_selecao->i][hex_selecao->j]->unidade,screen);
                                    while(1){
                                        blit_cima(eua,screen);
                                        vetor = get_Input();
                                        if(vetor->click == 1){
                                            verifica_hexagono(vetor->x,vetor->y);
                                            if(possui_unidade("azul")){
                                                break;
                                            }
                                            if(alcance_ataque_soldado()){
                                                dano_ataque(screen);
                                                codifica_ataque(codigo_s);
                                                //cout << "passei codifica" << endl;
                                                enviar_msg(Cserver,codigo_s);
                                                cout << "enviei" << endl;
                                                ataque_unidade(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                                //cout << "animei ataque" << endl;
                                                cout << "Derrotado:" << derrotado << endl;
                                                if(derrotado.compare(cor2) == 0){
                                                    cout << "Azul perdeu" << endl;
                                                    azulperde = 1;
                                                }
                                                if(vermelhoperde == 1){
                                                    cout << "Azul venceu" << endl;
                                                }
                                                pontos_jogador2 -= 6;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    cout << "Sai do jogador 2" << endl;
                                                    pontos_jogador2 = 20;
                                                }
                                                break;
                                            }



                                            if(alcance_movimento_soldado()){

                                                strcpy (codigo_s,"00");
                                                codigo_s[2] = (char)(((int)'0')+hex_selecao->i_antes);
                                                codigo_s[3] = (char)(((int)'0')+hex_selecao->j_antes);
                                                codigo_s[4] = (char)(((int)'0')+hex_selecao->i);
                                                codigo_s[5] = (char)(((int)'0')+hex_selecao->j);
                                                cout<<"Enviando msg..."<<endl;
                                                enviar_msg(Cserver,codigo_s);
                                                cout<<"A mensagem enviada foi: "<<codigo_s  <<endl;

                                                mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                                pontos_jogador2 -= 3;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    cout << "Sai do jogador 2" << endl;
                                                    pontos_jogador2 = 20;
                                                }
                                                break;
                                            }
                                                else{
                                                        blit_tela(screen,0);
                                                        blit_cima(eua,screen);
                                                        break;
                                                }
                                        }
                                    }
                        }
                        blit_tela(screen,0);
                        blit_cima(eua,screen);

                    }

                }
                //blit_tela(screen);
                //BlitImage(screen,mouse,vetor->x-13,vetor->y-13 );
                SDL_Flip(screen);
            }
        }
    }


}



void codifica_ataque(char codigo_s[]){

    strcpy(codigo_s,"01");
    codigo_s[2] = (char)(((int)'0')+hex_selecao->i_antes);
    codigo_s[3] = (char)(((int)'0')+hex_selecao->j_antes);
    codigo_s[4] = (char)(((int)'0')+hex_selecao->i);
    codigo_s[5] = (char)(((int)'0')+hex_selecao->j);
    /*codigo_s[6] = hp1/1000;
    codigo_s[7] = ((hp1%1000) - (hp1%100))/100;
    codigo_s[8] = ((hp1%100) - (hp1%10))/10;
    codigo_s[9] = hp1%10;
    codigo_s[10] = hp2/1000;
    codigo_s[11] = ((hp2%1000) - (hp2%100))/100;
    codigo_s[12] = ((hp2%100) - (hp2%10))/10;
    codigo_s[13] = hp2%10;*/
}


void amigo_movimenta(char code_recv[],SDL_Surface * screen, int totalElapsedTime, int delay, int lastdt){

            if(code_recv[0] == '0' && code_recv[1] == '0'){
                hex_selecao->i_antes = code_recv[2] - 48;
                hex_selecao->j_antes = code_recv[3] - 48;
                hex_selecao->i = code_recv[4] - 48;
                hex_selecao->j = code_recv[5] - 48;
                mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                blit_tela(screen,0);
            }

            else if(code_recv[0] == '0' && code_recv[1] == '1'){
                hex_selecao->i_antes = code_recv[2] - 48;
                hex_selecao->j_antes = code_recv[3] - 48;
                hex_selecao->i = code_recv[4] - 48;
                hex_selecao->j = code_recv[5] - 48;
                dano_ataque(screen);
                ataque_unidade(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);

                blit_tela(screen,0);
            }
}

void desenha_pontos(int number, SDL_Surface *screen){
    string points;
    points = convertInt(number);

    desenha_texto(points,screen, 1000, 20, 30);
}



