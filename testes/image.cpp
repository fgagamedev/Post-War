#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include<iostream>
#include<unistd.h>

using namespace std;
int main(){

	SDL_Surface *screen = NULL;
	int width = 1208, height = 680, bitsPerPixel = 16;
	Uint32 videoOptions = SDL_HWSURFACE | SDL_DOUBLEBUF;

	screen = SDL_SetVideoMode(width, height, bitsPerPixel, videoOptions);

	if (!screen)
	{
		cerr << "Nao foi possivel inicializar o video com as configuracoes "
			<< "indicadas: " << SDL_GetError() << endl;
		exit(-2);
	}


    SDL_Surface *IMG_Load(const char *file);
    char *IMG_GetError();

    SDL_Surface* pic = IMG_Load("bryjstudios_tela_final_02.png");
    SDL_Surface* pic2 = NULL;
    if(pic == NULL)
    {
    printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
    exit(0);
    }

    else{
        cout<<"entrou"<<endl;
        pic2 = SDL_DisplayFormat(pic);
        SDL_BlitSurface(pic2,0,screen,0);
         SDL_Flip(screen);

        sleep(5);
        SDL_FreeSurface(pic);

    }
    SDL_Quit();
    }
