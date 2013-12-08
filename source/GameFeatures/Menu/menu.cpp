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


Mix_Music *musica_tela_de_abertura;
Mix_Music *musica_tela_de_opcoes;
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
const int FPS=100;

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
        if((SDL_GetTicks() - start) < (1000/FPS)){
            SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
        }
    }


}


//- inicializa a SDL e SDL_Mix
void init(){
	Uint16 audio_format = AUDIO_S16SYS;

	//Initialize SDL_mixer
	if( Mix_OpenAudio(22050, audio_format, 2, 4096) < 0){
		printf("Mix_OpenAudio> %s\n", Mix_GetError());
		exit(1);
	}
	atexit(Mix_CloseAudio);
}

//- carrega todos os arquivos (musicas, sons...)
void carregar(){

	musica_tela_de_abertura = carregarMus("tela_de_abertura.wav");
	musica_tela_de_opcoes = carregarMus("tela_de_opcoes.wav");
	//musica_creditos = carregarMus("creditos.wav");
	efeito_click = carregarSom("selecao_ok.wav");
	efeito_selecao_cancelar = carregarSom("selecao_cancelar.wav");
}

//- carrega efeito sonoro
Mix_Chunk *carregarSom(const char *nome){

	Mix_Chunk *som = Mix_LoadWAV(nome);
	if(!som)
		printf("ERRO> arquivo:'%s'\n",nome);
	return som;
}

//- carrega fundo musical
Mix_Music *carregarMus(const char *nome){

	Mix_Music *mus = Mix_LoadMUS(nome);
	if(!mus)
		printf("ERRO> arquivo:'%s'\n",nome);
	return mus;
}

void descarregar(){

	Mix_FreeMusic(musica_tela_de_abertura);
	Mix_FreeMusic(musica_tela_de_opcoes);
	//Mix_FreeMusic(musica_creditos);
	Mix_FreeChunk(efeito_click);
	Mix_FreeChunk(efeito_selecao_cancelar);
}

//- play/pause fundo musical -//
void play_music(struct _Mix_Music *nome_da_musica){
	if( Mix_PlayingMusic() == 0 ){ //- sem música
		if( Mix_PlayMusic(nome_da_musica, -1) == -1 ) //- play música
			printf("ERRO> Mix_PlayMusic\n");
	}else{
		if( Mix_PausedMusic() == 1 ){ //- música pausada
			Mix_ResumeMusic(); //- continua tacando
		}else{
			Mix_PauseMusic(); //- pausar música
		}
	}
}

//- toca um efeito sonoro -//
void play_effect(struct Mix_Chunk *nome_do_efeito){
	if(Mix_PlayChannel(-1, nome_do_efeito, 0) == -1)
		printf("ERRO> Efeito\n");
}

