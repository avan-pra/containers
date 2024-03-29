#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
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
