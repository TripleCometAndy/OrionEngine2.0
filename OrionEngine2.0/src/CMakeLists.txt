set(BINARY orion)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
 
include_directories(../sdlInclude/include ../include)

file(COPY ../sdlLibWin/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
file(COPY ../sdlLibWin/SDL2_image.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
file(COPY ../Options.txt DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)

SET(SOURCES OrionEngine2.cpp Formula.cpp IsPrime.cpp "main.cpp" "OptionsLoader.cpp" "CollisionMap.cpp" "OrionLoop.cpp" "EventHandler.cpp" "Renderer.cpp" "Timer.cpp" "HardwareAbstractionLayer.cpp" "SDLHandler.cpp" "TimerImpl.cpp" "EventHandlerImpl.cpp" "OrionEntity.cpp" "Background.cpp" "RendererImpl.cpp" "EntityManager.cpp" "Orb.cpp" "EventHandlerRead.cpp" "EventHandlerWrite.cpp" "Camera.cpp" "Wall.cpp" "DecoupledHardwareAbstractionLayer.cpp")

add_executable(orion ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(orion SDL2 SDL2main SDL2_image SDL2.dll SDL2_image.dll)