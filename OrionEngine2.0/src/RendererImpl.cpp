#ifndef _RENDERER_IMPL
#define _RENDERER_IMPL
#include "RendererImpl.h"
#endif

RendererImpl::RendererImpl() {
}

void RendererImpl::destroyTexture(SDL_Texture* texture, HardwareAbstractionLayer * hardwareAbstractionLayer) {
    hardwareAbstractionLayer->destroyTexture(texture);
}

SDL_Texture* RendererImpl::imageLoad(std::string fileName, SDL_Renderer * renderer, HardwareAbstractionLayer * hardwareAbstractionLayer) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = hardwareAbstractionLayer->imageLoad(fileName.c_str());

    if (loadedSurface == NULL) {
        //printf("Unable to load image %s! SDL_image Error: %s\n",
            //"images/spriteSheetShield.png", IMG_GetError());
    }
    else {
        // Create texture from surface pixels
        newTexture = hardwareAbstractionLayer->createTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            //printf("Unable to create texture from %s! SDL Error: %s\n",
                //"images/spriteSheetShield.png", SDL_GetError());
            //exit(1);
        }
        else {
            /*
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;

            */
        }

        // Get rid of old loaded surface
        hardwareAbstractionLayer->freeSurface(loadedSurface);
    }

    return newTexture;

}