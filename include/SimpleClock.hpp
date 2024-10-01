#ifndef SIMPLECLOCK_HPP
# define SIMPLECLOCK_HPP

# include <chrono>
# include <iostream>

typedef std::chrono::milliseconds	Seconds;
typedef std::chrono::microseconds	MilliSeconds;
typedef std::chrono::nanoseconds	MicroSeconds;

template <typename Unit>
class SimpleClock
{
	public:
		typedef std::chrono::steady_clock::time_point	Time;
		typedef Time	(*const GetTime)(void);

		static const GetTime	getCurrentTime;
	private:
		std::string	name;
		Time		start;

		SimpleClock(const SimpleClock &ref);

		SimpleClock	&operator=(const SimpleClock &ref);

	public:
		SimpleClock(const std::string &name);
		~SimpleClock(void);


		double	elapsed(void);
		void	rename(const std::string &newName);

};

# include "SimpleClock.tpp"

#endif
