#ifndef RANGE_MAP_LOGGER_TPP
# define RANGE_MAP_LOGGER_TPP

# include "RangeMapLogger.hpp"

/* Constructors && Destructor */
template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>::RangeMapLogger(void)
{}

template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>::RangeMapLogger(const InputIterator begin,
			const InputIterator end,
			const Callable f,
			const std::string &delimiter):
	begin(begin),
	end(end),
	f(f),
	delimiter(delimiter)
{}

template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>::RangeMapLogger(const RangeMapLogger &ref):
	begin(ref.begin),
	end(ref.end),
	f(ref.f),
	delimiter(ref.delimiter)
{}

template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>::~RangeMapLogger(void)
{}


/* Operator Overloads */
template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>	&RangeMapLogger<InputIterator, Callable>::operator=(const RangeMapLogger &ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}


/* Log */
template <typename InputIterator, class Callable>
std::ostream	&operator<<(std::ostream &os, const RangeMapLogger<InputIterator, Callable> &ref)
{
	if (ref.begin == ref.end)
		return (os);
	os << ref.f(*ref.begin);
	for (InputIterator it = std::next(ref.begin); it != ref.end; ++it)
		os << ref.delimiter << ref.f(*it);
	return (os);
}

#endif
