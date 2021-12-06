#ifndef _OPTIONS_LOADER
#define _OPTIONS_LOADER
#include "OptionsLoader.h"
#endif

#ifndef _ORION_LOOP
#define _ORION_LOOP
#include "OrionLoop.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

#ifndef _SDL_HANDLER
#define _SDL_HANDLER
#include "SDLHandler.h"
#endif

#ifndef _TIMER
#define _TIMER
#include "Timer.h"
#endif

#ifndef _TIMER_IMPL
#define _TIMER_IMPL
#include "TimerImpl.h"
#endif

#ifndef _EVENT_HANDLER_IMPL
#define _EVENT_HANDLER_IMPL
#include "EventHandlerImpl.h"
#endif

#ifndef _EVENT_HANDLER_WRITE
#define _EVENT_HANDLER_WRITE
#include "EventHandlerWrite.h"
#endif

#ifndef _EVENT_HANDLER_READ
#define _EVENT_HANDLER_READ
#include "EventHandlerRead.h"
#endif

#ifndef _RENDERER_IMPL
#define _RENDERER_IMPL
#include "RendererImpl.h"
#endif

#include <iostream>


int main(int argc, char** argv)
{
    Options* options = getOptions("Options.txt");
    HardwareAbstractionLayer* sdlHandler = new SDLHandler();

    EventHandler* eventHandler;
    if (options->areEventsWrittenToFile) {
        std::cout << "WRITING TO FILE" << std::endl;
        std::cout << options->eventHandlerWritePath << std::endl;

        eventHandler = new EventHandlerWrite(options->eventHandlerWritePath);
    }
    else if (options->areEventsReadFromFile) {
        std::cout << "READING FROM FILE" << std::endl;
        
        eventHandler = new EventHandlerRead(options->eventHandlerReadPath);
    }
    else {
        std::cout << "NOT WRITING TO FILE" << std::endl;
        eventHandler = new EventHandlerImpl(sdlHandler);
    }

    
    Timer* timer = new TimerImpl(sdlHandler);
    Renderer* renderer = new RendererImpl();

    OrionLoop* orionLoop = new OrionLoop(options, sdlHandler, timer, eventHandler, renderer);
    orionLoop->initialize();
    orionLoop->execute();

    return 0;
}
