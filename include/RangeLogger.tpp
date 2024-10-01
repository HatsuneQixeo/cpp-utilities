#ifndef RANGE_LOGGER_TPP
# define RANGE_LOGGER_TPP

# include "RangeLogger.hpp"

/* Constructors && Destructor */
template <typename InputIterator>
RangeLogger<InputIterator>::RangeLogger(void)
{}

template <typename InputIterator>
RangeLogger<InputIterator>::RangeLogger(const InputIterator begin, const InputIterator end, const std::string &delimiter):
	begin(begin),
	end(end),
	delimiter(delimiter)
{}

template <typename InputIterator>
RangeLogger<InputIterator>::RangeLogger(const RangeLogger &ref):
	begin(ref.begin),
	end(ref.end),
	delimiter(ref.delimiter)
{}

template <typename InputIterator>
RangeLogger<InputIterator>::~RangeLogger(void)
{}


/* Operator Overloads */
template <typename InputIterator>
RangeLogger<InputIterator>	&RangeLogger<InputIterator>::operator=(const RangeLogger &ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}


/* Log */
template <typename InputIterator>
std::ostream	&operator<<(std::ostream &os, const RangeLogger<InputIterator> &ref)
{
	if (ref.begin == ref.end)
		return (os);
	os << *ref.begin;
	for (InputIterator it = std::next(ref.begin); it != ref.end; ++it)
		os << ref.delimiter << *it;
	return (os);
}

#endif
