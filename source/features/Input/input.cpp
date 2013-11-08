#include<iostream>
#include <vector>
#include <SDL/SDL.h>
#include "../../../include/loop.h"

using namespace std;

Vetor_mouse *get_Input(){
    SDL_Event event;
    Vetor_mouse *vetor_mouse = new Vetor_mouse;
    vetor_mouse->click = 0;


    while (SDL_WaitEvent(&event) != 0) {

            switch (event.type) {
                /* The next two event types deal
                with mouse activity. */
                case SDL_MOUSEMOTION:
                    vetor_mouse->x = event.motion.x;
                    vetor_mouse->y = event.motion.y;
                    return vetor_mouse;
                    /*printf("New position is (%i,%i). ",
                    event.motion.x, event.motion.y);
                    /* We can also get relative motion.
                    printf("That is a (%i,%i) change.\n",
                    event.motion.xrel, event.motion.yrel);*/
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    vetor_mouse->click = event.button.button;
                    vetor_mouse->x = event.motion.x;
                    vetor_mouse->y = event.motion.y;
                    return vetor_mouse;
                    /*printf("Mouse button pressed. ");
                    printf("Button %i at (%i,%i)\n",
                    event.button.button,
                    event.button.x, event.button.y);*/
                    break;
                    /* The SDL_QUIT event indicates that
                    the windows "Close" button has been
                    pressed. We can ignore this if we
                    need to, but that tends to make
                    users rather impatient. */
                case SDL_QUIT:
                    printf("Adeus.\n");
                    exit(0);
                 case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_1){
                        cout << "entrei sdl key down" << endl;
                        vetor_mouse->number = 1;
                        return vetor_mouse;
                    }
            }
        }

}

