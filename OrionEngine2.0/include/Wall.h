#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "OrionEntity.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

class Wall : public OrionEntity {
public:
	Wall(double x, double y, int width, int height, std::vector<std::string>* spriteSheetPaths);

	void handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap);
	void enactStateChanges();
	void setPosition(double xPos, double yPos);
};