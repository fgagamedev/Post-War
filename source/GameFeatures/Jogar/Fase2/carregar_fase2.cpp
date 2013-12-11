#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase2(SDL_Surface *screen, char pais_serv[],char pais_client[]){


    hex_selecao = new Hex_selecao();

    string caminho = "source/GameFeatures/Jogar/Fase2/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase2/images/fase_2.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase2/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase2/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase2/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase2/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase2/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase2/images/fase_2_malha.png";
    com_malha = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase2/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase2/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagonos[19][3]->obstaculo =1;
    hexagonos[2][3]->obstaculo =1;
    hexagonos[5][4]->obstaculo =1;
    hexagonos[6][5]->obstaculo =1;
    hexagonos[5][7]->obstaculo =1;
    hexagonos[19][6]->obstaculo =1;
    hexagonos[3][10]->obstaculo =1;
    hexagonos[16][9]->obstaculo =1;
    hexagonos[19][10]->obstaculo =1;
    hexagonos[8][11]->obstaculo =1;
    hexagonos[9][10]->obstaculo =1;

        string escolha = "servidor";
        carrega_franca(screen,escolha);


        escolha = "cliente";
        carrega_uk(screen,escolha);
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

