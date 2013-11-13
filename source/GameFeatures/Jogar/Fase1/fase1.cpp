#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void fase1(SDL_Surface *screen){
    string pais_serv ("china");
    string pais_client ("eua");
    carregar_fase1(screen,pais_serv,pais_client);

    //BlitImage(screen, mapa1, 0, 0);

    Vetor_mouse *vetor = new Vetor_mouse;

    SDL_Flip(screen);

      while(1){
        vetor = get_Input();

        if(vetor->click == 1){
            if(compara_selecao(801, 833, vetor->x, 151, 183, vetor->y)){
                cout << "cliquei no boneco certo e vetor click ="<< vetor->click << endl;
                while(1){
                vetor = get_Input();
                if(vetor->click == 1){
                    cout << "entrei para mover" << endl;
                    cout << "x:" << vetor->x << endl;
                    cout << "y:" << vetor->y << endl;
                    mover_soldado(screen, 1, vetor->x, vetor->y);
                    break;
                    }
                }
            }

        }
    }

}
