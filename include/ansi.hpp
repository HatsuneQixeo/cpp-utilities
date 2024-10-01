#ifndef ANSI_HPP
# define ANSI_HPP

namespace ansi
{
	typedef const char	*color_t;

	namespace dark
	{
		const color_t	grey = "\e[30m";
		const color_t	red = "\e[31m";
		const color_t	green = "\e[32m";
		const color_t	yellow = "\e[33m";
		const color_t	blue = "\e[34m";
		const color_t	magenta = "\e[35m";
		const color_t	cyan = "\e[36m";
		const color_t	white = "\e[37m";
	}

	namespace bright
	{
		const color_t	grey = "\e[90m";
		const color_t	red = "\e[91m";
		const color_t	green = "\e[92m";
		const color_t	yellow = "\e[93m";
		const color_t	blue = "\e[94m";
		const color_t	magenta = "\e[95m";
		const color_t	cyan = "\e[96m";
		const color_t	white = "\e[97m";
	}

	const color_t	reset = "\e[0m";
	const color_t	grey = dark::grey;
	const color_t	red = dark::red;
	const color_t	green = dark::green;
	const color_t	yellow = dark::yellow;
	const color_t	blue = dark::blue;
	const color_t	magenta = dark::magenta;
	const color_t	cyan = dark::cyan;
	const color_t	white = dark::white;

	const color_t	bold = "\e[1m";
	const color_t	italic = "\e[3m";
	const color_t	underline = "\e[4m";
	const color_t	blink = "\e[5m";
	const color_t	invert = "\e[7m";
	const color_t	hidden = "\e[8m";

	const color_t	no_bold = "\e[21m";
	const color_t	no_italic = "\e[23m";
	const color_t	no_underline = "\e[24m";
	const color_t	no_blink = "\e[25m";
	const color_t	no_invert = "\e[27m";
	const color_t	no_hidden = "\e[28m";

	const color_t	clear_line = "\e[K";
	const color_t	clear_screen = "\e[2J";

	const color_t	cursor_up = "\e[A";
	const color_t	cursor_down = "\e[B";
	const color_t	cursor_forward = "\e[C";
	const color_t	cursor_back = "\e[D";
	const color_t	cursor_next_line = "\e[E";
	const color_t	cursor_prev_line = "\e[F";
	const color_t	cursor_position = "\e[H";
	const color_t	cursor_save = "\e[s";
	const color_t	cursor_restore = "\e[u";
	const color_t	cursor_hide = "\e[?25l";
	const color_t	cursor_show = "\e[?25h";

	const color_t	scroll_up = "\e[S";
	const color_t	scroll_down = "\e[T";
	const color_t	scroll_left = "\e[@";
	const color_t	scroll_right = "\e[P";
	const color_t	scroll_next_line = "\e[E";
	const color_t	scroll_prev_line = "\e[F";
	const color_t	scroll_position = "\e[H";
	const color_t	scroll_save = "\e[s";
	const color_t	scroll_restore = "\e[u";
	const color_t	scroll_hide = "\e[?25l";
	const color_t	scroll_show = "\e[?25h";

	const color_t	erase_line = "\e[K";
	const color_t	erase_screen = "\e[2J";
	const color_t	erase_up = "\e[1J";
	const color_t	erase_down = "\e[J";
	const color_t	erase_start = "\e[1K";
	const color_t	erase_end = "\e[K";

	const color_t	none = "";
};

#endif
