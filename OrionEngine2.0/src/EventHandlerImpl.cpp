#ifndef _EVENT_HANDLER_IMPL
#define _EVENT_HANDLER_IMPL
#include "../include/EventHandlerImpl.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

#include <set>

EventHandlerImpl::EventHandlerImpl(HardwareAbstractionLayer* hardwareAbstractionLayer) {
    this->hardwareAbstractionLayer = hardwareAbstractionLayer;
}

void EventHandlerImpl::handleEvents(bool* shouldQuit, EntityManager* entityManager) {
    SDL_Event e;
    std::set<InputType> * events = new std::set<InputType>();

    // Handle events on queue
    while (hardwareAbstractionLayer->pollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
            *shouldQuit = true;
        }
        else if (e.type == SDL_KEYDOWN){
            SDL_Keycode keyCode = e.key.keysym.sym;

            switch (keyCode) {
                case SDLK_UP:
                    events->insert(InputType::UP_ARROW);
                    break;
                case SDLK_DOWN:
                    events->insert(InputType::DOWN_ARROW);
                    break;
                case SDLK_LEFT:
                    events->insert(InputType::LEFT_ARROW);
                    break;
                case SDLK_RIGHT:
                    events->insert(InputType::RIGHT_ARROW);
                    break;
            }
        }
    }

    if (!(*shouldQuit)) {
        entityManager->setInputs(events);
    }
}