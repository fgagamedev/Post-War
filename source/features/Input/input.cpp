#include<iostream>
#include<SDL/SDL.h>

int get_Input(){

	SDL_Event event;
	int rc;


	SDL_EnableUNICODE(1);

		while (SDL_PollEvent(&event)!=0) {
			switch (event.type) {
                case SDL_QUIT:
                    exit(0);

                case SDL_MOUSEBUTTONDOWN:
                        return 2;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
  /*                  case SDLK_UP:
                        break;

                    case SDLK_DOWN:
                        break;*/

                    case SDLK_LEFT:
                        return 1;

                    case SDLK_RIGHT:
                        return 2;

                    default:
                        break;
                    }
                    break;
                }
		}

}
