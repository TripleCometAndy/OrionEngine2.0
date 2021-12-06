#ifndef _WALL
#define _WALL
#include "../include/Wall.h"
#endif

#ifndef _HITBOX
#define _HITBOX
#include "../include/Hitbox.h"
#endif

#include <iostream>

Wall::Wall(double x, double y, int width, int height, std::vector<std::string>* spriteSheetPaths) {
	this->x = x;
	this->y = y;
	futureX = x;
	futureY = y;
	this->width = width;
	this->height = height;
	zIndex = 2;
	name = "WALL";

	for (std::string path : *spriteSheetPaths) {
		this->spriteSheetPaths.push_back(path);
	}

	Hitbox* hitbox = new Hitbox();
	hitbox->x = x;
	hitbox->y = y;
	hitbox->width = width;
	hitbox->height = height;
	hitbox->parent = this;

	hitboxes.insert(hitbox);
}

void Wall::handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap) {
}

void Wall::setPosition(double xPos, double yPos) {
}

void Wall::enactStateChanges() {
}