#include<iostream>
#include<stdio.h>
#include <SDL/SDL_net.h>
#include "../../../include/gamefeatures.h"

using namespace std;

void get_Network_Messages(){

}

void enviar_msg(TCPsocket maquina, char text[]){

    SDLNet_TCP_Send(maquina,text,strlen(text)+1);


}

void receber_msg(TCPsocket maquina, char *text){

    SDLNet_TCP_Recv(maquina,text,100);
/*
    cout<<"ok let's go"<<endl;
    if(SDLNet_TCP_Recv(maquina, text, 300) > 0){
        cout<<"Olha a msg: "<<text<<endl;
    }else{
        cout<<"Deu pau no recebimento, a msg é: "<<text<<   endl;
    }*/

}
