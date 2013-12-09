#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void evolucao_soldado(Pais *pais){
    for(unsigned int i=0;i<hexagonos.size();i++){
        for(unsigned int j=0;j<hexagonos[i].size();j++){
            if(hexagonos[i][j]->contem_unidade==1){
                if(hexagonos[i][j]->unidade->cor == pais->cor){
                    if(hexagonos[i][j]->unidade->tipo == "soldado"){
                        hexagonos[i][j]->unidade->hp = 250;
                        hexagonos[i][j]->unidade->atk = 150;
                        hexagonos[i][j]->unidade->def = 150;
                    }
                }
            }
        }
    }
    pais->ouro -= 30;
    if(pais->ouro < 0){
        pais->ouro = 0;
    }
    pais->minerio -= 50;
    if(pais->minerio < 0){
        pais->minerio = 0;
    }
    pais->comida -= 20;
    if(pais->comida <0){
        pais->comida = 0;
    }
}

void evolucao_quartel(Pais *pais){
    for(unsigned int i=0;i<hexagonos.size();i++){
        for(unsigned int j=0;j<hexagonos[i].size();j++){
            if(hexagonos[i][j]->contem_unidade==1){
                if(hexagonos[i][j]->unidade->cor == pais->cor){
                    if(hexagonos[i][j]->unidade->tipo == "quartel"){
                        hexagonos[i][j]->unidade->hp = 1250;
                        hexagonos[i][j]->unidade->atk = 0;
                        hexagonos[i][j]->unidade->def = 500;
                    }
                }
            }
        }
    }
    pais->ouro -= 50;
    if(pais->ouro < 0){
        pais->ouro = 0;
    }
    pais->minerio -= 50;
    if(pais->minerio < 0){
        pais->minerio = 0;
    }
    pais->comida -= 40;
    if(pais->comida <0){
        pais->comida = 0;
    }
}
