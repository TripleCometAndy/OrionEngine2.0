#ifndef _RENDERER
#define _RENDERER
#include "Renderer.h"
#endif

class RendererImpl : public Renderer {
public:
	RendererImpl();

	void destroyTexture(SDL_Texture* texture, HardwareAbstractionLayer * hardwareAbstractionLayer);
	SDL_Texture* imageLoad(std::string fileName, SDL_Renderer* renderer, HardwareAbstractionLayer* hardwareAbstractionLayer);
};