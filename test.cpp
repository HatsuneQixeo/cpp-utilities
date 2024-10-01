#include "cpplibft.hpp"
#include <vector>

int	main(void)
{
	std::vector<int>	miku;

	miku.push_back(39);
	miku.push_back(831);
	std::cout << makeRangeLogger(miku) << '\n';
	const std::string	str = ::toString(makeRangeLogger(miku));

	std::pair<int, int>	pair(39, 831);

	std::cout << pair << '\n';
	std::vector<std::pair<int, int> >	vec_pair;

	vec_pair.push_back(std::make_pair(39, 831));
	vec_pair.push_back(std::make_pair(831, 39));

	std::cout << ::toString(pair) << '\n';
	std::cout << makeRangeLogger(vec_pair) << '\n';
	std::cout << str << '\n';
	std::cout << (std::string("Hatsune Miku") * 39) << '\n';
}
