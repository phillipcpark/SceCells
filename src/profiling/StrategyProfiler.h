#ifndef STRATEGY_PROFILER_H
#define STRATEGY_PROFILER_H

#include "Profiler.h"
#include "ProfilingStrategy.h"

class StrategyProfiler: public Profiler {
	protected:
		ProfilingStrategy* strategy;
		void setChildOutputStream();			
	public:
		StrategyProfiler(std::string identifier, ProfilingStrategy* strategy, bool rowEnd = false);
		~StrategyProfiler();
		void stop();
		void setOutputStream(OFStreamCSV* outputStream);
};

#endif
