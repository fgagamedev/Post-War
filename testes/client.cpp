#include<iostream> 
#include<SDL/SDL.h>
#include<SDL/SDL_net.h>
#include<cstring>

using namespace std;

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip,"192.168.1.10",1234);

	TCPsocket client = SDLNet_TCP_Open(&ip);
	char text[100];
	cin>>text;
	SDLNet_TCP_Recv(client,text,100);
	cout<<text<<endl;


	SDLNet_TCP_Close(client); // precisa fechar porque senão,
				 // não dá pra usar a mesma porta denovo

	SDLNet_Quit();
	SDL_Quit();
}
