#ifndef STRING_HPP
# define STRING_HPP

# include <string>
# include <sstream>

std::string			toString(const char *str);
const std::string	&toString(const std::string &str);

template <typename T>
std::string	toString(const T &data)
{
	std::stringstream	ss;

	ss << data;
	return (ss.str());
}

std::string	operator*(const std::string &src, const unsigned int count);
std::string	patsubst(const std::string &src, const std::string &from, const std::string &to);
std::string	strPrintable(const std::string &input);

struct CaseInsensitiveCompare
{
	bool	operator()(const std::string &lhs, const std::string &rhs) const;
};

#endif