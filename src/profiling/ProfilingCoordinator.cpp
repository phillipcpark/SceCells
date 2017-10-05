#include "ProfilingCoordinator.h"

std::vector<Profiler*> ProfilingCoordinator::profilers = std::vector<Profiler*>();
OFStreamCSV* ProfilingCoordinator::strategyOutputStream = new OFStreamCSV();
//OFStreamCSV* ProfilingCoordinator::summedEventOutputStream = new OFStreamCSV();

unsigned ProfilingCoordinator::addProfiler(Profiler* child) const {
	ProfilingCoordinator::profilers.push_back(child);
	child->setOutputStream(ProfilingCoordinator::strategyOutputStream);
	unsigned index = ProfilingCoordinator::profilers.size() - 1;

	return index;
}

void ProfilingCoordinator::startProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->start();
}

void ProfilingCoordinator::stopProfiler(unsigned index) const {
	ProfilingCoordinator::profilers.at(index)->stop();
}

void ProfilingCoordinator::end() {
	ProfilingCoordinator::strategyOutputStream->close();
}

float ProfilingCoordinator::getProfilerTime(unsigned index) const {
	return ProfilingCoordinator::profilers.at(index)->getTime();
}

std::string ProfilingCoordinator::getProfilerID(unsigned index) const {
	return ProfilingCoordinator::profilers.at(index)->getID();
}
