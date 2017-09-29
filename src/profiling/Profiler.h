#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include "CudaEventLifecycleHandler.h"

class Profiler {
	protected:
		CudaEventLifecycleHandler timer;
		CudaEventPacket* eventPacket;	
		std::string identifier;
		float time;

		Profiler(std::string);
	public:
		virtual ~Profiler()=0;
		void start();
		virtual void stop()=0;
		std::string getID();
		float getTime();
};

#endif

