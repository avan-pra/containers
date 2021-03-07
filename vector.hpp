#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef const T								*const_pointer;
			typedef Iterator<value_type>				iterator;
			typedef const Iterator<value_type>			const_iterator;
			typedef ReverseIterator<value_type>			reverse_iterator;
			typedef const ReverseIterator<value_type>	const_reverse_iterator;
			typedef size_t								size_type;
			typedef std::ptrdiff_t						difference_type;

		private:
			allocator_type	_alloc;
			size_type		_size;


		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc);
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

	};
}

#endif