#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
# define VECTOR_CONST_REVERSE_ITERATOR_HPP

# include "traits.hpp"

template <class T>
struct iterator;

namespace ft
{
	template <class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&, class Category = traits::random_access_iterator_tag>
	struct const_reverse_iterator : public traits::random_access_iterator_tag
	{
		public:
			typedef iterator<T> iterator_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer  	pointer;
			typedef Reference	reference;
			typedef size_t		size_type;
		private:
			pointer		_ptr;
		public:
			const_reverse_iterator() : _ptr(NULL) { }
			explicit const_reverse_iterator(const iterator_type &it) : _ptr(it.operator->()) { }
			template <class Iter>
			const_reverse_iterator (const const_reverse_iterator<Iter>& rev_it) : _ptr(rev_it._ptr) { }
			template <class Iter>
			const_reverse_iterator (const reverse_iterator<Iter>& rev_it) : _ptr(rev_it.operator->()) { }
			~const_reverse_iterator() { }

			bool		operator==(const const_reverse_iterator &it) { return _ptr == it._ptr; }
			bool		operator!=(const const_reverse_iterator &it) { return !(_ptr == it._ptr); }
			reference	operator*() { return *_ptr; }
			pointer		operator->() { return _ptr; }
			const_reverse_iterator	operator=(const const_reverse_iterator &it) { _ptr = it._ptr; return *this; }
			const_reverse_iterator	operator++() { --_ptr; return (*this); }
			const_reverse_iterator	operator++(int f)
			{
				const_reverse_iterator f1(*this);

				(void)f;
				_ptr--;
				return (f1);
			}
			const_reverse_iterator	operator--() { ++_ptr; return (*this); }
			const_reverse_iterator	operator--(int f)
			{
				const_reverse_iterator f1(*this);

				(void)f;
				_ptr++;
				return (f1);
			}
			const_reverse_iterator	operator+(difference_type n) const { return _ptr + n; }
			const_reverse_iterator	operator+(const const_reverse_iterator &n) const { return _ptr + n._ptr; }
			const_reverse_iterator	operator-(difference_type n) const { return _ptr - n; }
			difference_type	operator-(const const_reverse_iterator &n) const { return _ptr - n._ptr; }
			bool		operator<(const const_reverse_iterator &n) const { return _ptr > n._ptr; }
			bool		operator>(const const_reverse_iterator &n) const { return _ptr < n._ptr; }
			bool		operator<=(const const_reverse_iterator &n) const { return _ptr >= n._ptr; }
			bool		operator>=(const const_reverse_iterator &n) const { return _ptr <= n._ptr; }
			const_reverse_iterator	operator+=(const size_type &n) { _ptr += n; return *this; }
			const_reverse_iterator	operator-=(const size_type &n) { _ptr -= n; return *this; }
			reference	operator[](const size_type &n) { return *(_ptr + n); }
	};

}

#endif
