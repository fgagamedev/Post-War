#include<iostream>
#include<SDL/SDL.h>
#include<SDL/SDL_net.h>
#include<cstring>
#include "../../../include/loop.h"

using namespace std;

int criar_servidor(){
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip,NULL,1234);

	TCPsocket server = SDLNet_TCP_Open(&ip);


    while(1){
	TCPsocket Sclient = SDLNet_TCP_Accept(server);

        if(Sclient){
            cout<<"Conectou!!"<<endl;
            return 1;
        }
    }

}

    /*
	char text[100];

	while(1){
		client = SDLNet_TCP_Accept(server);
		if(client){

			while(1){
				//aqui você pode comunicar com o cliente
				//SDLNet_TCP_Send (client,text,strlen(text)+1);
				cout<<"Sua vez de digitar"<<endl;
				cin.getline(text,100);
				SDLNet_TCP_Send(client,&text,100);
				cout<<"O cliente vai digitar..."<<endl;
				SDLNet_TCP_Recv(client,text,100);
				cout<<"O cliente diz: "<<text<<endl;
					if(strcmp(text,"sair") ==0){
						SDLNet_TCP_Close(client);
						SDLNet_TCP_Close(server);
						SDLNet_Quit();
						SDL_Quit();
						return 0;
					}

			}
		}
	}
	SDLNet_TCP_Close(server); // precisa fechar porque senão,
				 // não dá pra usar a mesma porta denovo

	SDLNet_Quit();
	SDL_Quit();
}*/
