#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

#ifndef _TIMER
#define _TIMER
#include "Timer.h"
#endif

#ifndef _EVENT_HANDLER
#define _EVENT_HANDLER
#include "EventHandler.h"
#endif

#ifndef _RENDERER
#define _RENDERER
#include "Renderer.h"
#endif

#ifndef _OPTIONS
#define _OPTIONS
#include "Options.h"
#endif


class OrionLoop {
private:
	unsigned int FPS;
	HardwareAbstractionLayer* sdlHandler;
	Timer* timer;
	EventHandler* eventHandler;
	Renderer* renderer;
	EntityManager* entityManager;

public:
	OrionLoop(Options * options, HardwareAbstractionLayer * sdlHandler, Timer * timer, EventHandler * eventHandler, Renderer * renderer);

	void initialize();
	void execute();
	int getEntityX(std::string entityName);
	int getEntityY(std::string entityName);
};