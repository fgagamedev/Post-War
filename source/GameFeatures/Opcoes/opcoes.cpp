#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_thread.h>
#include <SDL/SDL_mixer.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"


using namespace std;

void opcoes(SDL_Surface *screen){

    string tela = "source/GameFeatures/Opcoes/Images/fundo_opcoesMenu.png";
    SDL_Surface *telafundo = load_Image(tela, screen);


    BlitImage(screen, telafundo, 0, 0);
    SDL_Flip(screen);
    Vetor_mouse *vetor = new Vetor_mouse;

    start=0;
    float volume_menos = 1.1;
    float volume_mais = 1.1;

    while(1){

        start = SDL_GetTicks();
        vetor = get_Input();
        BlitImage(screen, telafundo, 0, 0);

        //Botao X da tela
        if(compara_selecao(792, 822, vetor->x, 296, 324, vetor->y)){
            if(vetor->click == 1){
                break;
                //load_menu(screen);
            }
        }
            //Botao - do volume
            else if (compara_selecao(486, 506, vetor->x, 356, 378, vetor->y)){
                if(vetor->click == 1){
                    // set the music volume to 1/2 maximum, and then check it
                    printf("volume was    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME/volume_menos));
                    printf("volume is now : %d\n", Mix_VolumeMusic(-1));

                    volume_menos = volume_menos + 0.1;
                }
            }
                //Botao + do volume
                else if (compara_selecao(801, 821, vetor->x, 356, 378, vetor->y)){
                    if(vetor->click == 1){
                        // set the music volume to 1/2 maximum, and then check it
                        printf("volume was    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME*volume_mais));
                        printf("volume is now : %d\n", Mix_VolumeMusic(-1));

                        volume_mais = volume_mais + 0.1;
                    }
                }

        //frame_delay(start);

    }

}


