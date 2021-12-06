#ifndef _ORION_LOOP
#define _ORION_LOOP
#include "OrionLoop.h"
#endif

#ifndef _BACKGROUND
#define _BACKGROUND
#include "Background.h"
#endif

#ifndef _ORB
#define _ORB
#include "Orb.h"
#endif

#ifndef _COLLISION_MAP
#define _COLLISION_MAP
#include "../include/CollisionMap.h"
#endif

#ifndef _ENTITY_MANAGER
#define _ENTITY_MANAGER
#include "EntityManager.h"
#endif

#ifndef _CAMERA
#define _CAMERA
#include "Camera.h"
#endif

#ifndef _WALL
#define _WALL
#include "Wall.h"
#endif

#include <iostream>

OrionLoop::OrionLoop(Options* options, HardwareAbstractionLayer* sdlHandler, Timer* timer, EventHandler* eventHandler, Renderer* renderer) {
	this->FPS = options->FPS;
	this->sdlHandler = sdlHandler;
	this->timer = timer;
	this->eventHandler = eventHandler;
	this->renderer = renderer;
}

void OrionLoop::initialize() {

}

void OrionLoop::execute() {
	int TICKS_PER_FRAME = 1000 / FPS;

	SDL_Joystick* gGameController = NULL;
	SDL_Window* window = NULL;
	SDL_Renderer* sdlRenderer = NULL;
	bool hasController = false;

	sdlHandler->init(710, 702, &window, &sdlRenderer, false, &gGameController, &hasController);

	std::vector<std::string> backgroundPaths;
	backgroundPaths.push_back("C:/Users/might/Downloads/background.jpg");

	OrionEntity* b = new Background(&backgroundPaths);
	
	std::vector<std::string> orbPaths;
	orbPaths.push_back("C:/Users/might/Downloads/orb.png");

	OrionEntity* o = new Orb(700, 700, &orbPaths);

	std::vector<std::string> wallPaths;
	wallPaths.push_back("C:/Users/might/Downloads/wall.png");

	OrionEntity* w = new Wall(400, 400, 40, 900, &wallPaths);
	OrionEntity* w2 = new Wall(400, 400, 800, 40, &wallPaths);
	OrionEntity* w3 = new Wall(1075, 400, 40, 900, &wallPaths);
	OrionEntity* w4 = new Wall(400, 1075, 800, 40, &wallPaths);

	Camera* c = new Camera();

	CollisionMap* collisionMap = new CollisionMap(2000, 2000, 107);

	//Instantiate EntityManager
	this->entityManager = new EntityManager(collisionMap);

	//Add entities to entity manager
	entityManager->addEntity(b);
	entityManager->addEntity(o);
	entityManager->addEntity(w);
	entityManager->addEntity(w2);
	entityManager->addEntity(w3);
	entityManager->addEntity(w4);
	entityManager->addEntity(c);

	//EntityManager.loadFiles
	entityManager->loadFiles(renderer, sdlRenderer, sdlHandler);

	bool quit = false;

	int simulationTime = 0;

	while (!quit) {
		timer->start();
		int realTime = timer->getTime();

		while (simulationTime < realTime) {
			eventHandler->handleEvents(&quit, entityManager);
			entityManager->handleStateChanges();
			entityManager->enactStateChanges();
			simulationTime += 16;
		}

		sdlHandler->setRenderDrawColor(sdlRenderer, 0xAF, 0xBF, 0xCF, 0xFF);
		sdlHandler->renderClear(sdlRenderer);
		entityManager->showAll(sdlRenderer, sdlHandler);
		sdlHandler->renderPresent(sdlRenderer);

		int frameTicks = timer->getTicks();

		if (frameTicks < TICKS_PER_FRAME) {
			sdlHandler->delay(TICKS_PER_FRAME - frameTicks);
		}
		else if (frameTicks > TICKS_PER_FRAME){
			sdlHandler->delay(frameTicks - TICKS_PER_FRAME);
		}
	}

	int orbX = getEntityX("ORB");
	int orbY = getEntityY("ORB");

	std::cout << "ORBB: " << orbX << ", " << orbY << std::endl;
}

int OrionLoop::getEntityX(std::string entityName) {
	return entityManager->getEntityX(entityName);
}

int OrionLoop::getEntityY(std::string entityName) {
	return entityManager->getEntityY(entityName);
}