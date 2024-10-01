#ifndef RANGE_MAP_LOGGER_HPP
# define RANGE_MAP_LOGGER_HPP

# include <iostream>
# include <string>

/**
 * @brief 
 * 
 * @note This class does not hold ownership of anything provided in the range
 */
template <typename InputIterator, class Callable>
struct RangeMapLogger
{
	public:
		const InputIterator	begin;
		const InputIterator	end;
		const Callable		f;
		const std::string	delimiter;

		RangeMapLogger(const InputIterator begin, const InputIterator end, const Callable f, const std::string &delimiter = ", ");
		RangeMapLogger(const RangeMapLogger &ref);
		~RangeMapLogger(void);
	private:
		RangeMapLogger(void);
		RangeMapLogger	&operator=(const RangeMapLogger &ref);
};

template <typename InputIterator, class Callable>
std::ostream	&operator<<(std::ostream &os, const RangeMapLogger<InputIterator, Callable> &ref);

# include "RangeMapLogger.tpp"

template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>
makeRangeMapLogger(const InputIterator begin, const InputIterator end, const Callable f)
{
	return (RangeMapLogger<InputIterator, Callable>(begin, end, f));
}

template <typename InputIterator, class Callable>
RangeMapLogger<InputIterator, Callable>
makeRangeMapLogger(const InputIterator begin, const InputIterator end, const Callable f, const std::string &delimiter)
{
	return (RangeMapLogger<InputIterator, Callable>(begin, end, f, delimiter));
}

template <class Container, class Callable>
RangeMapLogger<typename Container::const_iterator, Callable>
makeRangeMapLogger(const Container &container, const Callable f)
{
	return (makeRangeMapLogger(container.begin(), container.end(), f));
}

template <class Container, class Callable>
RangeMapLogger<typename Container::const_iterator, Callable>
makeRangeMapLogger(const Container &container, const Callable f, const std::string &delimiter)
{
	return (makeRangeMapLogger(container.begin(), container.end(), f, delimiter));
}

#endif
