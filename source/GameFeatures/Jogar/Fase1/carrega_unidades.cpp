#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

vector <Unidade *> unidades_azul;
vector <Unidade *> unidades_vermelhas;
vector< vector <Hexagono*> > hexagonos;
SDL_Rect cutBox = { 32, 0, 32, 32};


void setar_soldado(Unidade *soldado, string cor,string tipo,SDL_Surface *nome, SDL_Surface *ataque, SDL_Surface *ataque_baixo, SDL_Surface *ataque_cima){
    soldado->hp = 200;
    soldado->atk = 100;
    soldado->def = 100;
    soldado->alcance = 1;
    soldado->ouro = 100;
    soldado->cor = cor;
    soldado->nome = nome;
    soldado->ataque = ataque;
    soldado->ataque_baixo = ataque_baixo;
    soldado->ataque_cima = ataque_cima;
    soldado->tipo = tipo;

}

void setar_helicoptero(Unidade *helicoptero, string cor, string tipo, SDL_Surface *nome, SDL_Surface *ataque, SDL_Surface *ataque_baixo, SDL_Surface *ataque_cima){
    helicoptero->hp = 300;
    helicoptero->atk = 400;
    helicoptero->def = 200;
    helicoptero->alcance = 4;
    helicoptero->ouro = 400;
    helicoptero->cor = cor;
    helicoptero->nome = nome;
    helicoptero->ataque = ataque;
    helicoptero->ataque_baixo = ataque_baixo;
    helicoptero->ataque_cima = ataque_cima;
    helicoptero->tipo = tipo;
}

void setar_metralhadora(Unidade *metralhadora, string cor, string tipo,SDL_Surface *nome, SDL_Surface *ataque){
    metralhadora->hp = 100;
    metralhadora->atk = 200;
    metralhadora->def = 300;
    metralhadora->alcance = 3;
    metralhadora->ouro = 200;
    metralhadora->cor = cor;
    metralhadora->nome = nome;
    metralhadora->ataque = ataque;
    metralhadora->ataque_baixo = ataque;
    metralhadora->ataque_cima = ataque;
    metralhadora->tipo = tipo;
}

void setar_tanque(Unidade *tanque, string cor, string tipo, SDL_Surface *nome, SDL_Surface *ataque, SDL_Surface *ataque_baixo, SDL_Surface *ataque_cima){
    tanque->hp = 400;
    tanque->atk = 300;
    tanque->def = 400;
    tanque->alcance = 2;
    tanque->ouro = 300;
    tanque->cor = cor;
    tanque->nome = nome;
    tanque->ataque = ataque;
    tanque->ataque_baixo = ataque_baixo;
    tanque->ataque_cima = ataque_cima;
    tanque->tipo = tipo;
}

void setar_quartel(Unidade *quartel, string cor, string tipo, SDL_Surface *nome, SDL_Surface *ataque){
    quartel->hp = 1000;
    quartel->atk = 0;
    quartel->def = 400;
    quartel->alcance = 0;
    quartel->ouro = 0;
    quartel->cor = cor;
    quartel->nome = nome;
    quartel->ataque = ataque;
    quartel->ataque_baixo = ataque;
    quartel->ataque_cima = ataque;
    quartel->tipo = tipo;
}

void carrega_china(SDL_Surface *screen,string lado){

    string lado1("servidor");
    string cor = "vermelho";
    int k;
    for(int i=0, j=1;i<10;i++,j+=30){
        k=i;
        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
        SDL_Surface *ataque_soldado = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        string unidadea1 = "soldado";
        setar_soldado(soldado, cor, unidadea1, soldado1, ataque_soldado, ataque_baixo, ataque_cima);
        unidades_azul.push_back(soldado);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst = {hexagonos[i*2][3]->x, hexagonos[i*2][3]->y, 0, 0};
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;

        caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul.png";
        SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
        Unidade *quartel_a = new Unidade();
        string quarte = "quartel";
        setar_quartel(quartel_a,cor,quarte,quartel_azul_cabana, quartel_azul_cabana);
        BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);
        hexagonos[6][1]->unidade = quartel_a;
        hexagonos[6][1]->contem_unidade = 1;

    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
    SDL_Surface *metralhadora1 = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_ataque.png";
    SDL_Surface *metralhadora_ataque = load_Image(caminho, screen);
    Unidade *metralhadora = new Unidade();
    string unidadea2 = "metralhadora";
    setar_metralhadora(metralhadora, cor, unidadea2, metralhadora1, metralhadora_ataque);
    unidades_azul.push_back(metralhadora);

    BlitImage(screen,unidades_azul[10]->nome,hexagonos[6][4]->x,hexagonos[6][4]->y);
    hexagonos[6][4]->contem_unidade=1;
    hexagonos[6][4]->unidade = metralhadora;

    SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	//drawCircle(screen, 20, 44, 137, blue);
	//drawCircle(screen, 20, 78, 157, blue);
}

void carrega_eua(SDL_Surface *screen,string lado){

    string lado2("cliente");
    string cor2 = "azul";

    for(int i=0;i<3;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque.png";
        SDL_Surface *soldado_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_baixo.png";
        SDL_Surface *soldado_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_cima.png";
        SDL_Surface *soldado_ataque_cima = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        string unidade = "soldado";
        setar_soldado(soldado, cor2, unidade, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima);
        unidades_vermelhas.push_back(soldado);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_movimentacao_esqueda.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul.png";
        SDL_Surface *helicoptero_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_baixo.png";
        SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_cima.png";
        SDL_Surface *helicoptero_ataque_cima = load_Image(caminho, screen);
        //caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_ataque_baixo.png";
        //SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        string unidade1 = "helicoptero";
        setar_helicoptero(helicoptero, cor2, unidade1, helicoptero1, helicoptero_ataque, helicoptero_ataque_baixo, helicoptero_ataque_cima);
        unidades_vermelhas.push_back(helicoptero);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_azul_ataque.png";
        SDL_Surface *metrapalhadora_ataque = load_Image(caminho, screen);
        Unidade *metralhadora = new Unidade();
        string unidade2 = "metralhadora";
        setar_metralhadora(metralhadora, cor2, unidade2, metrapalhadora1, metrapalhadora_ataque);
        unidades_vermelhas.push_back(metralhadora);
    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_esquerda1.png";
    SDL_Surface *tanque1 = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque.png";
    SDL_Surface *tanque_ataque = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_baixo.png";
    SDL_Surface *tanque_ataque_baixo = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_cima.png";
    SDL_Surface *tanque_ataque_cima = load_Image(caminho, screen);
    Unidade *tanque = new Unidade();
    string unidade3 = "tanque";
    setar_tanque(tanque, cor2, unidade3, tanque1, tanque_ataque, tanque_ataque_baixo, tanque_ataque_cima);
    unidades_vermelhas.push_back(tanque);

    SDL_Rect dst = {hexagonos[2][12]->x, hexagonos[2][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[0]->nome, &cutBox,  screen, &dst);
    //BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
    hexagonos[2][12]->unidade = unidades_vermelhas[0];
    hexagonos[2][12]->contem_unidade = 1;
    unidades_vermelhas[0]->x = hexagonos[2][12]->x;
    unidades_vermelhas[0]->y = hexagonos[2][12]->y;

    SDL_Rect d = {hexagonos[4][12]->x, hexagonos[4][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[1]->nome, &cutBox,  screen, &d);
    //BlitImage(screen,unidades_vermelhas[1]->nome,hexagonos[4][12]->x,hexagonos[4][12]->y);
    hexagonos[4][12]->unidade = unidades_vermelhas[1];
    hexagonos[4][12]->contem_unidade = 1;
    unidades_vermelhas[1]->x = hexagonos[4][12]->x;
    unidades_vermelhas[1]->y = hexagonos[4][12]->y;

    SDL_Rect ds = {hexagonos[6][12]->x, hexagonos[6][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[2]->nome, &cutBox,  screen, &ds);
    //BlitImage(screen,unidades_vermelhas[2]->nome,hexagonos[6][12]->x,hexagonos[6][12]->y);
    hexagonos[6][12]->unidade = unidades_vermelhas[2];
    hexagonos[6][12]->contem_unidade = 1;
    unidades_vermelhas[2]->x = hexagonos[6][12]->x;
    unidades_vermelhas[2]->y = hexagonos[6][12]->y;

    SDL_Rect ds1 = {hexagonos[8][12]->x, hexagonos[8][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[3]->nome, &cutBox,  screen, &ds1);
    hexagonos[8][12]->unidade = unidades_vermelhas[3];
    hexagonos[8][12]->contem_unidade = 1;
    unidades_vermelhas[3]->x = hexagonos[8][12]->x;
    unidades_vermelhas[3]->y = hexagonos[8][12]->y;

    SDL_Rect ds2 = {hexagonos[10][12]->x, hexagonos[10][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[4]->nome, &cutBox,  screen, &ds2);
    hexagonos[10][12]->unidade = unidades_vermelhas[4];
    hexagonos[10][12]->contem_unidade = 1;
    unidades_vermelhas[4]->x = hexagonos[10][12]->x;
    unidades_vermelhas[4]->y = hexagonos[10][12]->y;

    BlitImage(screen,unidades_vermelhas[5]->nome,hexagonos[14][12]->x,hexagonos[14][12]->y);
    hexagonos[14][12]->unidade = unidades_vermelhas[5];
    hexagonos[14][12]->contem_unidade = 1;
    unidades_vermelhas[5]->x = hexagonos[14][12]->x;
    unidades_vermelhas[5]->y = hexagonos[14][12]->y;

    BlitImage(screen,unidades_vermelhas[6]->nome,hexagonos[6][14]->x,hexagonos[6][14]->y);
    hexagonos[6][14]->unidade = unidades_vermelhas[6];
    hexagonos[6][14]->contem_unidade = 1;
    unidades_vermelhas[6]->x = hexagonos[6][14]->x;
    unidades_vermelhas[6]->y = hexagonos[14][12]->y;

    BlitImage(screen,unidades_vermelhas[7]->nome,hexagonos[7][10]->x,hexagonos[7][10]->y);
    hexagonos[7][10]->unidade = unidades_vermelhas[7];
    hexagonos[7][10]->contem_unidade = 1;
    unidades_vermelhas[7]->x = hexagonos[7][10]->x;
    unidades_vermelhas[7]->y = hexagonos[7][10]->y;

           // cout<<"i: "<<i<<unidades_vermelhas[i]->tipo<<endl;

        /*unidades_vermelhas[i]->x = hexagonos[i][j]->x;
        unidades_vermelhas[i]->y =hexagonos[i][j]->y;*/
    }









