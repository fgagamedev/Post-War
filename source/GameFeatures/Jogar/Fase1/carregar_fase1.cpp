#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;

SDL_Surface *mapa1;


void mapeia_hexagono(SDL_Surface *screen){

 SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

    int ia=0;
    int ja=124;
    int ie=44;
    int je=136;
    int contador=0;
    while(ja<500){
        vector <Hexagono *> hex_temp;
        for(ia=35, ie=44;ia<1050;ia+=68,ie+=68 ){

            //drawCircle(screen, 20, ie, je, blue);
            //BlitImage(screen,unidades_azul[0]->nome,ia,ja);
            //drawCircle(screen, 20, ie, je, blue);
            Hexagono *hexagon = new Hexagono;
            hexagon->centro_x = ie;
            hexagon->centro_y = je;
            hexagon->raio = 20;
            hexagon->x = ia;
            hexagon->y = ja;
            hexagon->indice = contador;
            hex_temp.push_back(hexagon);
            contador++;
        }
        hexagonos.push_back(hex_temp);
        ja+=19;
        je+=20;
        vector <Hexagono *> hex_temp2;
        for(ia=65,ie=78;ia<1050;ia+=68,ie+=68){

            //BlitImage(screen,unidades_azul[0]->nome,ia,ja);
            //drawCircle(screen, 20, ie, je, blue);
            Hexagono *hexagon = new Hexagono;
            hexagon->x = ia;
            hexagon->y = ja;
            hexagon->indice = contador;
            hex_temp2.push_back(hexagon);
            contador++;
        }
        hexagonos.push_back(hex_temp2);
        ja+=20;
        je+=20;
    }

}


void carregar_fase1(SDL_Surface *screen, string pais_serv,string pais_client){



    Unidade *unit;

    string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/malha.png";
    SDL_Surface *malha = load_Image(caminho, screen);
    BlitImage(screen,malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/FundoHUD.png";
    mapa1 = load_Image(caminho, screen);
    BlitImage(screen, mapa1, 0, 0);

    mapeia_hexagono(screen);

    if(strcmp("china","china") == 0){
        string escolha = "servidor";
        carrega_china(screen,escolha);
    }

    if(strcmp("eua","eua")==0){
        string escolha = "cliente";
        carrega_eua(screen,escolha);
    }
/*
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
        BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[i][j]->x,hexagonos[i][j]->y);
        cout<<hexagonos[i][j]->indice<<" ";
        }
        cout<<endl;
    }*/




    SDL_Flip(screen);
}

