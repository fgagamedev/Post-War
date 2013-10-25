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
    string um = "source/features/RenderWorld/images/front_end1.png";
    load_Image(um,screen);
    SDL_Delay(3000);
    um = "source/features/RenderWorld/images/front_end2.png";
    load_Image(um,screen);
    SDL_Delay(3000);
    um = "source/features/RenderWorld/images/front_end3.png";
    load_Image(um,screen);
    SDL_Delay(3000);
    um = "source/features/RenderWorld/images/front_end4.png";
    load_Image(um,screen);
    SDL_Delay(3000);
    um = "source/features/RenderWorld/images/TelaJogo.png";
    load_Image(um,screen);
    SDL_Delay(3000);
    um = "source/features/RenderWorld/images/bryjstudios_tela_final_01.png";
    load_Image(um,screen);
	SDL_Delay(3000);
	um = "source/features/RenderWorld/images/bryjstudios_tela_final_02.png";
    load_Image(um,screen);
	SDL_Delay(3000);

}



