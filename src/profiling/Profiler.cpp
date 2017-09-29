#include "Profiler.h"

Profiler::Profiler(std::string identifier) {
	this->identifier = identifier;
}

Profiler::~Profiler() {}

void Profiler::start() {
	eventPacket = timer.start();
}

std::string Profiler::getID() {
	return identifier;
}

float Profiler::getTime() {
	return time;
}


