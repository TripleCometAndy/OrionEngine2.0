#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

class DecoupledHardwareAbstractionLayer : public HardwareAbstractionLayer {
public:
	DecoupledHardwareAbstractionLayer();

	void init(int width, int height, SDL_Window** gWindow, SDL_Renderer** gRenderer, bool fullScreen, SDL_Joystick** gGameController, bool* hasController);

	void delay(int numTicksToDelay);
	void renderCopy(SDL_Renderer* gRenderer, SDL_Texture* image, SDL_Rect* clip, SDL_Rect* renderQuad);
	void setRenderDrawColor(SDL_Renderer* sdlRenderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void renderClear(SDL_Renderer* sdlRenderer);
	void renderPresent(SDL_Renderer* sdlRenderer);
	int __cdecl pollEvent(SDL_Event* event);
	Uint32 __cdecl getTicks();
	void destroyTexture(SDL_Texture* texture);
	SDL_Surface* imageLoad(const char* file);
	SDL_Texture* createTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	void freeSurface(SDL_Surface* loadedSurface);
};