#include "../sdlInclude/include/SDL.h"

class Timer {
public:
	Timer();

	virtual void start() = 0;
	virtual int getTime() = 0;
	virtual int getTicks() = 0;
};