#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

namespace Sparky {

	class Timer
	{
	private:
		steady_clock::time_point m_startTime;
		steady_clock::time_point m_currentTime;
	
	public:
		Timer()
		{
			reset();
		}


		void reset()
		{
			m_startTime = steady_clock::now();
		}


		double deltaTime()
		{
			m_currentTime = steady_clock::now();

			steady_clock::duration d = m_currentTime - m_startTime;
			
			double a = duration_cast<microseconds>(d).count() / 1000000.0f;
			
			return a;
		}
	};

}

#endif
