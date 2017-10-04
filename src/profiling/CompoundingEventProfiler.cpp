#include "CompoundingEventProfiler.h"

CompoundingEventProfiler::CompoundingEventProfiler(std::string identifier, bool rowEnd): Profiler(identifier, rowEnd) {
	time = 0;
}

CompoundingEventProfiler::~CompoundingEventProfiler() { 
	delete eventPacket;
}

void CompoundingEventProfiler::stop() {
	if (eventPacket != NULL) {	
		float lastTimeBlock = timer.getElapsedTime(eventPacket);	
		time += lastTimeBlock;	

		eventPacket = NULL;

std::cout << "\n\n\nPROFILER WRITING " << lastTimeBlock << "\n\n";

		outputStream->write(lastTimeBlock);
	
		if (!rowEnd)
			outputStream->newRow();
		else
			outputStream->newColumn();
	}
}

