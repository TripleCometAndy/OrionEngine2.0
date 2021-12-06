#ifndef _TIMER
#define _TIMER
#include "Timer.h"
#endif

#ifndef _HARDWARE_ABSTRACTION_LAYER
#define _HARDWARE_ABSTRACTION_LAYER
#include "HardwareAbstractionLayer.h"
#endif

class TimerImpl : public Timer {
private:
	bool started;
	int startTicks;
	HardwareAbstractionLayer* hardwareAbstractionLayer;
public:
	TimerImpl(HardwareAbstractionLayer* hardwareAbstractionLayer);

	void start();
	int getTime();
	int getTicks();
};