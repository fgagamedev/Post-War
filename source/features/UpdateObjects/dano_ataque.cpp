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

    int rand_defensor = rand() % 50 + 30;
    int rand_atacante = rand() % 50 + 40;
    cout << "rand_defensor:" << rand_defensor << endl;
    cout << "rand_atacante:" << rand_atacante << endl;

    Unidade *atacante = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
    Unidade *defensor = hexagonos[hex_selecao->i][hex_selecao->j]->unidade;

    int dano_no_atacante = ((defensor->atk/atacante->def)+1)*(rand_defensor/2);
    int dano_no_defensor = ((atacante->atk/ defensor->def)+1)*(rand_atacante);

    atacante->hp -= dano_no_atacante;
    if(atacante->hp <= 0){
        atacante->hp  = 0;
    }
    defensor->hp -= dano_no_defensor;
    if(defensor->hp < 0){
        defensor->hp  = 0;
    }


    if(atacante->hp <= 0){
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade = NULL;
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade = 0;
        //free(hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade);
    }
    else{
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade->hp = atacante->hp;
    }
    cout << "passei do primeiro else" << endl;
    if(defensor->hp <= 0){
        hexagonos[hex_selecao->i][hex_selecao->j]->unidade = NULL;
        hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade = 0;
        //free(hexagonos[hex_selecao->i][hex_selecao->j]->unidade);
    }
    else{
        hexagonos[hex_selecao->i][hex_selecao->j]->unidade->hp = defensor->hp;
    }
    cout << "passei do segundo else" << endl;
}
