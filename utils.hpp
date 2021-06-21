#ifndef TO_STRING_HPP
# define TO_STRING_HPP

# include <iostream>

template <typename T>
std::string		ft_to_string(T value)
{
	std::string output;
	std::string sign;
	char		nb[2];

	if (value < 0)
	{
		sign + "-";
		value = -value;
	}
	nb[1] = '\0';
	while (output.empty() || (value > 0))
	{
		nb[0] = value % 10 + '0';
		output.insert(0, std::string(nb));
		value /= 10;
	}

	return (sign + output);
}

template <class T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

#endif
