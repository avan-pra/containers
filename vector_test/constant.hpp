#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <iostream>
#include <vector>
#include <string>

#define COLOR_RESET		"\033[0m"
#define COLOR_RED		"\033[1;31m"
#define COLOR_BLUE		"\033[1;34m"
#define COLOR_GREEN		"\033[1;32m"
#define COLOR_WHITE		"\033[1;37m"
#define COLOR_YELLOW	"\033[33m"
#define COLOR_CYAN		"\033[1;36m"
#define	clear_terminal "\x1B[2J\x1B[H"
#define ft_vector		COLOR_BLUE << "----- ft::vector -----" << COLOR_RESET << std::endl

void	next_test();

#endif
