#include "string.hpp"
#include <iomanip>

const std::string	&toString(const std::string &str)
{
	return (str);
}

std::string	toString(const char *str)
{
	if (str == nullptr)
		return ("(null)");
	else
		return (str);
}

std::string	patsubst(const std::string &src, const std::string &from, const std::string &to)
{
	std::string	dst;
	size_t		start = 0;
	size_t		end = src.find(from);

	while (end != std::string::npos)
	{
		dst.append(src, start, end - start);
		dst.append(to);
		start = end + from.size();
		end = src.find(from, start);
	}
	dst.append(src, start, src.size() - start);
	return (dst);
}

std::string	operator*(const std::string &src, const unsigned int count)
{
	std::string	str;

	str.reserve(src.size() * count);
	for (unsigned int i = 0; i < count; ++i)
		str += src;
	return (str);
}

std::string strPrintable(const std::string &input)
{
	std::stringstream	output;

	output << std::hex << std::setfill('0');
	for (std::string::const_iterator it = input.begin(), end = input.end();
		it != end;
		++it)
	{
		const unsigned char	c = *it;

		if (c == '\r')
			output << "\\r";
		else if (c == '\n')
			output << "\\n";
		else if (!std::isprint(c))
			output << '\\' << std::setw(2) << static_cast<int>(c);
		else
			output << c;
	}
	return (output.str());
}

bool	CaseInsensitiveCompare::operator()(const std::string &lhs, const std::string &rhs) const
{
	for (size_t i = 0; i < lhs.size() + 1; ++i)
	{
		const unsigned char	l = std::tolower(lhs[i]);
		const unsigned char	r = std::tolower(rhs[i]);

		if (l != r)
			return (l < r);
	}
	return (false);
}
