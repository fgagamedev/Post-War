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


int possui_unidade(string color){

    if(hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade){
        if(!hexagonos[hex_selecao->i][hex_selecao->j]->unidade->cor.compare(color)){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        return 0;
    }
}


int alcance_movimento_soldado(){

    if((abs(hex_selecao->j_antes - hex_selecao->j) <= 1) && (abs(hex_selecao->i_antes - hex_selecao->i)  >0) && (abs(hex_selecao->i_antes - hex_selecao->i)  <3) ){
        if ((abs(hex_selecao->i_antes - hex_selecao->i) == 2  && (abs(hex_selecao->j_antes - hex_selecao->j) == 1 ))){
            return 0;
        }

        if(hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade){
            return 0;
        }

        return 1;
    }
    else{
        return 0;
    }


}

int alcance_ataque_soldado(){
    if((abs(hex_selecao->j_antes - hex_selecao->j) <= 1) && (abs(hex_selecao->i_antes - hex_selecao->i)  >0) && (abs(hex_selecao->i_antes - hex_selecao->i)  <3) ){
        if ((abs(hex_selecao->i_antes - hex_selecao->i) == 2  && (abs(hex_selecao->j_antes - hex_selecao->j) == 1 ))){
            return 0;
        }

        if(hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade){
            Unidade *temp1 = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
            Unidade *temp2 = hexagonos[hex_selecao->i][hex_selecao->j]->unidade;
            if(temp2->cor != temp1->cor)
                return 1;
        }

        return 0;
    }
    else{
        return 0;
    }

}









