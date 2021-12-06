#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "OrionEntity.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

#ifndef _COLLISION_MAP
#define _COLLISION_MAP
#include "CollisionMap.h"
#endif


#include <vector>
#include <set>

class EntityManager {
private:
	std::vector<OrionEntity*> entities;
	std::set<InputType>* currentInputs;
	CollisionMap* collisionMap;
public:
	EntityManager(CollisionMap * collisionMap);
	void addEntity(OrionEntity* entity);
	void loadFiles(Renderer* renderer, SDL_Renderer* sdlRenderer, HardwareAbstractionLayer* hardwareAbstractionLayer);
	void showAll(SDL_Renderer* gRenderer, HardwareAbstractionLayer * hardwareHandler);
	void setInputs(std::set<InputType>* events);
	void handleStateChanges();
	void enactStateChanges();
	int getEntityX(std::string entityName);
	int getEntityY(std::string entityName);
};