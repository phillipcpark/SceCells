#include "ProfilingCoordinator.h"

std::vector<Profiler*> ProfilingCoordinator::profilers = std::vector<Profiler*>();
OFStreamCSV* ProfilingCoordinator::outputStream = OFStreamCSV*;

unsigned ProfilingCoordinator::addProfiler(Profiler* child) const {
	ProfilingCoordinator::profilers.push_back(child);
	unsigned index = ProfilingCoordinator::profilers.size() - 1;

	return index;
}

void ProfilingCoordinator::startProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->start();
}

void ProfilingCoordinator::stopProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->stop();
}

float ProfilingCoordinator::getProfilerTime(unsigned index) const {
	return ProfilingCoordinator::profilers.at(index)->getTime();
}

std::string ProfilingCoordinator::getProfilerID(unsigned index) const {
	return ProfilingCoordinator::profilers.at(index)->getID();
}
