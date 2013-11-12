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
    metralhadora->hp = 100;
    metralhadora->atk = 200;
    metralhadora->def = 300;
    metralhadora->alcance = 3;
    metralhadora->ouro = 200;
    metralhadora->cor = cor;
}

void setar_tanque(Unidade *tanque, char cor[], char tipo[]){
    tanque->hp = 400;
    tanque->atk = 300;
    tanque->def = 400;
    tanque->alcance = 2;
    tanque->ouro = 300;
    tanque->cor = cor;
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

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        Unidade *metralhadora = new Unidade();
        char cor[100] = "vermelha";
        char unidade[100] = "metralhadora";
        setar_metralhadora(metralhadora, cor, unidade);
    }

     for (int i=0;i<=0;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_vermelha_esquerda1.png";
        SDL_Surface *tanque1 = load_Image(caminho, screen);
        Unidade *tanque = new Unidade();
        char cor[100] = "vermelha";
        char unidade[100] = "tanque";
        setar_tanque(tanque, cor, unidade);
    }



}
