#include "Profiler.h"

Profiler::Profiler(std::string identifier, bool rowEnd) {
	this->identifier = identifier;
	this->rowEnd = rowEnd;
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

void Profiler::setOutputStream(OFStreamCSV* outputStream) {
	this->outputStream = outputStream;
	outputStream->write(identifier);

	if (rowEnd)
		outputStream->newRow();
	else
		outputStream->newColumn();
}	

