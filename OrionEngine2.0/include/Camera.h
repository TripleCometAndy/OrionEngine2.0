#ifndef _ORION_ENTITY
#define _ORION_ENTITY
#include "OrionEntity.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

class Camera : public OrionEntity {
public:
	Camera();

	void handleStateChanges(std::set<InputType>* currentInputs, CollisionMap * collisionMap);
	void enactStateChanges();
};