#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void verifica_derrota(SDL_Surface *screen){
    Unidade *temp;
    for(int i=0;i<hexagonos.size();i++){
        for(int j=0;j<hexagonos[i].size();j++){
            if(hexagonos[i][j]->contem_unidade==1){
                temp = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
                if(temp->tipo == "quartel" && temp->hp == 0){
                    string mensagem = "Você perdeu!LOSER!!";
                    desenha_texto(mensagem, screen, 50, 50, 60);
                }
            }
        }
    }
}

