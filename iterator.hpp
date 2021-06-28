#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&>
	struct iterator {
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer  	pointer;
			typedef Reference	reference;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef size_t		size_type;
		private:
			pointer		_ptr;
		public:
			iterator() : _ptr(NULL) { }
			iterator(pointer ptr) : _ptr(ptr) { }
			iterator(const iterator &it) : _ptr(it._ptr) { }
			~iterator() { }

			bool		operator==(const iterator &it) { return _ptr == it._ptr; }
			bool		operator!=(const iterator &it) { return !(_ptr == it._ptr); }
			reference	operator*() { return *_ptr; }
			pointer		operator->() { return _ptr; }
			iterator	operator=(const iterator &it) { _ptr = it._ptr; return *this; }
			iterator	operator++() { ++_ptr; return (*this); }
			iterator	operator++(int f)
			{
				iterator f1(*this);

				(void)f;
				_ptr++;
				return (f1);
			}
			iterator	operator--() { --_ptr; return (*this); }
			iterator	operator--(int f)
			{
				iterator f1(*this);

				(void)f;
				_ptr--;
				return (f1);
			}
			iterator	operator+(difference_type n) const { return _ptr + n; }
			iterator	operator+(const iterator &n) const { return _ptr + n._ptr; }
			iterator	operator-(difference_type n) const { return _ptr - n; }
			iterator	operator-(const iterator &n) const { return _ptr - n._ptr; }
			bool		operator<(const iterator &n) const { return _ptr < n._ptr; }
			bool		operator>(const iterator &n) const { return _ptr > n._ptr; }
			bool		operator<=(const iterator &n) const { return _ptr <= n._ptr; }
			bool		operator>=(const iterator &n) const { return _ptr >= n._ptr; }
			iterator	operator+=(const size_type &n) { _ptr += n; return *this; }
			iterator	operator-=(const size_type &n) { _ptr -= n; return *this; }
			reference	operator[](const size_type &n) { return *(_ptr + n); }
	};

}

#endif
