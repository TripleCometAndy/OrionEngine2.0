#ifndef _TIMER_IMPL
#define _TIMER_IMPL
#include "../include/TimerImpl.h"
#endif

TimerImpl::TimerImpl(HardwareAbstractionLayer * hardwareAbstractionLayer) {
	this->hardwareAbstractionLayer = hardwareAbstractionLayer;
	started = false;
	startTicks = 0;
}

void TimerImpl::start() {
	//Start the timer
	started = true;
	startTicks = hardwareAbstractionLayer->getTicks();
}

int TimerImpl::getTicks() {
	int numTicks = 0;

	//If the timer is running
	if (started)
	{
		//Return the current time minus the start time
		numTicks = hardwareAbstractionLayer->getTicks() - startTicks;
	}

	return numTicks;
}

int TimerImpl::getTime() {
	return hardwareAbstractionLayer->getTicks();
}