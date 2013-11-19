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
	string tipo;
	int x;
	int y;
} Unidade;

typedef struct _Hexagonos{
	int x;
	int y;
	int indice;
	int contem_unidade;
	Unidade *unidade;
	int centro_x;
	int centro_y;
	int raio;
} Hexagono;

extern vector< vector <Hexagono *> > hexagonos;
extern vector<Unidade *> unidades_azul;
extern vector<Unidade *> unidades_vermelhas;
extern SDL_Surface *malha;
extern SDL_Surface *hud;


extern void desenha_texto(char *texto, SDL_Surface* dst, int x, int y, int size);
extern void load_menu(SDL_Surface *screen);
extern void inicio(SDL_Surface *screen);
extern void creditos(SDL_Surface *screen);
extern void fase1(SDL_Surface *screen);
extern void carregar_fase1(SDL_Surface *screen,string pais_serv, string pais_client);
extern void carrega_china(SDL_Surface *screen,string lado);
extern void carrega_eua(SDL_Surface *screen,string lado);
extern void blit_tela(SDL_Surface *screen);
extern int verifica_hexagono(int x, int y);
extern void mover_soldado(SDL_Surface *screen, int i, int x, int y);




#endif

