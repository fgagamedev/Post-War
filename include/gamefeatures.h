#ifndef _GAMEFEATURES_H_
#define _GAMEFEATURES_H_

#include <SDL/SDL.h>
#include<SDL/SDL_net.h>
#include <map>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

typedef struct _Unidade{
	SDL_Surface *ataque;
	SDL_Surface *ataque_baixo;
	SDL_Surface *ataque_cima;
	SDL_Surface *nome;
	SDL_Surface *imagem_lateral;
	int hp;
	int atk;
	int def;
	int alcance;
	int ouro;
	int comida;
	int minerio;
	string cor;
	string tipo;
	int x;
	int y;
} Unidade;

typedef struct _Hexagonos{
	int x;
	int y;
	int indice;
	bool contem_unidade : 1;
	Unidade *unidade;
	int centro_x;
	int centro_y;
	int raio;
} Hexagono;


typedef struct _Hexagono_selecao{
	int i;
	int j;
	int i_antes;
	int j_antes;
} Hex_selecao;

extern Hex_selecao *hex_selecao;
extern vector< vector <Hexagono *> > hexagonos;
extern vector<Unidade *> unidades_azul;
extern vector<Unidade *> unidades_vermelhas;
extern SDL_Surface *malha;
extern SDL_Surface *hud;
extern SDL_Surface *sem_malha;
extern SDL_Surface *com_malha;
//extern char codigo[100];
extern TCPsocket Sclient;
extern TCPsocket Cserver;
extern char texto_global[100];
extern int qual_vez;
extern int red, green, blue;

extern void desenha_texto(string texto, SDL_Surface* dst, int x, int y, int size);
extern void load_menu(SDL_Surface *screen);
extern void inicio(SDL_Surface *screen);
extern void creditos(SDL_Surface *screen);
extern void fase1(SDL_Surface *screen,string qual_maquina);
extern void carregar_fase1(SDL_Surface *screen,string pais_serv, string pais_client);
extern void carrega_china(SDL_Surface *screen,string lado);
extern void carrega_eua(SDL_Surface *screen,string lado);
extern void blit_tela(SDL_Surface *screen,int i);
extern int verifica_hexagono(int x, int y);
extern void mover_soldado(SDL_Surface *screen, int i, int x, int y);
extern void ataque_unidade(SDL_Surface *screen, int x, int y, int totalElapsedTime, int delay, int lastdt);
extern int possui_unidade(string cor);
extern int alcance_movimento_soldado();
extern int alcance_ataque_soldado();
extern void dano_ataque(SDL_Surface *screen);
extern void enviar_msg (TCPsocket maquina, char text[]);
extern void receber_msg(TCPsocket maquina,char *texto);
void amigo_movimenta(char code_recv[],SDL_Surface * screen, int totalElapsedTime, int delay, int lastdt);
void codifica_ataque(char codigo[]);
void verifica_derrota(SDL_Surface *screen);
void blit_lateral(Unidade *lateral,SDL_Surface *screen);


#endif

