#include "ProfilingCoordinator.h"

std::vector<Profiler*> ProfilingCoordinator::profilers = std::vector<Profiler*>();

ProfilingCoordinator::~ProfilingCoordinator() {
	for (std::vector<Profiler*>::iterator iter = profilers.begin(); iter != profilers.end(); iter++)
		delete *iter;

	profilers.clear();
}

unsigned ProfilingCoordinator::addProfiler(Profiler* child) const {
	ProfilingCoordinator::profilers.push_back(child);
	unsigned index = ProfilingCoordinator::profilers.size() - 1;

	return index;
}

void ProfilingCoordinator::startProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->start();
}

void ProfilingCoordinator::updateProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->update();	
}

void ProfilingCoordinator::stopProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->stop();
}

float ProfilingCoordinator::getProfilerTime(unsigned index) const {
	return ProfilingCoordinator::profilers.at(index)->getTime();
}


