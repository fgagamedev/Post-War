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
    cout<<"cheguei até aqui"<<endl;

    for(int i=0;i<hexagonos.size();i++){
        for(int j=0;j<hexagonos[i].size();j++){
            if(hexagonos[i][j]->contem_unidade==1){
                cout<<"foi, i: "<<i<<"j: "<<j<<endl;
                BlitImage(screen,hexagonos[i][j]->unidade->nome,hexagonos[i][j]->x,hexagonos[i][j]->y);
            }
        }
    }

}
