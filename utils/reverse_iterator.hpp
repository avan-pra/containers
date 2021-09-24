#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "../utils/traits.hpp"

template <class T>
struct iterator;

namespace ft
{
	template <class Iterator>
	struct reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename traits::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename traits::iterator_traits<Iterator>::value_type			value_type;
			typedef typename traits::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename traits::iterator_traits<Iterator>::pointer  	pointer;
			typedef typename traits::iterator_traits<Iterator>::reference	reference;
			typedef size_t		size_type;

		private:
			Iterator	_ptr;

		public:
			reverse_iterator() : _ptr(NULL) { }
			explicit reverse_iterator (iterator_type it) : _ptr(it) { }	
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _ptr(rev_it.base()) { }
			~reverse_iterator() { }

			iterator_type base() const{ return _ptr; }

			reference	operator*() { return *_ptr; }

			reverse_iterator	operator=(const reverse_iterator &it) { _ptr = it._ptr; return *this; }

			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_ptr - n); }
			reverse_iterator	operator++() { --_ptr; return (*this); }
			reverse_iterator	operator++(int f)
			{
				reverse_iterator f1(*this);

				(void)f;
				_ptr--;
				return (f1);
			}
			reverse_iterator	operator+=(const size_type &n) { _ptr -= n; return *this; }

			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_ptr + n); }
			reverse_iterator	operator--() { ++_ptr; return (*this); }
			reverse_iterator	operator--(int f)
			{
				reverse_iterator f1(*this);

				(void)f;
				_ptr++;
				return (f1);
			}
			reverse_iterator	operator-=(const size_type &n) { _ptr += n; return *this; }

			pointer		operator->() const { return _ptr.operator->(); }

			reference	operator[](const size_type &n) { return *(_ptr - n); }

			bool		operator==(const reverse_iterator &it) { return _ptr == it._ptr; }
			bool		operator!=(const reverse_iterator &it) { return !(_ptr == it._ptr); }
			bool		operator<(const reverse_iterator &n) const { return _ptr > n._ptr; }
			bool		operator<=(const reverse_iterator &n) const { return _ptr >= n._ptr; }
			bool		operator>(const reverse_iterator &n) const { return _ptr < n._ptr; }
			bool		operator>=(const reverse_iterator &n) const { return _ptr <= n._ptr; }
	};
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return reverse_iterator<Iterator>(rev_it.base() - n); } 
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return rhs.base() - lhs.base(); }
}

#endif
