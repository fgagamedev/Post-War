// Autor: Edson Alves
// Data: 26/12/2012
// e-mail: edsonalves@unb.br
#include <iostream>
#include <SDL/SDL.h>

#include "draw.h"
#include "video.h"

using namespace std;

void render_World(){



	init_sdl();
	setup_window();
	SDL_Surface *screen = setup_video();

    load_Image("source/features/RenderWorld/images/bryjstudios_tela_final_01.png",screen);
	SDL_Delay(3000);
    load_Image("source/features/RenderWorld/images/bryjstudios_tela_final_02.png",screen);
	SDL_Delay(3000);

}



