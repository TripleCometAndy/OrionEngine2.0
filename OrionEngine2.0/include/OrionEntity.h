#ifndef _RENDERER
#define _RENDERER
#include "Renderer.h"
#endif

#ifndef _SDL
#define _SDL
#include "../sdlInclude/include/SDL.h"
#include "../sdlInclude/include/SDL_image.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

#ifndef _HITBOX
#define _HITBOX
#include "Hitbox.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

#ifndef _COLLISION_MAP
#define _COLLISION_MAP
#include "../include/CollisionMap.h"
#endif

#include <unordered_map>
#include <vector>
#include <set>

class OrionEntity {
protected:
	std::vector<std::string> spriteSheetPaths;
	std::unordered_map<std::string, SDL_Texture*> spriteSheets;
	std::set<Hitbox *> hitboxes;
	std::string name;

	double x;
	double y;
	int width;
	int height;
	int zIndex;

	//Futures
	double futureX;
	double futureY;
	double futureWidth;
	double futureHeight;

public:
	OrionEntity();

	void load_files(Renderer* renderer, SDL_Renderer* sdlRenderer, HardwareAbstractionLayer * hardwareAbstractionLayer);
	void show(SDL_Renderer* gRenderer, HardwareAbstractionLayer* hardwareHandler, double cameraOffsetX, double cameraOffsetY);
	std::set<Hitbox *>* getHitboxes();
	int getZIndex();
	std::string getName();
	double getX();
	double getY();
	bool isCollidingWith(Hitbox* hitbox);

	virtual void handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap) = 0;
	virtual void enactStateChanges() = 0;
};