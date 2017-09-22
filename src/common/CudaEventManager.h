#ifndef CUDA_EVENT_MANAGER
#define CUDA_EVENT_MANAGER

struct CudaEventPacket {
	cudaEvent_t* start;
	cudaEvent_t* stop;

	CudaEventPacket() {
		start = new cudaEvent_t();
		stop = new cudaEvent_t();
	}
};

class CudaEventManager {
	public:
		CudaEventPacket* start();
		float getElapsedTime(CudaEventPacket*);
};

CudaEventPacket* CudaEventManager::start() {
	CudaEventPacket* eventPacket = new CudaEventPacket();	

	cudaEventCreate(eventPacket->start);
	cudaEventCreate(eventPacket->stop);		
	cudaEventRecord(*(eventPacket->start));

	return eventPacket;
}

float CudaEventManager::getElapsedTime(CudaEventPacket* eventPacket) {
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

#endif
