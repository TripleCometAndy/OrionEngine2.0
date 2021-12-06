#ifndef _EVENT_HANDLER
#define _EVENT_HANDLER
#include "EventHandler.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

class EventHandlerImpl : public EventHandler {
private:
	HardwareAbstractionLayer* hardwareAbstractionLayer;
public:
	EventHandlerImpl(HardwareAbstractionLayer* hardwareAbstractionLayer);
	void handleEvents(bool* shouldQuit, EntityManager* entityManager);
};