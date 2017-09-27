#include "ProfilingCoordinator.h"

std::vector<Profiler*> ProfilingCoordinator::profilers = std::vector<Profiler*>();
OFStreamCSV ProfilingCoordinator::outputCSV = OFStreamCSV();

unsigned ProfilingCoordinator::addProfiler(Profiler* child) const {
	ProfilingCoordinator::profilers.push_back(child);
	unsigned index = ProfilingCoordinator::profilers.size() - 1

	return index;
}

void ProfilingCoordinator::updateProfiler(unsigned index, Profiler* child {
	ProfilingCoordinator::profilers.at(index)->update(child);	
}



