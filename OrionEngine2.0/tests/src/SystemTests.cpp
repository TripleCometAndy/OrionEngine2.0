#include "gtest/gtest.h"


#ifndef _OPTIONS_LOADER
#define _OPTIONS_LOADER
#include "../../../include/OptionsLoader.h"
#endif

#ifndef _ORION_LOOP
#define _ORION_LOOP
#include "../../../include/OrionLoop.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "../../../include/HardwareAbstractionLayer.h"
#endif

#ifndef _TIMER
#define _TIMER
#include "../../../include/Timer.h"
#endif

#ifndef _TIMER_IMPL
#define _TIMER_IMPL
#include "../../../include/TimerImpl.h"
#endif

#ifndef _EVENT_HANDLER_IMPL
#define _EVENT_HANDLER_IMPL
#include "../../../include/EventHandlerImpl.h"
#endif

#ifndef _EVENT_HANDLER_READ
#define _EVENT_HANDLER_READ
#include "../../../include/EventHandlerRead.h"
#endif

#ifndef _RENDERER_IMPL
#define _RENDERER_IMPL
#include "../../../include/RendererImpl.h"
#endif

#ifndef _DECOUPLED_HARDWARE_ABSTRACTION_LAYER
#define _DECOUPLED_HARDWARE_ABSTRACTION_LAYER
#include "../../../include/DecoupledHardwareAbstractionLayer.h"
#endif

#include <iostream>


TEST(SystemTests, test1) {
    Options* options = getOptions("C:/Users/might/Downloads/Options.txt");
    HardwareAbstractionLayer* sdlHandler = new DecoupledHardwareAbstractionLayer();

    EventHandler* eventHandler;
    if (options->areEventsReadFromFile) {
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

    int orbX = orionLoop->getEntityX("ORB");
    int orbY = orionLoop->getEntityY("ORB");

    ASSERT_EQ(orbX, 552);
    ASSERT_EQ(orbY, 844);
};