#ifndef _SDL_HANDLER
#define _SDL_HANDLER
#include "../include/SDLHandler.h"
#endif

#include <iostream>

SDLHandler::SDLHandler() {

}

void SDLHandler::init(int width, int height, SDL_Window** gWindow, SDL_Renderer** gRenderer, bool fullScreen, SDL_Joystick** gGameController, bool* hasController) {
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window

        if (SDL_NumJoysticks() < 1) {
            (*hasController) = false;

            std::cout << "No Controller" << std::endl;
            // exit(1);
        }
        else {
            // Load joystick
            *gGameController = SDL_JoystickOpen(0);

            if (*gGameController == NULL) {
                printf(
                    "Warning: Unable to open game controller! SDL Error: %s\n",
                    SDL_GetError());
            }

            (*hasController) = true;
        }

        if (fullScreen) {
            (*gWindow) =
                SDL_CreateWindow("Orion Engine", SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED, width, height,
                    SDL_WINDOW_SHOWN || SDL_WINDOW_FULLSCREEN_DESKTOP);
            SDL_ShowCursor(0);
        }
        else {

            (*gWindow) = SDL_CreateWindow("Orion Engine",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
                height, SDL_WINDOW_SHOWN);
        }

        if (gWindow == NULL) {
            printf(
                "Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            // Create renderer for window
            (*gRenderer) = SDL_CreateRenderer((*gWindow), -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n",
                    SDL_GetError());
                success = false;
            }
            else {
                // Initialize renderer color
                SDL_SetRenderDrawColor((*gRenderer), 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf(
                        "SDL_image could not initialize! SDL_image Error: %s\n",
                        IMG_GetError());
                    success = false;
                }
            }
        }

        if (!success) {
            exit(1);
        }
    }
}

void SDLHandler::delay(int numTicksToDelay) {
    SDL_Delay(numTicksToDelay);
}

void SDLHandler::renderCopy(SDL_Renderer* gRenderer, SDL_Texture* image, SDL_Rect * clip, SDL_Rect * renderQuad) {
    SDL_RenderCopy(gRenderer, image, clip, renderQuad);
}

void SDLHandler::setRenderDrawColor(SDL_Renderer* sdlRenderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(sdlRenderer, 0xAF, 0xBF, 0xCF, 0xFF);
}

void SDLHandler::renderClear(SDL_Renderer* sdlRenderer) {
    SDL_RenderClear(sdlRenderer);
}

void SDLHandler::renderPresent(SDL_Renderer* sdlRenderer) {
    SDL_RenderPresent(sdlRenderer);
}

int __cdecl SDLHandler::pollEvent(SDL_Event* event) {
    return SDL_PollEvent(event);
}

Uint32 __cdecl SDLHandler::getTicks() {
    return SDL_GetTicks();
}

void SDLHandler::destroyTexture(SDL_Texture* texture) {
    SDL_DestroyTexture(texture);
}

SDL_Surface* SDLHandler::imageLoad(const char* file) {
    return IMG_Load(file);
}

SDL_Texture* SDLHandler::createTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
    return SDL_CreateTextureFromSurface(renderer, surface);
}

void SDLHandler::freeSurface(SDL_Surface* loadedSurface) {
    SDL_FreeSurface(loadedSurface);
}