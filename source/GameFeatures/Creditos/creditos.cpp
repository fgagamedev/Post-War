#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

using namespace std;

void RunImage(SDL_Surface *screen1, SDL_Surface *screen2, SDL_Surface *screen3){
 Vetor_mouse *vetor = new Vetor_mouse;
    while(1){
        for(int j = 680; j >= -680; j-=2){
            vetor = get_Input();
            if(vetor->number == 39){
                load_menu(screen1);
            }
            BlitImage(screen1, screen3, 0, 0);
            BlitImage(screen1, screen2, 0, j);
            SDL_Flip(screen1);
        }
        break;
    }

}

void creditos(SDL_Surface *screen){

    SDL_Surface *coisa = setup_video();

    string tela = "source/GameFeatures/Creditos/Images/fundo_creditos.png";
    SDL_Surface *telapreta = load_Image(tela, coisa);
    string imagem_bryj = "source/GameFeatures/Creditos/Images/logo_postwar.png";
    SDL_Surface *bryj = load_Image(imagem_bryj, coisa);
    string imagem_sdl = "source/GameFeatures/Creditos/Images/sdl_logo.png";
    SDL_Surface *sdl = load_Image(imagem_sdl, coisa);
    string imagem_ubuntu = "source/GameFeatures/Creditos/Images/ubuntu_logo.png";
    SDL_Surface *ubuntu = load_Image(imagem_ubuntu, coisa);
    string imagem_16 = "source/GameFeatures/Creditos/Images/nome_jogo.png";
    SDL_Surface *jogo_nome= load_Image(imagem_16, coisa);
    string creditos_path = "source/GameFeatures/Creditos/Images/nome_creditos.png";
    SDL_Surface *creditos= load_Image(creditos_path, coisa);

    //const char* musica_creditos = "creditos.ogg";

    //SDL_Thread *audio = SDL_CreateThread(testeaudio, (void*)musica_creditos);

    SDL_Flip(screen);

	play_music(musica_creditos);
    RunImage(coisa, creditos, telapreta);
    RunImage(coisa, bryj, telapreta);
    RunImage(coisa, sdl, telapreta);
    RunImage(coisa, ubuntu, telapreta);
    RunImage(coisa, jogo_nome, telapreta);

	descarregar();
	Mix_HaltMusic();
    Mix_CloseAudio();
    load_menu(screen);

}

