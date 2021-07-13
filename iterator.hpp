#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>
# include "traits.hpp"

namespace ft
{
	template <class T, class Container, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&, class Category = traits::random_access_iterator_tag>
	struct iterator : public traits::random_access_iterator_tag
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer  	pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
			typedef size_t		size_type;
		private:
			pointer		_ptr;
		public:
			iterator() : _ptr(NULL) { }
			iterator(pointer ptr) : _ptr(ptr) { }
			iterator(const typename Container::iterator &it) : _ptr(it.operator->()) { }
			iterator(const typename Container::const_iterator &it) : _ptr(it.operator->()) { }
			~iterator() { }

			bool		operator==(const iterator &it) const { return _ptr == it._ptr; }
			bool		operator!=(const iterator &it) const { return !(_ptr == it._ptr); }
			reference	operator*() { return *_ptr; }
			pointer		operator->() const { return _ptr; }
			iterator	operator=(const iterator &it) { _ptr = it._ptr; return *this; }
			iterator	&operator++() { ++_ptr; return (*this); }
			iterator	operator++(int f)
			{
				iterator f1(*this);

				(void)f;
				_ptr++;
				return (f1);
			}
			iterator	&operator--() { --_ptr; return (*this); }
			iterator	operator--(int f)
			{
				iterator f1(*this);

				(void)f;
				_ptr--;
				return (f1);
			}
			iterator	operator+(const difference_type &n) const { return iterator(_ptr + n); }
			iterator	operator-(const difference_type &n) const { return iterator(_ptr - n); }
			difference_type	operator+(const iterator &n) const { return _ptr + n._ptr; }
			difference_type	operator-(const iterator &n) const { return _ptr - n._ptr; }
			bool		operator<(const iterator &n) const { return _ptr < n._ptr; }
			bool		operator>(const iterator &n) const { return _ptr > n._ptr; }
			bool		operator<=(const iterator &n) const { return _ptr <= n._ptr; }
			bool		operator>=(const iterator &n) const { return _ptr >= n._ptr; }
			iterator	operator+=(const size_type &n) { _ptr += n; return *this; }
			iterator	operator-=(const size_type &n) { _ptr -= n; return *this; }
			reference	operator[](const size_type &n) { return *(_ptr + n); }
	};
	template <class T, class V, class I>
	iterator<V, T>	operator+(const I &n, const iterator<V, T> &it) { return iterator<V, T>(it.operator->() + n); }
	// template <class T, class V, class I>
	// iterator<V, T>	operator-(const I &n, const iterator<V, T> &it) { return iterator<V, T>(it.operator->() - n); }
}

#endif
