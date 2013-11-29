#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include "../../../include/draw.h"
#include "../../../include/gamefeatures.h"

void desenha_texto(string texto, SDL_Surface* screen, int x, int y, int size){
    char fonte[] = "atfantrg.ttf";
	TTF_Font *font = TTF_OpenFont(fonte, size);
	if(font == NULL){
        cout << "Nao carreguei a fonte"<< endl;
        }
    const char* txt = texto.c_str();
	SDL_Color cor = {red , green, blue}; //vermelho
	SDL_Surface* escrita = TTF_RenderText_Solid(font, txt, cor);
	SDL_Rect pos = {x, y};
	SDL_BlitSurface(escrita, NULL, screen, &pos);
    //SDL_Flip(screen);
    //cout << "digitei o ip 1" << endl;
    //SDL_FreeSurface(escrita);
    TTF_CloseFont(font);
}
