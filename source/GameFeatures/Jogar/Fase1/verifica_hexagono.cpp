#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"
#include<math.h>

using namespace std;


int verifica_hexagono(int x, int y){

    float vx, vy;
    float re=0;
    float x_f = (float) x;
    float y_f = (float) y;

    for(int i=0;i<hexagonos.size();i++){
        for(int j=0;j<hexagonos[i].size();j++){
        //cout<<"indice="<<hexagonos[i][j]->indice<<endl;
            //if(hexagonos[i][j]->contem_unidade==1){
                //cout<<"calculando..., indice="<<hexagonos[i][j]->indice<<endl;
                vx = abs(x_f - hexagonos[i][j]->centro_x);
                vy = abs(y_f - hexagonos[i][j]->centro_y);
                re = (vx*vx)+(vy*vy);
                re = sqrt(re);
                    if(re <= 20){
                        cout<<"clicou no hexagono "<<hexagonos[i][j]->indice<<endl;
                        hex_selecao->i = i;
                        hex_selecao->j = j;
                        cout<<"hex_selecao->i"<<hex_selecao->i <<endl;
                        cout<<"hex_selecao->j"<<hex_selecao->j <<endl;
                        return 1;
                    }
           // }
            /*hex_selecao->i = i;
            hex_selecao->j = j;*/

        }

    }

}
