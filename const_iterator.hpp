#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

# include "traits.hpp"

namespace ft
{
	template <class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&, class Category = traits::random_access_iterator_tag>
	struct const_iterator : public traits::random_access_iterator_tag
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
			const_iterator() : _ptr(NULL) { }
			const_iterator(pointer ptr) : _ptr(ptr) { }
			const_iterator(const iterator<T> &it) : _ptr(it.operator->()) { }
			const_iterator(const const_iterator &it) : _ptr(it._ptr) { }
			~const_iterator() { }

			bool		operator==(const const_iterator &it) const { return _ptr == it._ptr; }
			// bool		operator==(const iterator &it) const { return _ptr == it.operator->(); }
			bool		operator!=(const const_iterator &it) const { return !(_ptr == it._ptr); }
			// bool		operator!=(const iterator &it) const { return !(_ptr == it.operator->()); }
			reference	operator*() { return *_ptr; }
			pointer		operator->() const { return _ptr; }
			const_iterator	operator=(const const_iterator &it) { _ptr = it._ptr; return *this; }
			const_iterator	operator++() { ++_ptr; return (*this); }
			const_iterator	operator++(int f)
			{
				const_iterator f1(*this);

				(void)f;
				_ptr++;
				return (f1);
			}
			const_iterator	operator--() { --_ptr; return (*this); }
			const_iterator	operator--(int f)
			{
				const_iterator f1(*this);

				(void)f;
				_ptr--;
				return (f1);
			}
			const_iterator	operator+(difference_type n) const { return _ptr + n; }
			const_iterator	operator+(const const_iterator &n) const { return _ptr + n._ptr; }
			const_iterator	operator-(difference_type n) const { return _ptr - n; }
			difference_type	operator-(const const_iterator &n) const { return _ptr - n._ptr; }
			bool		operator<(const const_iterator &n) const { return _ptr < n._ptr; }
			bool		operator>(const const_iterator &n) const { return _ptr > n._ptr; }
			bool		operator<=(const const_iterator &n) const { return _ptr <= n._ptr; }
			bool		operator>=(const const_iterator &n) const { return _ptr >= n._ptr; }
			const_iterator	operator+=(const size_type &n) { _ptr += n; return *this; }
			const_iterator	operator-=(const size_type &n) { _ptr -= n; return *this; }
			reference	operator[](const size_type &n) { return *(_ptr + n); }
	};

}

#endif
