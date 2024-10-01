#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <chrono>
# include "SimpleClock.hpp"
# include "logging.hpp"

/* Returns the elapsed time in microseconds unit */
# define PROFILE(code)	({\
	const std::chrono::steady_clock::time_point	__start__ = std::chrono::high_resolution_clock::now();\
	code;\
	const std::chrono::steady_clock::time_point	__end__ = std::chrono::high_resolution_clock::now();\
	std::chrono::duration_cast<std::chrono::microseconds>(__end__ - __start__).count();\
})

std::ostream	&showFDUsage(std::ostream &os);

#endif
