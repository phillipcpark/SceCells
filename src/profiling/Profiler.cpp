#include "Profiler.h"

Profiler::~Profiler() {}

void Profiler::start() {
	std::cout << "\n\nPROFILER CREATED EVENT PACKET\n\n";
	eventPacket = timer.start();
	std::cout << "\n\nTIMER STARTED\n\n";
}

float Profiler::getTime() {
	return time;
}


