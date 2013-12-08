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
                        hexagonos[i][j]->unidade->atk =150;
                        hexagonos[i][j]->unidade->def = 150;
                    }
                }
            }
        }
    }
}
