#pragma once

#ifndef _SDL
#define _SDL
#include "../sdlInclude/include/SDL.h"
#include "../sdlInclude/include/SDL_image.h"
#endif

#include <vector>

class HardwareAbstractionLayer {
public:
	HardwareAbstractionLayer();

    virtual void init(int width, int height, SDL_Window** gWindow, SDL_Renderer** gRenderer, bool fullScreen, SDL_Joystick** gGameController, bool* hasController) = 0;
	virtual void delay(int numTicksToDelay) = 0;
	virtual void renderCopy(SDL_Renderer* gRenderer, SDL_Texture* image, SDL_Rect * clip, SDL_Rect * renderQuad) = 0;
	virtual void setRenderDrawColor(SDL_Renderer * sdlRenderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
	virtual void renderClear(SDL_Renderer* sdlRenderer) = 0;
	virtual void renderPresent(SDL_Renderer* sdlRenderer) = 0;
	virtual int __cdecl pollEvent(SDL_Event * event) = 0;
	virtual Uint32 __cdecl getTicks() = 0;
	virtual void destroyTexture(SDL_Texture* texture) = 0;
	virtual SDL_Surface* imageLoad(const char * file) = 0;
	virtual SDL_Texture* createTextureFromSurface(SDL_Renderer * renderer, SDL_Surface * surface) = 0;
	virtual void freeSurface(SDL_Surface* loadedSurface) = 0;
};