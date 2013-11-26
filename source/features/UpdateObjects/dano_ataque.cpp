#include <iostream>
#include <string>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void dano_ataque(){

    //inicializa o random
    srand (time(NULL));

    int rand_defensor = rand() % 100 + 50;
    int rand_atacante = rand() % 100 + 60;
    cout << "rand_defensor:" << rand_defensor << endl;
    cout << "rand_atacante:" << rand_atacante << endl;

    Unidade *atacante = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
    Unidade *defensor = hexagonos[hex_selecao->i][hex_selecao->j]->unidade;

    int dano_no_atacante = ((((2*100/5+2) * defensor->atk/ atacante->def) / 50) + 2)*(rand_defensor/100)*30;
    int dano_no_defensor = ((((2*100/5+2) * atacante->atk/ defensor->def) / 50) + 2)*(rand_atacante/100)*30;
    cout << "dano no atacante:" << dano_no_atacante << endl;;
    cout << "dano no defensor:" << dano_no_defensor << endl;;
    atacante->hp -= dano_no_atacante;
    defensor->hp -= dano_no_defensor;
    cout << "atacante hp:" << atacante->hp << endl;
    cout << "defensor hp:" << defensor->hp << endl;

    hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade->hp = atacante->hp;
    hexagonos[hex_selecao->i][hex_selecao->j]->unidade->hp = defensor->hp;

    if(hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade->hp <= 0){
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade = NULL;
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade = 0;
    }
    if(hexagonos[hex_selecao->i][hex_selecao->j]->unidade->hp <= 0){
        hexagonos[hex_selecao->i][hex_selecao->j]->unidade = NULL;
        hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade = 0;
    }


}
