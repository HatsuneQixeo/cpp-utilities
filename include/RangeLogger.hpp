#ifndef RANGE_LOGGER_HPP
# define RANGE_LOGGER_HPP

# include <iostream>
# include <string>

/**
 * @brief 
 * 
 * @note This class does not hold ownership of anything provided in the range
 */
template <typename InputIterator>
struct RangeLogger
{
	public:
		const InputIterator	begin;
		const InputIterator	end;
		const std::string	delimiter;

		RangeLogger(const InputIterator begin, const InputIterator end, const std::string &delimiter = ", ");
		RangeLogger(const RangeLogger &ref);
		~RangeLogger(void);
	private:
		RangeLogger(void);
		RangeLogger	&operator=(const RangeLogger &ref);
};

template <typename InputIterator>
std::ostream	&operator<<(std::ostream &os, const RangeLogger<InputIterator> &ref);

# include "RangeLogger.tpp"

template <typename InputIterator>
RangeLogger<InputIterator>	makeRangeLogger(const InputIterator begin, const InputIterator end)
{
	return (RangeLogger<InputIterator>(begin, end));
}

template <typename InputIterator>
RangeLogger<InputIterator>	makeRangeLogger(const InputIterator begin, const InputIterator end, const std::string &delimiter)
{
	return (RangeLogger<InputIterator>(begin, end, delimiter));
}

template <class Container>
RangeLogger<typename Container::const_iterator>	makeRangeLogger(const Container &container)
{
	return (makeRangeLogger(container.begin(), container.end()));
}

template <class Container>
RangeLogger<typename Container::const_iterator>	makeRangeLogger(const Container &container, const std::string &delimiter)
{
	return (makeRangeLogger(container.begin(), container.end(), delimiter));
}

#endif
