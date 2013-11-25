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


	char text[100];

			/*cout<<"O servidor vai digitar..."<<endl;
			SDLNet_TCP_Recv(Cserver,text,100);
			cout<<"O servidor diz: "<<text<<endl;*/
			/*cout<<"Digite AGORA"<<endl;
			cin.getline(text,100);
			SDLNet_TCP_Send(client,&text,100);
			if(strcmp(text, "sair") == 0)
				break;*/
}



/*
    char code_asd[100];
	IPaddress ip;
	SDLNet_ResolveHost(&ip,ip_text,1234);

    cout<<"Conectando..."<<endl;
	Cserver = SDLNet_TCP_Open(&ip);
    /* Open a connection with the IP provided (listen on the host's port)
	if (!(Cserver = SDLNet_TCP_Open(&ip)))
	{
        cout<<"DEU PAU"<<endl;
        exit(EXIT_FAILURE);
	}
        else{
            cout<<"Deu!!"<<endl;
        }


    SDLNet_TCP_Recv(Cserver, code_asd, 100);
    cout<<"FINALMENTE a msg é: "<<code_asd<<endl;*/


    /*
	char text[100];

		while(1){
			cout<<"O servidor vai digitar..."<<endl;
			SDLNet_TCP_Recv(server,text,100);
			cout<<"O servidor diz: "<<text<<endl;
			cout<<"Digite AGORA"<<endl;
			cin.getline(text,100);
			SDLNet_TCP_Send(server,&text,100);
			if(strcmp(text, "sair") == 0)
				break;
		}


	SDLNet_TCP_Close(client); // precisa fechar porque senão,
				 // não dá pra usar a mesma porta denovo

	SDLNet_Quit();
	SDL_Quit();
}
*/
