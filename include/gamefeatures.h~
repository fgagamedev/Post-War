#ifndef _GAMEFEATURES_H_
#define _GAMEFEATURES_H_

#include <SDL/SDL.h>
#include <map>
#include <vector>

using namespace std;

typedef struct _Unidade{
	SDL_Surface *nome;
	double hp;
	int atk;
	int def;
	int alcance;
	int ouro;
	int comida;
	int minerio;
	char *cor;
	char *tipo;
} Unidade;



extern void desenha_texto(char *texto, SDL_Surface* dst, int x, int y, char *tipo_fonte, int size);
extern void load_menu(SDL_Surface *screen);
extern void inicio(SDL_Surface *screen);
extern void creditos(SDL_Surface *screen);
extern void fase1(SDL_Surface *screen);
extern void carregar_fase1(SDL_Surface *screen,string pais_serv, string pais_client);
extern void carrega_china(SDL_Surface *screen,string lado);
extern void carrega_eua(SDL_Surface *screen,string lado);


#endif

