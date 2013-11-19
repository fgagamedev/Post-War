#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../include/draw.h"
#include "../../include/video.h"
#include "../../include/loop.h"
#include "../../include/gamefeatures.h"



using namespace std;
void blit_tela(SDL_Surface *screen){

    BlitImage(screen, malha, 0, 0);
    BlitImage(screen, hud, 0, 0);


    for(int i=0;i<hexagonos.size();i++){
        for(int j=0;j<hexagonos[i].size();j++){
            if(hexagonos[i][j]->contem_unidade==1){
                //cout<<"foi, i: "<<i<<"j: "<<j<<endl;
                if((i == 2 || i == 4 || i == 6) && (j == 12)){
                    SDL_Rect cutBox = {32,0,32,32};
                    SDL_Rect dst = {hexagonos[i][j]->x, hexagonos[i][j]->y, 0, 0};
                    //cout << "fiz isso i " << i << endl;
                    SDL_BlitSurface(hexagonos[i][j]->unidade->nome, &cutBox,  screen, &dst);
                }
                else
                BlitImage(screen,hexagonos[i][j]->unidade->nome,hexagonos[i][j]->x,hexagonos[i][j]->y);
            }
        }

    }

}
