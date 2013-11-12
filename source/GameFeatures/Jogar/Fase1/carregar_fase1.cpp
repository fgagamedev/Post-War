#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void carregar_fase1(SDL_Surface *screen, string pais_serv,string pais_client){

    Unidade *unit;

    string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);



    caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_mapa_final_sv2.png";
    SDL_Surface *mapa1 = load_Image(caminho, screen);
    BlitImage(screen, mapa1, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
    SDL_Surface *sold = load_Image(caminho, screen);
    BlitImage(screen, sold, 600, 500);

    caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_vermelha_esquerda1.png";
    SDL_Surface *sold2 = load_Image(caminho, screen);
    BlitImage(screen, sold2, 700, 450);
    BlitImage(screen, sold2, 700, 350);
    BlitImage(screen, sold2, 700, 250);



    SDL_Flip(screen);

    SDL_Delay(10000);
/*
    caminho = "source/GameFeatures/Jogar/Fase1/images/FundoHUD.png";
    cout<<"caminho:" << caminho<<endl;
    SDL_Surface *hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);
    */


    if(strcmp("china","china") == 0){
        string escolha = "servidor";
        carrega_china(screen,escolha);
    }

    if(strcmp("eua","eua")==0){
        string escolha = "cliente";
        carrega_eua(screen,escolha);
    }


/*
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


    */

}
