#ifndef TRAITS_HPP
# define TRAITS_HPP

# include <cstddef>

namespace traits
{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag { };
	struct bidirectional_iterator_tag { };
	struct random_access_iterator_tag { };

	template <class Iterator> class iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::category iterator_category;
	};
	template <class T> class iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef traits::random_access_iterator_tag iterator_category;
	};
	template <class T> class iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef traits::random_access_iterator_tag iterator_category;
	};
}

#endif
