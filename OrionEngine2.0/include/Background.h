#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "OrionEntity.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

class Background : public OrionEntity {
public:
	Background(std::vector<std::string>* spriteSheetPaths);

	void handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap);
	void enactStateChanges();
};