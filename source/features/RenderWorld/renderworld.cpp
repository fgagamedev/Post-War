// Autor: Edson Alves
// Data: 26/12/2012
// e-mail: edsonalves@unb.br
#include <iostream>
#include <SDL/SDL.h>

#include "draw.h"
#include "video.h"

using namespace std;

void render_World(int op){



	init_sdl();
	setup_window();
	SDL_Surface *screen = setup_video();


    switch(op){
        case 1:
            load_Image("source/features/RenderWorld/images/bryjstudios_tela_final_01.png",screen);
        break;

        case 2:
            load_Image("source/features/RenderWorld/images/bryjstudios_tela_final_02.png",screen);
        break;


    }


}



