#include "Timer.h"

namespace sdds {
	void Timer::start()
	{
		//takes the current timestamp and stores it in an attribute
		startPoint = std::chrono::steady_clock::now();
	}
	long long Timer::stop()
	{
		//stop the timer and return the time spent in a nano seconds
		endPoint = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint).count();
	}
}