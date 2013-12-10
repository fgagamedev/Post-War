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
#include "../../../include/sound.h"



using namespace std;

Hex_selecao *hex_selecao;
char codigo[100];
SDL_Surface *mapa1;

vector <Unidade *> unidades_azul;
vector <Unidade *> unidades_vermelhas;
vector< vector <Hexagono*> > hexagonos;
int id;

int pontos_jogador1 = 20;
int pontos_jogador2 = 20;
int vermelhoperde = 0;
int azulperde = 0;
int vermelhoganha = 0;
int azulganha = 0;
string cor2 = "azul";
string cor1 = "vermelho";
int minerio_vermelho = 10;
int minerio_azul = 10;
int ouro_vermelho = 10;
int ouro_azul = 10;
int comida_vermelha = 10;
int comida_azul = 10;

SDL_Surface *sem_malha;
SDL_Surface *com_malha;
SDL_Surface *hud;
SDL_Surface *hud2;
SDL_Surface *menu_meio;
SDL_Surface *menu_jogo;
SDL_Surface *menu_menor;
SDL_Surface *voltar_jogo_sel;
SDL_Surface *sair_sel;
SDL_Surface *opcoes_sel;
int x_painel;
int y_painel;

void digitarip(Vetor_mouse *vetor, SDL_Surface *screen);
void digitarnome(Vetor_mouse *vetor, SDL_Surface *screen);


void inicio(SDL_Surface *screen){

    string opcao = "source/GameFeatures/Jogar/images/conexao.png";
    SDL_Surface *escolher = load_Image(opcao, screen);

    opcao = "source/GameFeatures/Jogar/images/criar_partida_selecionado.png";
    SDL_Surface *criar_selecao = load_Image(opcao,screen);

    opcao = "source/GameFeatures/Jogar/images/entrar-partida_selecionado.png";
    SDL_Surface *conectar_selecao = load_Image(opcao,screen);

    opcao = "source/GameFeatures/Jogar/images/aguardando_cliente.png";
    SDL_Surface *aguarda_cliente = load_Image(opcao,screen);


    BlitImage(screen,escolher,0,0);
    SDL_Flip(screen);
    Vetor_mouse *vetor = new Vetor_mouse;
	play_music(musica_tela_de_opcoes);

    start = 0;

    while(1){
        start = SDL_GetTicks();
        vetor = get_Input();

        if(compara_selecao(496, 710, vetor->x, 358, 383, vetor->y)){
            BlitImage(screen,escolher,0,0);
            BlitImage(screen, criar_selecao, 496, 358);
            SDL_Flip(screen);
            if(vetor->click == 1){
                cout<<"cliquei em servidor"<<endl;
                BlitImage(screen,aguarda_cliente,0,0);
                SDL_Flip(screen);
                criar_servidor();
                //fase1(screen,"servidor");
                escolha_mapa(screen);
            }

        }

            else if(compara_selecao(458, 750, vetor->x, 413, 435, vetor->y)){
                BlitImage(screen,escolher,0,0);
                BlitImage(screen, conectar_selecao, 458, 413);
                SDL_Flip(screen);
                if(vetor->click == 1){
                    cout << "cliquei em conectar" << endl;
                    //digitarnome(vetor, screen);
                    digitarip(vetor, screen);
                    char local[] = "localhost";
                    conectar(local);
                    fase1(screen,"cliente");
                }
            }
                else if(compara_selecao(580, 630, vetor->x, 311, 381, vetor->y)){
                    if(vetor->click == 1){
                        Mix_CloseAudio();
                        //load_menu(screen);
                    }

                }
                SDL_Flip(screen);

        if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
            SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
        }

    }
}

void escolha_mapa(SDL_Surface *screen){

    string opcao = "source/GameFeatures/Jogar/images/escolha_mapa.png";
    SDL_Surface *maps = load_Image (opcao, screen);

    opcao = "source/GameFeatures/Jogar/images/criar_partida_selecionado.png";
    SDL_Surface *partida_selecionado = load_Image (opcao, screen);

    opcao = "source/GameFeatures/Jogar/images/entrar-partida_selecionado.png";
    SDL_Surface *entrar_selecionado = load_Image (opcao, screen);

    opcao = "source/GameFeatures/Jogar/images/pais_selecionado.png";
    SDL_Surface *pais_selecionado = load_Image (opcao, screen);



    BlitImage(screen,maps,0,0);
    SDL_Flip(screen);
    Vetor_mouse *vetor = new Vetor_mouse;

    start = 0;

    while(1){
        start = SDL_GetTicks();
        vetor = get_Input();
        ///Fase1
        if(compara_selecao(77, 223, vetor->x, 333, 499, vetor->y)){
            BlitImage(screen,maps,0,0);
            BlitImage(screen,pais_selecionado,77,378);
            SDL_Flip(screen);
            if(vetor->click == 1){
                fase1(screen,"servidor");
            }
        }   ///Fase2
            else if(compara_selecao(253, 397, vetor->x, 333, 499, vetor->y)){
                BlitImage(screen,maps,0,0);
                BlitImage(screen,pais_selecionado,250,378);
                SDL_Flip(screen);
                if(vetor->click == 1){
                    fase2(screen,"servidor");
                }
            }

                ///Fase3
                else if(compara_selecao(438, 580, vetor->x, 333, 499, vetor->y)){
                    BlitImage(screen,maps,0,0);
                    BlitImage(screen,pais_selecionado,433,378);
                    SDL_Flip(screen);
                    if(vetor->click == 1){
                        //fase1(screen,"servidor");
                    }
                }
                    ///Fase4
                    else if(compara_selecao(673, 819, vetor->x, 333, 499, vetor->y)){
                        BlitImage(screen,maps,0,0);
                        BlitImage(screen,pais_selecionado,673,378);
                        SDL_Flip(screen);
                        if(vetor->click == 1){
                            //fase1(screen,"servidor");
                        }
                    }
                        ///Fase5
                        else if(compara_selecao(952, 1097, vetor->x, 333, 499, vetor->y)){
                            BlitImage(screen,maps,0,0);
                            BlitImage(screen,pais_selecionado,952,378);
                            SDL_Flip(screen);
                            if(vetor->click == 1){
                                //fase1(screen,"servidor");
                            }
                        }
                        ///Voltar
                            else if(compara_selecao(952, 1097, vetor->x, 333, 499, vetor->y)){
                                BlitImage(screen,maps,0,0);
                                BlitImage(screen,partida_selecionado,952,333);
                                SDL_Flip(screen);
                                if(vetor->click == 1){
                                    break;
                                }

                            }
                                ///Iniciar partida
                                else if(compara_selecao(952, 1097, vetor->x, 333, 499, vetor->y)){
                                }
        frame_delay(start);
    }

}


void digitarip(Vetor_mouse *vetor, SDL_Surface *screen){
    int xinicial = 410;
    int yinicial = 248;

    string opcao = "source/GameFeatures/Jogar/images/digitarip.png";
    SDL_Surface *maps = load_Image (opcao, screen);
    BlitImage(screen,maps,0,0);

    opcao = "source/GameFeatures/Jogar/images/estou_pronto_selecionado.png";
    SDL_Surface *pronto_selecionado = load_Image (opcao, screen);

    opcao = "source/GameFeatures/Jogar/images/voltar_selecionado.png";
    SDL_Surface *voltar_selecionado = load_Image (opcao, screen);

    SDL_Flip(screen);

    string texto_ip;

    while(1){

        start = SDL_GetTicks();
        vetor = get_Input();
        string texto;

        if(compara_selecao(815, 1040, vetor->x, 599, 620, vetor->y)){
        cout<<"entrei aqui"<<endl;
            BlitImage(screen,maps,0,0);
            BlitImage(screen,pronto_selecionado,813,597);
            SDL_Flip(screen);
            if(vetor->click == 1){
            const char *local = texto_ip.c_str();
            char *vai = (char *) local;
            conectar(vai);

            fase1(screen,"cliente");
            }
        }
            else if(compara_selecao(640, 757, vetor->x, 600, 6222, vetor->y)){
                BlitImage(screen,maps,0,0);
                BlitImage(screen,voltar_selecionado,638,596);
                SDL_Flip(screen);
            }
            switch(vetor->number){

                case 0:
                    texto = "0";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 1:
                    //cout << "entrei em digitar ip " << vetor->number << endl;
                    texto = "1";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 2:
                    texto = "2";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 3:
                    texto = "3";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 4:
                    texto = "4";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 5:
                    texto = "5";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 6:
                    texto = "6";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 7:
                    texto = "7";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 8:
                    texto = "8";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 9:
                    texto = "9";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 10:
                    texto = ".";
                    desenha_texto(texto, screen, xinicial, yinicial, 40);
                    xinicial = xinicial + 30;
                    SDL_Flip(screen);
                    break;
                case 38:
                xinicial = xinicial - 30;
                texto = " ";
                desenha_texto(texto, screen, xinicial, yinicial, 40);
                SDL_Flip(screen);
                break;
                default:
                    break;
        }

        frame_delay(start);
        texto_ip.append(texto);

        //cout<<"texto: "<<texto<<endl;
        texto.clear();
        //cout<<"texto_novo: "<<texto_ip<<endl;
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
