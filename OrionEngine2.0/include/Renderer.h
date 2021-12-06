#ifndef _SDL
#define _SDL
#include "../sdlInclude/include/SDL.h"
#include "../sdlInclude/include/SDL_image.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "../include/HardwareAbstractionLayer.h"
#endif

#include <string>

class Renderer {
public:
	Renderer();

	virtual void destroyTexture(SDL_Texture* texture, HardwareAbstractionLayer * hardwareAbstractionLayer) = 0;
	virtual SDL_Texture* imageLoad(std::string fileName, SDL_Renderer* renderer, HardwareAbstractionLayer * hardwareAbstractionLayer) = 0;
};