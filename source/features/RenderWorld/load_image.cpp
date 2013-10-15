#include<SDL/SDL_image.h>
#include<iostream>

void load_Image(char path[],SDL_Surface *screen){

    SDL_Surface *IMG_Load(const char *file);
    char *IMG_GetError();

    SDL_Surface* pic = IMG_Load(path);
    SDL_Surface* pic2 = NULL;
    if(pic == NULL)
    {
    printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
    exit(0);
    }

    else{
        pic2 = SDL_DisplayFormat(pic);
        SDL_BlitSurface(pic2,0,screen,0);
        SDL_Flip(screen); /// Mudar essa função para UpdateObjets
        SDL_FreeSurface(pic);

    }
}

