#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


using namespace std;

void inicio(SDL_Surface *screen){

    SDL_Surface *escolha = setup_video();

    string opcao = "source/GameFeatures/Jogar/images/conexao.png";
    SDL_Surface *escolher = load_Image(opcao, escolha);

    Vetor_mouse *vetor = new Vetor_mouse;

    while(1){

    vetor = get_Input();
    BlitImage(escolha, escolher, 0, 0);
    SDL_Flip(escolha);


    if(compara_selecao(560, 720, vetor->x, 111, 211, vetor->y)){

        if(vetor->click == 1){
            cout << "cliquei aqui" << endl;
        }


    }
    }





}
