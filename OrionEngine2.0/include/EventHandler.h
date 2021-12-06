#include "../sdlInclude/include/SDL.h"

#ifndef _ENTITY_MANAGER
#define _ENTITY_MANAGER
#include "EntityManager.h"
#endif

class EventHandler {
public:
	EventHandler();

	virtual void handleEvents(bool* shouldQuit, EntityManager * entityManager) = 0;
};