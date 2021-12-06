#ifndef _DECOUPLED_HARDWARE_ABSTRACTION_LAYER
#define _DECOUPLED_HARDWARE_ABSTRACTION_LAYER
#include "../include/DecoupledHardwareAbstractionLayer.h"
#endif

#include <iostream>

DecoupledHardwareAbstractionLayer::DecoupledHardwareAbstractionLayer() {

}

void DecoupledHardwareAbstractionLayer::init(int width, int height, SDL_Window** gWindow, SDL_Renderer** gRenderer, bool fullScreen, SDL_Joystick** gGameController, bool* hasController) {
}

void DecoupledHardwareAbstractionLayer::delay(int numTicksToDelay) {
}

void DecoupledHardwareAbstractionLayer::renderCopy(SDL_Renderer* gRenderer, SDL_Texture* image, SDL_Rect* clip, SDL_Rect* renderQuad) {
}

void DecoupledHardwareAbstractionLayer::setRenderDrawColor(SDL_Renderer* sdlRenderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
}

void DecoupledHardwareAbstractionLayer::renderClear(SDL_Renderer* sdlRenderer) {
}

void DecoupledHardwareAbstractionLayer::renderPresent(SDL_Renderer* sdlRenderer) {
}

int __cdecl DecoupledHardwareAbstractionLayer::pollEvent(SDL_Event* event) {
	return 0;
}

Uint32 __cdecl DecoupledHardwareAbstractionLayer::getTicks() {
	return 50000;
}

void DecoupledHardwareAbstractionLayer::destroyTexture(SDL_Texture* texture) {

}

SDL_Surface* DecoupledHardwareAbstractionLayer::imageLoad(const char* file) {
	return NULL;
}

SDL_Texture* DecoupledHardwareAbstractionLayer::createTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
	return NULL;
}

void DecoupledHardwareAbstractionLayer::freeSurface(SDL_Surface* loadedSurface) {

}