#ifndef _ENTITY_MANAGER
#define _ENTITY_MANAGER
#include "../include/EntityManager.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "../include/InputType.h"
#endif

#ifndef _COLLISION_MAP
#define _COLLISION_MAP
#include "../include/CollisionMap.h"
#endif

#ifndef _CAMERA
#define _CAMERA
#include "Camera.h"
#endif

#ifndef _ORB
#define _ORB
#include "Orb.h"
#endif

#ifndef _WALL
#define _WALL
#include "Wall.h"
#endif

#include "../include/instanceof.h"


#include <iostream>
#include <algorithm>

EntityManager::EntityManager(CollisionMap * collisionMap) {
	this->collisionMap = collisionMap;
}

void EntityManager::addEntity(OrionEntity* entity) {
	entities.push_back(entity);

	//Add hitboxes to collision map
	std::set<Hitbox *> * hitboxes = entity->getHitboxes();

	collisionMap->addHitboxes(hitboxes);
}

void EntityManager::loadFiles(Renderer* renderer, SDL_Renderer* sdlRenderer, HardwareAbstractionLayer * hardwareAbstractionLayer) {
	for (OrionEntity* entity : entities) {
		entity->load_files(renderer, sdlRenderer, hardwareAbstractionLayer);
	}
}

void EntityManager::showAll(SDL_Renderer* gRenderer, HardwareAbstractionLayer * hardwareHandler) {
	//Get Camera
	Camera* camera;
	for (OrionEntity* entity : entities) {
		if ((camera = dynamic_cast<Camera*>(entity)) != nullptr) {
			break;
		}
	}

	//Get every entity that is colliding with the camera's hitbox
	std::set<Hitbox *>* cameraHitbox = camera->getHitboxes();

	Hitbox * cHitbox;
	for (Hitbox * h : *cameraHitbox) {
		cHitbox = h;
		break;
	}

	std::set<OrionEntity * > entitiesToRender = collisionMap->getCollidingEntities(cHitbox);

	std::vector<OrionEntity*> sortedEntities;

	std::copy(entitiesToRender.begin(), entitiesToRender.end(), std::back_inserter(sortedEntities));

	std::sort(std::begin(sortedEntities), std::end(sortedEntities),
		[](OrionEntity* a, OrionEntity* b) { return a->getZIndex() < b->getZIndex(); });

	for (OrionEntity* entity : sortedEntities) {
		entity->show(gRenderer, hardwareHandler, cHitbox->x, cHitbox->y);
	}
}

void EntityManager::setInputs(std::set<InputType>* events) {
	this->currentInputs = events;
}

void EntityManager::handleStateChanges() {
	for (OrionEntity* entity : entities) {
		entity->handleStateChanges(currentInputs, collisionMap);
	}
}

void EntityManager::enactStateChanges() {
	for (OrionEntity* entity : entities) {
		entity->enactStateChanges();

		std::set<Hitbox*>* hitboxes = entity->getHitboxes();
		collisionMap->updateEntityPosition(hitboxes);
	}
}

int EntityManager::getEntityX(std::string entityName) {
	OrionEntity* orb;
	for (OrionEntity* entity : entities) {
		if (entity->getName().compare("ORB") == 0) {
			orb = entity;
		}
	}

	return orb->getX();
}

int EntityManager::getEntityY(std::string entityName) {
	OrionEntity* orb;
	for (OrionEntity* entity : entities) {
		if (entity->getName().compare("ORB") == 0) {
			orb = entity;
		}
	}

	return orb->getY();
}