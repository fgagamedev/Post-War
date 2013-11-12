#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void setar_soldado(Unidade *soldado, char cor[],char tipo[]){
    soldado->hp = 200;
    soldado->atk = 100;
    soldado->def = 100;
    soldado->alcance = 1;
    soldado->ouro = 100;
    soldado->cor = cor;
}

void carrega_china(SDL_Surface *screen,string lado){

    string lado1("servidor");

    if(lado.compare(lado1)==0){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
        SDL_Surface *loading = load_Image(caminho, screen);
        BlitImage(screen, loading, 0, 0);
    }

    for(int i=0;i<10;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        char cor[100] = "azul";
        char unidade[100] = "soldado";
        setar_soldado(soldado,cor,unidade);
    }


}

void carrega_eua(SDL_Surface *screen,string lado){

    string lado2("cliente");

    if(lado.compare(lado2)==0){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
        SDL_Surface *loading = load_Image(caminho, screen);
        BlitImage(screen, loading, 0, 0);
    }

        for(int i=0;i<3;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_vermelha_esquerda1.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        char cor[100] = "vermelha";
        char unidade[100] = "soldado";
        setar_soldado(soldado,cor,unidade);
    }





}
