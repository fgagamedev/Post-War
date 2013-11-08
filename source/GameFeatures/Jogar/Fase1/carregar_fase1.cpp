#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

void carregar_fase1(SDL_Surface *screen,){

    Unidade *unit;

    string mapa = "source/GameFeatures/Jogar/Fase1/bryjstudios_mapa_final_v2.png";
    SDL_Surface *mapa1 = load_Image(mapa, screen);
    unit = new Unidade();
    unit

    string soldadoazul_direita1 = "unidade_azul_direita1.png";
    SDL_Surface *soldado1 = load_Image(soldadoazul_direita1, screen);


    string soldadoinimigo = "";
    SDL_Surface *soldado2 = load_Image(soldadoinimigo, screen);


    string helicopteroamigo = "";
    SDL_Surface *helicoptero1 = load_Image(helicopteroamigo, screen);


    string helicopteroinimigo = "";
    SDL_Surface *helicoptero2 = load_Image(helicopteroinimigo, screen);


    string tanqueamigo = "";
    SDL_Surface *tanque1 = load_Image(tanqueamigo, screen);


    string tanqueinimigo = "";
    SDL_Surface *tanque2 = load_Image(tanqueinimigo, screen);


    string quartelamigo = "";
    SDL_Surface *quartel1 = load_Image(quartelamigo, screen);


    string quartelinimigo = "";
    SDL_Surface *quartel2 = load_Image(quartelinimigo, screen);


    string  grid1 = "";
    SDL_Surface *grid = load_Image(grid1,screen);


    string metralhador= "";
    SDL_Surface *metralhadora = load_Image(metralhador,screen);




}
