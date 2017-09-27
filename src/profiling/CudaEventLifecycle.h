#ifndef CUDA_EVENT_LIFECYCLE
#define CUDA_EVENT_LIFECYCLE

struct CudaEventPacket {
	cudaEvent_t* start;
	cudaEvent_t* stop;

	CudaEventPacket() {
		start = new cudaEvent_t();
		stop = new cudaEvent_t();
	}

	~CudaEventPacket() {
		delete start;
		delete stop;
	}
};

namespace CudaEventLifecycle {
	CudaEventPacket* start() {
		CudaEventPacket* eventPacket = new CudaEventPacket();	

		cudaEventCreate(eventPacket->start);
		cudaEventCreate(eventPacket->stop);		
		cudaEventRecord(*(eventPacket->start));

		return eventPacket;
	}

	float getElapsedTime(CudaEventPacket* eventPacket) {
		cudaEvent_t start = *(eventPacket->start);
		cudaEvent_t stop = *(eventPacket->stop);

		cudaEventRecord(stop, 0);
		cudaEventSynchronize(stop);
	
		float elapsedTime;
		cudaEventElapsedTime(&elapsedTime, start, stop);

		cudaEventDestroy(start);
		cudaEventDestroy(stop);
		delete eventPacket;

		return elapsedTime; 
	}
}

#endif
