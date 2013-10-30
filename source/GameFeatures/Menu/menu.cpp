#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void load_menu(SDL_Surface *screen){

    SDL_Surface *jogar_selecionado;
    SDL_Surface *creditos_selecionado;
    SDL_Surface *sair_selecionado;
    SDL_Surface *estatisticas_selecionado;
    SDL_Surface *opcoes_selecionado;
    //carregando imagens
    string path_jogo = "source/GameFeatures/Menu/Images/jogar_selecionado.png";
    jogar_selecionado = load_Image(path_jogo,screen);

    string path_estatisticas = "source/GameFeatures/Menu/Images/estatisticas_selecionado.png";
    estatisticas_selecionado = load_Image(path_estatisticas, screen);

    string path_creditos = "source/GameFeatures/Menu/Images/creditos_selecionado.png";
    creditos_selecionado = load_Image(path_creditos, screen);

    string path_sair = "source/GameFeatures/Menu/Images/sair_selecionado.png";
    sair_selecionado = load_Image(path_sair, screen);

    string path_opcoes = "source/GameFeatures/Menu/Images/opcoes_selecionado.png";
    opcoes_selecionado = load_Image(path_opcoes, screen);

    string path = "source/GameFeatures/Menu/Images/menu.png";
    SDL_Surface *menu = load_Image(path, screen);



    BlitImage(screen, menu, 0, 0);
    SDL_Flip(screen);
    int cont=0;
    Vetor_mouse *vetor = new Vetor_mouse;


    while(1){

        vetor = get_Input();



        //cout <<"Posicao do mouse ("<<vetor->x<<","<<vetor->y<<")"<<endl;
        //cout<<"Click: "<<vetor->click<<endl;

        if(compara_selecao(478.5,731.5,vetor->x,211,275,vetor->y)){
            BlitImage(screen, jogar_selecionado, 478.5, 211);
            SDL_Flip(screen);
            //cout<<"Entrei aqui"<<endl;
            if(vetor->click == 1){
                //cout<<"Clicou em jogar"<<endl;
                inicio(screen);
            }
            cont=0;
        }

            else if(compara_selecao(450,798,vetor->x,311,375,vetor->y)){
                BlitImage(screen, opcoes_selecionado, 450.0, 311);
                SDL_Flip(screen);
                if(vetor->click == 1){
                                //cout<<"Clicou em jogar"<<endl;
                }
                cont=0;
                }
                    else if(compara_selecao(355,798,vetor->x,417,475,vetor->y)){
                            BlitImage(screen, estatisticas_selecionado, 355.0, 411);
                            SDL_Flip(screen);
                            //cout<<"Entrei aqui"<<endl;
                            if(vetor->click == 1){
                                //cout<<"Clicou em jogar"<<endl;
                            }
                            cont=0;
                        }

                        else if(compara_selecao(425,798,vetor->x,511,575,vetor->y)){
                            BlitImage(screen, creditos_selecionado, 425.0, 511);
                            SDL_Flip(screen);
                            //cout<<"Entrei aqui"<<endl;
                            if(vetor->click == 1){
                                //cout<<"Clicou em jogar"<<endl;
                                creditos(screen);
                            }
                            cont=0;
                        }

                                else if(compara_selecao(350,798,vetor->x,611,675,vetor->y)){
                                    BlitImage(screen, sair_selecionado, 350.0, 611);
                                    SDL_Flip(screen);
                                    //cout<<"Entrei aqui"<<endl;
                                    if(vetor->click == 1){
                                        //cout<<"Clicou em jogar"<<endl;
                                        SDL_Quit();
                                        exit(0);
                                    }
                                    cont=0;
                                }




                                else if (cont==0){
                                    BlitImage(screen, menu, 0, 0);
                                    SDL_Flip(screen);
                                    cont=1;
                                }
    }

    SDL_Delay(10000);
}
