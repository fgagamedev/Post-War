#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "../../include/sound.h"


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

	musica_tela_de_abertura = carregarMus("sounds/sound_track/tela_de_abertura.ogg");
	musica_tela_de_opcoes = carregarMus("sounds/sound_track/tela_de_opcoes.ogg");
	musica_creditos = carregarMus("sounds/sound_track/creditos.ogg");
	efeito_click = carregarSom("sounds/sounds_effects/click.ogg");
	efeito_selecao_cancelar = carregarSom("sounds/sounds_effects/selecao_cancelar.ogg");
}

//- carrega efeito sonoro
Mix_Chunk *carregarSom(const char *nome){

	Mix_Chunk *som = Mix_LoadWAV(nome);
	if(!som)
		printf("ERRO CARREGAR EFEITO SONORO> arquivo:'%s'\n",nome);
	return som;
}

//- carrega fundo musical
Mix_Music *carregarMus(const char *nome){

	Mix_Music *mus = Mix_LoadMUS(nome);
	if(!mus)
		printf("ERRO CARREGAR MUSICA> arquivo:'%s'\n",nome);
	return mus;
}

void descarregar(){

	Mix_FreeMusic(musica_tela_de_abertura);
	Mix_FreeMusic(musica_tela_de_opcoes);
	Mix_FreeMusic(musica_creditos);
	Mix_FreeChunk(efeito_click);
	Mix_FreeChunk(efeito_selecao_cancelar);
}

//- play/pause fundo musical -//
void play_music(struct _Mix_Music *nome_da_musica){
	
	if( Mix_PlayMusic(nome_da_musica, -1) == -1 ) //- play música
		printf("ERRO TOCAR MUSICA> Mix_PlayMusic\n");
}

//- toca um efeito sonoro -//
void play_effect(struct Mix_Chunk *nome_do_efeito){
	if(Mix_PlayChannel(-1, nome_do_efeito, 0) == -1)
		printf("ERRO TOCAR EFEITO SONORO> Efeito\n");
}

