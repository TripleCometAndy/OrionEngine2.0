#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "OrionEntity.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

class Orb : public OrionEntity {
public:
	Orb(double x, double y, std::vector<std::string>* spriteSheetPaths);

	void handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap);
	void enactStateChanges();
	void setPosition(double xPos, double yPos);
};