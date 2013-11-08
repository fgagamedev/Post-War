#ifndef _LOOP_H
#define _LOOP_H

#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_net.h>

typedef struct _vetormouse{
	int x;
	int y;
	int click;
}Vetor_mouse;

extern Vetor_mouse *get_Input();
extern int compara_selecao(int x_min,int x_max,int x,int y_min,int y_max,int y);

extern int criar_servidor();

extern int conectar(char* ip_text); 


extern TCPsocket Sclient;
extern TCPsocket Cserver;

#endif

