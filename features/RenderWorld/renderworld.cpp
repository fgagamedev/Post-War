#include <SDL/SDL.h>
#include <iostream>

void render_World(){
    SDL_Surface *tela;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

    tela = SDL_SetVideoMode(640, 480, 16, SDL_DOUBLEBUF);
    
    SDL_Delay(3000);		
}

int main(){

    render_World();
}
