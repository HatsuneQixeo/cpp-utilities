#include "SimpleClock.hpp"

template <typename Unit>
typename SimpleClock<Unit>::GetTime	SimpleClock<Unit>::getCurrentTime = std::chrono::high_resolution_clock::now;

/* Constructor && Destructor */
template <typename Unit>
SimpleClock<Unit>::SimpleClock(const std::string &name):
	name(name),
	start(getCurrentTime())
{}

template <typename Unit>
SimpleClock<Unit>::SimpleClock(const SimpleClock &ref)
{
	*this = ref;
}

template <typename Unit>
SimpleClock<Unit>::~SimpleClock(void)
{
	const double	duration = this->elapsed();

	std::cout << "[Clock]" << name << ": " << duration << std::endl;
	this->start = getCurrentTime();
}


/* Operator Overload */
template <typename Unit>
SimpleClock<Unit>	&SimpleClock<Unit>::operator=(const SimpleClock<Unit> &ref)
{
	/* Copy assignment */
	return (*this);
	(void)ref;
}


/* MemberFunctions */
template <typename Unit>
double	SimpleClock<Unit>::elapsed(void)
{
	const Time	now = getCurrentTime();
	const long	duration = std::chrono::duration_cast<Unit>(now - this->start).count();

	return (duration * 0.001);
}

template <typename Unit>
void	SimpleClock<Unit>::rename(const std::string &newName)
{
	this->name = newName;
}
