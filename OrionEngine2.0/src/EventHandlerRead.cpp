#ifndef _EVENT_HANDLER_READ
#define _EVENT_HANDLER_READ
#include "../include/EventHandlerRead.h"
#endif

#ifndef _INPUT_TYPE
#define _INPUT_TYPE
#include "InputType.h"
#endif

#include <set>
#include <fstream>
#include <iostream>

EventHandlerRead::EventHandlerRead(std::string pathToInputs) {
    currentFrame = 0;

    std::ifstream myfile(pathToInputs);

	//Read all the inputs into memory (as a hashmap)

    std::string line;
    while (std::getline(myfile, line)) {
        std::string frameNum = line.substr(0, line.find(':'));
        int integerFrameNum = std::stoi(frameNum);

        std::string inputs = line.substr(line.find(":") + 1, line.size());
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;

        int integerToken = 0;
        std::set<InputType> inputsForFrame;
        while ((pos = inputs.find(delimiter)) != std::string::npos) {
            token = inputs.substr(0, pos);
            integerToken = std::stoi(token);
            inputsForFrame.insert(static_cast<InputType>(integerToken));
            inputs.erase(0, pos + delimiter.length());
        }
        std::cout << inputs << std::endl;

        if (inputs.size() > 0) {
            integerToken = std::stoi(inputs);

            inputsForFrame.insert(static_cast<InputType>(integerToken));
        }


        std::pair<int, std::set<InputType>> input(integerFrameNum, inputsForFrame);

        this->readInputs.insert(input);
    }
}

void EventHandlerRead::handleEvents(bool* shouldQuit, EntityManager* entityManager) {
    SDL_Event e;
    std::unordered_map<int, std::set<InputType>>::const_iterator got = readInputs.find(currentFrame);

    std::set<InputType>* events = new std::set<InputType>();

    if (got != readInputs.end()) {
        for (InputType input : got->second) {
            if (input == InputType::QUIT) {
                *shouldQuit = true;
            }

            events->insert(input);
        }
    }

    if (!(*shouldQuit)) {
        entityManager->setInputs(events);
    }

    currentFrame++;
}