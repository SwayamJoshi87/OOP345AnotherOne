#include <chrono>
#include <iostream>

#ifndef SDDS_TIMER_H_
#define SDDS_TIMER_H_

namespace sdds {

	class Timer {
		std::chrono::steady_clock::time_point startPoint;
		std::chrono::steady_clock::time_point endPoint;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H_

