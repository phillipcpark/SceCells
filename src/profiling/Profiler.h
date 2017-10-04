#ifndef PROFILER_H
#define PROFILER_H

#include <iostream>
#include "CudaEventLifecycleHandler.h"
#include "OFStreamCSV.h"

class Profiler {
	protected:
		CudaEventLifecycleHandler timer;
		CudaEventPacket* eventPacket;
		OFStreamCSV* outputStream;
	
		std::string identifier;
		float time;
		bool rowEnd;

		Profiler(std::string identifier, bool rowEnd = false);
	public:
		virtual ~Profiler()=0;
		void start();
		virtual void stop()=0;
		std::string getID();
		float getTime();
		void setOutputStream(OFStreamCSV*);
};

#endif

