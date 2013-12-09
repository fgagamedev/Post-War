#include <iostream>
#include <string>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

string derrotado = "branca";
void dano_ataque(){
    string tipoquartel = "quartel";
    //inicializa o random
    srand (time(NULL));

    string cor1 = "azul";
    string cor2 = "vermelho";

    int rand_defensor = rand() % 50 + 30;
    int rand_atacante = rand() % 50 + 40;


    Unidade *atacante = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
    Unidade *defensor = hexagonos[hex_selecao->i][hex_selecao->j]->unidade;

    if(atacante->tipo == tipoquartel){
        cout << "Unidade não pode atacar" << endl;
        return;
    }

    int dano_no_atacante = ((defensor->atk/atacante->def)+1)*(rand_defensor/2);
    int dano_no_defensor = ((atacante->atk/ defensor->def)+1)*(rand_atacante);
    cout << "dano no atacante:" << dano_no_atacante << endl;
    cout << "dano no defensor:" << dano_no_defensor << endl;
    atacante->hp -= dano_no_atacante;
    if(atacante->hp <= 0){
        atacante->hp  = 0;
    }
    defensor->hp -= dano_no_defensor;
    if(defensor->hp < 0){
        defensor->hp  = 0;
    }

    if(defensor->tipo == tipoquartel && defensor->hp == 0){
        cout << "defensor:" << defensor->cor << endl;
        derrotado = defensor->cor;
        cout << "derrotado:" << derrotado << endl;
    }
    cout << "atacante hp:" << atacante->hp << endl;
    cout << "defensor hp:" << defensor->hp << endl;


    if(atacante->hp <= 0){
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade = NULL;
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade = 0;
        //free(hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade);
    }
    else{
        hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade->hp = atacante->hp;
    }
    //cout << "passei do primeiro else" << endl;
    if(defensor->hp <= 0){
        if(defensor->tipo.compare("quartel") != 0){
            if(defensor->tipo.compare("metralhadora") != 0){
                hexagonos[hex_selecao->i][hex_selecao->j]->unidade = NULL;
                hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade = 0;
            }
                else if (defensor->cor == "azul"){
                    hexagonos[9][12]->unidade = NULL;
                    hexagonos[9][12]->contem_unidade = 0;
                    hexagonos[10][12]->unidade = NULL;
                    hexagonos[10][12]->contem_unidade = 0;
                    hexagonos[11][12]->unidade = NULL;
                    hexagonos[11][12]->contem_unidade = 0;
                    hexagonos[12][12]->unidade = NULL;
                    hexagonos[12][12]->contem_unidade = 0;
                    hexagonos[13][12]->unidade = NULL;
                    hexagonos[13][12]->contem_unidade = 0;
                }
                    else{
                        hexagonos[6][4]->unidade = NULL;
                        hexagonos[6][4]->contem_unidade = 0;
                        hexagonos[7][4]->unidade = NULL;
                        hexagonos[7][4]->contem_unidade = 0;
                        hexagonos[8][4]->unidade = NULL;
                        hexagonos[8][4]->contem_unidade = 0;

                    }

        }

            else if (defensor->cor == "azul"){
                hexagonos[5][1]->unidade = NULL;
                hexagonos[5][1]->contem_unidade = 0;
                hexagonos[6][1]->unidade = NULL;
                hexagonos[6][1]->contem_unidade = 0;
                hexagonos[6][2]->contem_unidade = 0;
                hexagonos[6][2]->unidade = NULL;
                hexagonos[7][1]->contem_unidade = 0;
                hexagonos[7][1]->unidade = NULL;
                hexagonos[8][1]->contem_unidade = 0;
                hexagonos[8][1]->unidade = NULL;
                hexagonos[8][2]->contem_unidade = 0;
                hexagonos[8][2]->unidade = NULL;
                hexagonos[9][1]->contem_unidade = 0;
                hexagonos[9][1]->unidade = NULL;
            }
                else{
                    hexagonos[6][4]->unidade = NULL;
                    hexagonos[6][4]->contem_unidade = 0;
                    hexagonos[7][4]->unidade = NULL;
                    hexagonos[7][4]->contem_unidade = 0;
                    hexagonos[8][4]->unidade = NULL;
                    hexagonos[8][4]->contem_unidade = 0;

                }

        //free(hexagonos[hex_selecao->i][hex_selecao->j]->unidade);
    }
    else{
        hexagonos[hex_selecao->i][hex_selecao->j]->unidade->hp = defensor->hp;
    }
    //cout << "passei do segundo else" << endl;
}
