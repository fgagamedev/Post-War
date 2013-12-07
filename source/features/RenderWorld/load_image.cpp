#include <SDL/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

SDL_Surface *load_Image(string path1,SDL_Surface *screen){

    SDL_Surface *IMG_Load(const char *file);
    char *IMG_GetError();
    screen = SDL_CreateRGBSurface(SDL_HWSURFACE, img->w,img->h, 32,0x000000FF,0x0000FF00,0x00FF0000,0xFF000000);
    const char *path = path1.c_str();
        SDL_Surface* pic = IMG_Load(path);
    SDL_Surface* pic2 = NULL;

    if(pic == NULL){
        printf("Erro ao carregar a imagem: %s\n", IMG_GetError());
        exit(0);
    }

    else{
        pic2 = SDL_DisplayFormat(pic);

        0x000000FF,0x0000FF00,0x00FF0000,0xFF000000

        SDL_SetColorKey(pic2, SDL_SRCCOLORKEY, SDL_MapRGB(pic2->format, 0, 255, 0));
        SDL_FreeSurface(pic);
        return pic2;
    }
    SDL_Flip(screen);
}

void free_image(SDL_Surface *image){
    SDL_UnlockSurface(image);
    SDL_FreeSurface(image);
    //image = NULL;
    //delete image;
    cout << "cheguei"<< endl;
}


void BlitImage(SDL_Surface *screen, SDL_Surface *image, int x, int y){
    SDL_Rect dest;
/*
    src.x = 0;
    src.y = 0;
    src.w = image->w;
    src.h = image->h;*/

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image,NULL,screen,&dest);
}
