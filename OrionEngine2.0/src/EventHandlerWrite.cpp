#ifndef _EVENT_HANDLER_WRITE
#define _EVENT_HANDLER_WRITE
#include "../include/EventHandlerWrite.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

#include <set>

EventHandlerWrite::EventHandlerWrite(std::string pathToInputs) {
	currentFrame = 0;

	//Open filestream
    fs.open(pathToInputs.c_str(), std::ofstream::out | std::ofstream::trunc);
}

void EventHandlerWrite::handleEvents(bool* shouldQuit, EntityManager* entityManager) {
    SDL_Event e;
    std::set<InputType>* events = new std::set<InputType>();

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
            *shouldQuit = true;
            events->insert(InputType::QUIT);
        }
        else if (e.type == SDL_KEYDOWN) {
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

    //Write inputs to file
    if (events->size() > 0) {
        writeInputsToFile(events);
    }
    

    //Iterate frame
    currentFrame++;
}

void EventHandlerWrite::writeInputsToFile(std::set<InputType>* events) {
    fs << currentFrame;
    fs << ":";
    
    for (InputType event : *events) {
        fs << event;
        fs << ",";
    }
    
    fs << "\n";
}