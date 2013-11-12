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

void setar_helicoptero(Unidade *helicoptero, char cor[], char tipo[]){
    helicoptero->hp = 300;
    helicoptero->atk = 400;
    helicoptero->def = 200;
    helicoptero->alcance = 4;
    helicoptero->ouro = 400;
    helicoptero->cor = cor;
}

void setar_metralhadora(Unidade *metralhadora, char cor[], char tipo[]){
    helicoptero->hp = 100;
    helicoptero->atk = 200;
    helicoptero->def = 300;
    helicoptero->alcance = 3;
    helicoptero->ouro = 200;
    helicoptero->cor = cor;
}

void setar_tanque(Unidade *tanque, char cor[], char tipo[]){
    helicoptero->hp = 400;
    helicoptero->atk = 300;
    helicoptero->def = 400;
    helicoptero->alcance = 2;
    helicoptero->ouro = 300;
    helicoptero->cor = cor;
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
    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_vermelha_esquerda1.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        char cor[100] = "vermelha";
        char unidade[100] = "helicoptero";
        setar_helicoptero(helicoptero, cor, unidade);
    }



}
