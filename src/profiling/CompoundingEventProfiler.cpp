#include "CompoundingEventProfiler.h"

CompoundingEventProfiler::CompoundingEventProfiler(std::string identifier, bool rowEnd): Profiler(identifier, rowEnd) {
	time = 0;
	sampleSize = SAMPLE_SIZE;
	currentCount = 0;
}

CompoundingEventProfiler::~CompoundingEventProfiler() { 
	delete eventPacket;
}

void CompoundingEventProfiler::stop() {
	if (eventPacket != NULL) {	
		float lastTimeBlock = timer.getElapsedTime(eventPacket);	
		time += lastTimeBlock;	
		currentCount++;

std::cout << "\n\nADDING TIME OF " << lastTimeBlock << "\n\n";

		eventPacket = NULL;

		if (currentCount == sampleSize) {
			float average = time / (float)sampleSize;
			outputStream->write(average);

std::cout << "\n\nTOTAL COMPOUNDED TIME WAS \n\n" << time << " DIVIDED BY SAMPLE SIZE = " << average << "\n\n";

			if (rowEnd)
				outputStream->newRow();
			else
				outputStream->newColumn();
			
			currentCount = 0;
			time = 0;
		}
	}
}

