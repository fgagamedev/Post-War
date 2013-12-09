#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"
#include "../../../source/GameFeatures/audio.cpp"


Mix_Music *musica_tela_de_abertura;
Mix_Music *musica_tela_de_opcoes;
Mix_Music *musica_creditos;
Mix_Chunk *efeito_click;
Mix_Chunk *efeito_selecao_cancelar;


void init();
void carregar();
Mix_Chunk *carregarSom(const char *nome);
Mix_Music *carregarMus(const char *nome);
void descarregar();
void play_music(struct _Mix_Music *nome_da_musica);
void play_effect(struct Mix_Chunk *nome_do_efeito);

int start;
int FPS=100;

void load_menu(SDL_Surface *screen){

    SDL_Surface *jogar_selecionado;
    SDL_Surface *creditos_selecionado;
    SDL_Surface *sair_selecionado;
    SDL_Surface *estatisticas_selecionado;
    SDL_Surface *opcoes_selecionado;

    //carregando imagens
    string path_jogo = "source/GameFeatures/Menu/Images/jogar_selecionado.png";
    jogar_selecionado = load_Image(path_jogo,screen);

    string path_estatisticas = "source/GameFeatures/Menu/Images/estatisticas_selecionado.png";
    estatisticas_selecionado = load_Image(path_estatisticas, screen);

    string path_creditos = "source/GameFeatures/Menu/Images/creditos_selecionado.png";
    creditos_selecionado = load_Image(path_creditos, screen);

    string path_sair = "source/GameFeatures/Menu/Images/sair_selecionado.png";
    sair_selecionado = load_Image(path_sair, screen);

    string path_opcoes = "source/GameFeatures/Menu/Images/opcoes_selecionado.png";
    opcoes_selecionado = load_Image(path_opcoes, screen);

    string path = "source/GameFeatures/Menu/Images/menu.png";
    SDL_Surface *menu = load_Image(path, screen);

	//Tocando a musica
	init();
	carregar();
	play_music(musica_tela_de_abertura);


    BlitImage(screen, menu, 0, 0);
    SDL_Flip(screen);
    Vetor_mouse *vetor = new Vetor_mouse;
    int cont=0;
    start = 0;
    while(1){
        start = SDL_GetTicks();
        cont++;
        vetor = get_Input();
        BlitImage(screen, menu, 0, 0);
        //cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        //cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(478.5,731.5,vetor->x,211,275,vetor->y)){
            BlitImage(screen, jogar_selecionado, 478.5, 211);
            SDL_Flip(screen);

            if(vetor->click == 1){
				play_effect(efeito_click);
				Mix_HaltMusic();
                inicio(screen);
            }
        }

            else if(compara_selecao(450,798,vetor->x,311,375,vetor->y)){
                BlitImage(screen, opcoes_selecionado, 450.0, 311);
                SDL_Flip(screen);
                if(vetor->click == 1){
					play_effect(efeito_click);
                }
            }
                    else if(compara_selecao(355,798,vetor->x,417,475,vetor->y)){
                            BlitImage(screen, estatisticas_selecionado, 355.0, 411);
                            SDL_Flip(screen);

                            if(vetor->click == 1){
								play_effect(efeito_click);
                            }
                    }

                        else if(compara_selecao(425,798,vetor->x,511,575,vetor->y)){
                            BlitImage(screen, creditos_selecionado, 425.0, 511);
                            SDL_Flip(screen);

                            if(vetor->click == 1){
                                play_effect(efeito_click);
                                creditos(screen);
                            }
                        }

                                else if(compara_selecao(350,798,vetor->x,611,675,vetor->y)){
                                    BlitImage(screen, sair_selecionado, 350.0, 611);
                                    SDL_Flip(screen);

                                    if(vetor->click == 1){
										play_effect(efeito_click);
										descarregar();
                                        Mix_CloseAudio();
                                        SDL_Quit();
                                        exit(0);
                                    }
                                }



        //SDL_Delay(10);
        if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
            SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
        }
    }





}


void clica_menu_menor(SDL_Surface *screen){
        BlitImage(screen,menu_menor,488,200);
        SDL_Flip(screen);
        int start = 0;
        Vetor_mouse *vetor = new Vetor_mouse();
        while(1){
            vetor = get_Input();
            start = SDL_GetTicks();
            if(compara_selecao(500,771,vetor->x,225,271,vetor->y)){
                cout<<"era pra eu sair"<<endl;
                //BlitImage(screen,voltar_jogo_sel,570,700);
                BlitImage(screen,voltar_jogo_sel,500,225);
                SDL_Flip(screen);
                if(vetor->click == 1){
                    blit_tela(screen,0);
                    break;

                }
            }

                else if(compara_selecao(520,771,vetor->x,275,271,vetor->y)){
                    cout<<"era pra eu sair"<<endl;
                    //BlitImage(screen,voltar_jogo_sel,570,700);
                    BlitImage(screen,opcoes_sel,520,275);
                    SDL_Flip(screen);
                    if(vetor->click == 1){

                    }
                }
            }

            BlitImage(screen,menu_menor,488,200);

            if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
                //SDL_Flip(screen);

            }

            SDL_Flip(screen);

    }
