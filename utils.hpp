#ifndef TO_STRING_HPP
# define TO_STRING_HPP

# include <iostream>

namespace utils
{
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

	//is_integral implementation
	template <bool is_integral, typename T>
	struct __is_integral_res
	{
		static const bool value = is_integral;
		typedef T type;
	};

	template <typename T>
	struct __is_integral_helper : public __is_integral_res<false, T> { };
	template <>
	struct __is_integral_helper<bool> : public __is_integral_res<true, bool> { };
	template <>
	struct __is_integral_helper<char> : public __is_integral_res<true, char> { };
	template <>
	struct __is_integral_helper<char16_t> : public __is_integral_res<true, char16_t> { };
	template <>
	struct __is_integral_helper<char32_t> : public __is_integral_res<true, char32_t> { };
	template <>
	struct __is_integral_helper<wchar_t> : public __is_integral_res<true, wchar_t> { };
	template <>
	struct __is_integral_helper<short> : public __is_integral_res<true, short> { };
	template <>
	struct __is_integral_helper<int> : public __is_integral_res<true, int> { };
	template <>
	struct __is_integral_helper<long> : public __is_integral_res<true, long> { };
	template <>
	struct __is_integral_helper<long long> : public __is_integral_res<true, long long> { };

	template <typename T>
	struct is_integral : public __is_integral_helper<T> { };

	//enable_if implementation
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
}

#endif
