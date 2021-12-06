# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

IF (WIN32)
	message("WIN32")

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

	file(COPY sdlLibWin/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

	project (orion)
	include_directories(src)
	link_directories(sdlLibWin)

	add_subdirectory(src)
	add_subdirectory(tests)
	add_subdirectory(lib/googletest)
	add_subdirectory(lib/rapidcheck) 
	#target_link_libraries(my_target rapidcheck)


ENDIF()

IF (UNIX)
	message("UNIX")

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY OrionEngine2/bin)

	project (orion)

	include_directories(OrionEngine2/sdlInclude/include)

	SET(SOURCES OrionEngine2/OrionEngine2.cpp)

	link_directories(OrionEngine2/sdlLibUnix)
	add_executable(orion ${SOURCES} )

	target_link_libraries(orion SDL2 sndio)
ENDIF()


