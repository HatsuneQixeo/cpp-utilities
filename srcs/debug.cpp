#include "debug.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <array>
#include <vector>

std::ostream	&showFDUsage(std::ostream &os)
{
	int							fd_expect = 3;
	std::array<int, 100>		arr_fd;
	std::vector<std::string>	msg_used;

	for (unsigned int i = 0; i < arr_fd.size(); i++)
		arr_fd[i] = -1;
	for (unsigned int i = 0; i < arr_fd.size(); i++)
	{
		const int	fd = ::open(".", O_RDONLY);

		arr_fd[i] = fd;
		if (fd == -1)
		{
			msg_used.push_back(std::to_string(fd_expect) + " - MAX_FILES(ulimit -n)");
			break ;
		}
		else if (0 <= fd && fd <= 2)
		{
			os << "fdUsage: " << fd << " is closed for some reason" << '\n';
			fd_expect = 3;
			continue ;
		}
		else if (fd - 1 == fd_expect)
			msg_used.push_back(std::to_string(fd_expect));
		else if (fd != fd_expect)
			msg_used.push_back(std::to_string(fd_expect) + " - " + std::to_string(fd - 1));
		fd_expect = fd + 1;
	}
	std::for_each(arr_fd.begin(), arr_fd.end(), ::close);
	os << "fdUsage: ";
	if (msg_used.empty())
		return (os << "none");
	os << makeRangeLogger(msg_used);
	return (os);
}
