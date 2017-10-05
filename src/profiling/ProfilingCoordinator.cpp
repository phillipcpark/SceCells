#include "ProfilingCoordinator.h"

//static member definitions
std::vector<Profiler*> ProfilingCoordinator::profilers = std::vector<Profiler*>();
OFStreamCSV* ProfilingCoordinator::strategyOutputStream = new OFStreamCSV(STRATEGY);
OFStreamCSV* ProfilingCoordinator::summingOutputStream = new OFStreamCSV(SUMMED);

unsigned ProfilingCoordinator::addProfiler(Profiler* child) const {
	ProfilingCoordinator::profilers.push_back(child);

	child->setStrategyOutputStream(ProfilingCoordinator::strategyOutputStream);
	child->setSummingOutputStream(ProfilingCoordinator::summingOutputStream);

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
	ProfilingCoordinator::summingOutputStream->close();
}

