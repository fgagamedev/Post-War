#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

vector <Unidade *> unidades_azul;
vector <Unidade *> unidades_vermelhas;

void setar_soldado(Unidade *soldado, char cor[],char tipo[],SDL_Surface *nome){
    soldado->hp = 200;
    soldado->atk = 100;
    soldado->def = 100;
    soldado->alcance = 1;
    soldado->ouro = 100;
    soldado->cor = cor;
    soldado->nome = nome;
}

void setar_helicoptero(Unidade *helicoptero, char cor[], char tipo[], SDL_Surface *nome){
    helicoptero->hp = 300;
    helicoptero->atk = 400;
    helicoptero->def = 200;
    helicoptero->alcance = 4;
    helicoptero->ouro = 400;
    helicoptero->cor = cor;
    helicoptero->nome = nome;
}

void setar_metralhadora(Unidade *metralhadora, char cor[], char tipo[],SDL_Surface *nome){
    metralhadora->hp = 100;
    metralhadora->atk = 200;
    metralhadora->def = 300;
    metralhadora->alcance = 3;
    metralhadora->ouro = 200;
    metralhadora->cor = cor;
    metralhadora->nome = nome;
}

void setar_tanque(Unidade *tanque, char cor[], char tipo[], SDL_Surface *nome){
    tanque->hp = 400;
    tanque->atk = 300;
    tanque->def = 400;
    tanque->alcance = 2;
    tanque->ouro = 300;
    tanque->cor = cor;
    tanque->nome = nome;
}

void carrega_china(SDL_Surface *screen,string lado){

    string lado1("servidor");
    char cor[100] = "azul";
    for(int i=0, j=1;i<10;i++,j+=30){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        char unidade[100] = "soldado";
        setar_soldado(soldado, cor, unidade, soldado1);
        unidades_azul.push_back(soldado);
    }


    string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
    SDL_Surface *metralhadora1 = load_Image(caminho, screen);
    Unidade *metralhadora = new Unidade();
    char tipo[100] = "metralhadora";
    setar_metralhadora(metralhadora, cor, tipo, metralhadora1);
    unidades_azul.push_back(metralhadora);


    for(int i=0, j =1;i<11;i++,j+=30){
            BlitImage(screen,unidades_azul[i]->nome,i+200,j+150);

    }

}

void carrega_eua(SDL_Surface *screen,string lado){

    string lado2("cliente");
    char cor[100] = "vermelha";

    for(int i=0;i<3;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_vermelha_esquerda1.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        char unidade[100] = "soldado";
        setar_soldado(soldado, cor, unidade, soldado1);
        unidades_vermelhas.push_back(soldado);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_vermelha_esquerda1.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        char unidade[100] = "helicoptero";
        setar_helicoptero(helicoptero, cor, unidade, helicoptero1);
        unidades_vermelhas.push_back(helicoptero);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        Unidade *metralhadora = new Unidade();
        char unidade[100] = "metralhadora";
        setar_metralhadora(metralhadora, cor, unidade, metrapalhadora1);
        unidades_vermelhas.push_back(metralhadora);
    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_vermelha_esquerda1.png";
    SDL_Surface *tanque1 = load_Image(caminho, screen);
    Unidade *tanque = new Unidade();
    char unidade[100] = "tanque";
    setar_tanque(tanque, cor, unidade, tanque1);
    unidades_vermelhas.push_back(tanque);


    for(int i=0, j=1;i<5;i++,j+=30){
            BlitImage(screen,unidades_vermelhas[i]->nome,i+800,j+150);
            unidades_vermelhas[i]->x = i+800;
            unidades_vermelhas[i]->y = j+150;

    }

      for(int i=5, j=1;i<8;i++,j+=60){
            BlitImage(screen,unidades_vermelhas[i]->nome,i+900,j+200);

    }
}
