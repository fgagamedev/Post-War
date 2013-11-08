#include <SDL/SDL_ttf.h>
#include <iostream>
#include <SDL/SDL.h>
#include "../../../include/draw.h"




void desenha_texto(char *texto, SDL_Surface* dst, int x, int y, char *tipo_fonte, int size){

	TTF_Font *font = TTF_OpenFont(tipo_fonte, size);
	SDL_Color cor = {255, 0, 0}; //vermelho
	SDL_Surface* src = TTF_RenderText_Solid(font, texto, cor);
	SDL_Rect dst_rect = {x, y, 0, 0};

	//BlitImage(dst, src, 0 , 0);
	//SDL_Flip(dst);
	SDL_BlitSurface(src, NULL, dst, &dst_rect);
    SDL_Flip(dst);

	//SDL_FreeSurface(src);
}
