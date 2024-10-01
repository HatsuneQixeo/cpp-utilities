#ifndef LOGGING_HPP
# define LOGGING_HPP

# include "string.hpp"
# include "RangeLogger.hpp"
# include "RangeMapLogger.hpp"

namespace map
{
	struct dereference
	{
		template <typename P>
		const typename std::iterator_traits<P>::value_type	&operator()(const P &ptr) const
		{
			return (*ptr);
		}
	};

	struct wrap
	{
		const std::string	prefix;
		const std::string	suffix;

		wrap(const std::string &prefix, const std::string &suffix);

		template <typename T>
		std::string	operator()(const T &data) const
		{
			return (this->prefix + ::toString(data) + this->suffix);
		}
	};
}

#endif