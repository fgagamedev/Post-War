#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H

#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
typedef struct _vetormouse{
	int x;
	int y;
	int click;
}Vetor_mouse;


extern Vetor_mouse *get_Input();
extern int compara_selecao(int x_min,int x_max,int x,int y_min,int y_max,int y);
SDL_Surface *free_image(SDL_Surface *image);

#endif

