#include<iostream>
#include<SDL/SDL.h>
#include<SDL/SDL_net.h>
#include<cstring>
#include "../../../include/loop.h"

using namespace std;

TCPsocket Cserver;

int conectar(char ip_text[]){

	IPaddress ip;
	SDLNet_ResolveHost(&ip,"localhost",1234);

	Cserver = SDLNet_TCP_Open(&ip);
    return 0;
}
