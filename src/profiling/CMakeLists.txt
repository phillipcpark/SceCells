include_directories(${COMMON_INCLUDES})

add_library(SceProfiling
	Profiler.h
	Profiler.cpp
	SingleEventProfiler.h
	SingleEventProfiler.cpp
	CompoundingEventProfiler.h
	CompoundingEventProfiler.cpp
	ProfilingCoordinator.h
	ProfilingCoordinator.cpp
	CudaEventLifecycleHandler.h
	CudaEventLifecycleHandler.cpp
)

