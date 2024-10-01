#ifndef CPPLIBFT_HPP
# define CPPLIBFT_HPP

# include <iostream>

template <typename T1, typename T2>
std::ostream	&operator<<(std::ostream &os, const std::pair<T1, T2> &ref)
{
	return (os << ref.first << ": " << ref.second);
}

# include "ansi.hpp"
# include "string.hpp"
# include "logging.hpp"
# include "debug.hpp"

#endif
