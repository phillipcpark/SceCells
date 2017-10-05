#include "AveragedBlockStrategy.h"


#include <iostream>

AveragedBlockStrategy::AveragedBlockStrategy() {
	blockSize = BLOCK_SIZE;	
	currentCount = 0;
	time = 0;
}

void AveragedBlockStrategy::stop(float time) {	
	currentCount++;
	this->time += time;

	if (currentCount == blockSize) {
		float average = this->time / (float)blockSize;
		outputStream->write(average);

		if (rowEnd)
			outputStream->newRow();
		else
			outputStream->newColumn();
	
		currentCount = 0;
		this->time = 0;
	}
}

