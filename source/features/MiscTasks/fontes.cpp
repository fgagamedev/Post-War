#include <SDL/SDL_ttf.h>
#include <iostream>
#include <SDL/SDL.h>
#include "../../../include/draw.h"




void desenha_texto(char *texto, SDL_Surface* screen, int x, int y, char *tipo_fonte, int size){

	TTF_Font *font = TTF_OpenFont(tipo_fonte, size);
	SDL_Color cor = {255, 0, 0}; //vermelho
	SDL_Surface* escrita = TTF_RenderText_Solid(font, texto, cor);
	SDL_Rect pos = {x, y};
	SDL_BlitSurface(escrita, NULL, screen, &pos);
    SDL_Flip(screen);
    cout << "digitei o ip 1" << endl;
}
