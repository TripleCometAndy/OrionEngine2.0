#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "../include/OrionEntity.h"
#endif

#ifndef _IOEXCEPTION
#define _IOEXCEPTION
#include "../include/IOException.h"
#endif

#ifndef _HITBOX
#define _HITBOX
#include "../include/Hitbox.h"
#endif

#include <iostream>

OrionEntity::OrionEntity() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

void OrionEntity::load_files(Renderer* renderer, SDL_Renderer* sdlRenderer, HardwareAbstractionLayer * hardwareAbstractionLayer) {
	if (!spriteSheets.empty()) {
		for (auto it : spriteSheets) {
			SDL_Texture* spriteSheet = it.second;

			renderer->destroyTexture(spriteSheet, hardwareAbstractionLayer);
		}

		spriteSheets.clear();
	}

	try {
		for (std::string spriteSheetPath : spriteSheetPaths) {
			SDL_Texture* spriteSheet = renderer->imageLoad(spriteSheetPath, sdlRenderer, hardwareAbstractionLayer);

			spriteSheets.emplace(spriteSheetPath, spriteSheet);
		}
	}
	catch (IOException& ex) {
		std::cout << ex.what() << std::endl;
		throw(ex);
	}
}

void OrionEntity::show(SDL_Renderer* gRenderer, HardwareAbstractionLayer * hardwareHandler, double cameraOffsetX, double cameraOffsetY)
{
	if (!spriteSheets.empty()) {
		SDL_Texture* image = spriteSheets.at(spriteSheetPaths[0]);
		SDL_Rect clip = { 0, 0, width, height };
		SDL_Rect renderQuad = { (int)(x - cameraOffsetX), (int)(y - cameraOffsetY), width, height };

		hardwareHandler->renderCopy(gRenderer, image, &clip, &renderQuad);
		//SDL_RenderCopy(gRenderer, image, &clip, &renderQuad);
	}
}

std::set<Hitbox *>* OrionEntity::getHitboxes() {
	std::set<Hitbox *>* copies = new std::set<Hitbox *>();
	
	for (Hitbox * hitbox : hitboxes) {
		copies->insert(hitbox);
	}

	return copies;
}

int OrionEntity::getZIndex() {
	return zIndex;
}

bool OrionEntity::isCollidingWith(Hitbox* hitbox) {
	bool isCollidingWith = false;

	for (Hitbox* h : hitboxes) {
		isCollidingWith = h->isColliding(hitbox);

		if (isCollidingWith) {
			break;
		}
	}

	return isCollidingWith;
}

std::string OrionEntity::getName() {
	return name;
}

double OrionEntity::getX() {
	return x;
}

double OrionEntity::getY() {
	return y;
}
 