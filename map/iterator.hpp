#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/traits.hpp"
# include "node.hpp"

namespace ft
{
	template <class T, class Container, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&, class Category = traits::bidirectional_iterator_tag>
	struct iterator : public traits::bidirectional_iterator_tag
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer  	pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
			typedef size_t		size_type;

		private:
			typedef		node<value_type> node;
			node		*_ptr;

		public:
			iterator() : _ptr(NULL) { }
			iterator(node *elem): _ptr(elem) { }
			iterator(iterator *other): _ptr(other->_ptr) { }
			// iterator(const typename Container::iterator &it) : _ptr(it.operator->()) { }
			// iterator(const typename Container::const_iterator &it) : _ptr(it.operator->()) { }
			~iterator() { }

			pointer operator->()
			{
				return _ptr->data;
			}

			value_type operator*()
			{
				return *(_ptr->data);
			}
			// bool		operator==(const iterator &it) const { return _ptr == it._ptr; }
			// bool		operator!=(const iterator &it) const { return !(_ptr == it._ptr); }
			// iterator	operator=(const iterator &it) { _ptr = it._ptr; return *this; }
			
			iterator	&operator++()
			{
				if (_ptr->right != NULL)
					_ptr = getLeftMost(_ptr->right);
				else
				{
					while (_ptr->parent != NULL && _ptr->parent->right == _ptr)
					{
						_ptr = _ptr->parent;
					}
					// std::cout << &_ptr << ":" << _ptr->parent->right << std::endl;
					_ptr =_ptr->parent;
					// if (_ptr == _ptr.parent->left)
					// 	_ptr = _ptr.parent;
					// else if (true)
					// 	;
				}
				return *this;
			}

			private:
			node *getLeftMost(node *n)
			{
				node *tmp = n;

				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			}

			// iterator	operator++(int f)
			// {
			// 	iterator f1(*this);

			// 	(void)f;
			// 	_ptr++;
			// 	return (f1);
			// }
			// iterator	&operator--() { --_ptr; return (*this); }
			// iterator	operator--(int f)
			// {
			// 	iterator f1(*this);

			// 	(void)f;
			// 	_ptr--;
			// 	return (f1);
			// }
			// iterator	operator+(const difference_type &n) const { return iterator(_ptr + n); }
			// iterator	operator-(const difference_type &n) const { return iterator(_ptr - n); }
			// difference_type	operator+(const iterator &n) const { return _ptr + n._ptr; }
			// difference_type	operator-(const iterator &n) const { return _ptr - n._ptr; }
			// bool		operator<(const iterator &n) const { return _ptr < n._ptr; }
			// bool		operator>(const iterator &n) const { return _ptr > n._ptr; }
			// bool		operator<=(const iterator &n) const { return _ptr <= n._ptr; }
			// bool		operator>=(const iterator &n) const { return _ptr >= n._ptr; }
			// iterator	operator+=(const size_type &n) { _ptr += n; return *this; }
			// iterator	operator-=(const size_type &n) { _ptr -= n; return *this; }
			// reference	operator[](const size_type &n) { return *(_ptr + n); }
	};
	// template <class T, class V, class I>
	// iterator<V, T>	operator+(const I &n, const iterator<V, T> &it) { return iterator<V, T>(it.operator->() + n); }
	// template <class T, class V, class I>
	// iterator<V, T>	operator-(const I &n, const iterator<V, T> &it) { return iterator<V, T>(it.operator->() - n); }
}

#endif
