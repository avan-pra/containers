#ifndef MAP_REVERSE_ITERATOR_HPP
# define MAP_REVERSE_ITERATOR_HPP

# include "../utils/traits.hpp"
# include "node.hpp"

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
			typedef		typename Iterator::container_type	Container;
			typedef		node<value_type> node;

		public:
			node	*_ptr;

		public:
			reverse_iterator() : _ptr(NULL) { }
			~reverse_iterator() { }
			reverse_iterator(node *elem): _ptr(elem) { }
			reverse_iterator(reverse_iterator *other): _ptr(other->_ptr) { }
			reverse_iterator(const typename Container::reverse_iterator &it) : _ptr(it._ptr) { }
			reverse_iterator(const typename Container::const_reverse_iterator &it) : _ptr(it._ptr) { }

			reverse_iterator	operator=(const reverse_iterator &it) { _ptr = it._ptr; return *this; }

			bool		operator==(const reverse_iterator &it) const
			{
				return (_ptr == it._ptr);
			}

			bool		operator!=(const reverse_iterator &it) const { return !(_ptr == it._ptr); }

			value_type operator*()
			{
				return *(_ptr->data);
			}

			pointer operator->()
			{
				return _ptr->data;
			}

			reverse_iterator	&operator++()
			{
				if (_ptr->left != NULL)
					_ptr = getRightMost(_ptr->left);
				else
				{
					while (_ptr->parent != NULL && _ptr->parent->left == _ptr)
						_ptr = _ptr->parent;
					_ptr =_ptr->parent;
				}
				return *this;
			}

			reverse_iterator	operator++(int f)
			{
				reverse_iterator f1(*this);

				(void)f;
				++(*this);
				return (f1);
			}

			reverse_iterator	&operator--()
			{
				if (_ptr->right != NULL)
					_ptr = getLeftMost(_ptr->right);
				else
				{
					while (_ptr->parent != NULL && _ptr->parent->right == _ptr)
						_ptr = _ptr->parent;
					_ptr =_ptr->parent;
				}
				return *this;
			}

			reverse_iterator	operator--(int f)
			{
				reverse_iterator f1(*this);

				(void)f;
				--(*this);
				return (f1);
			}

		private:
			node *getLeftMost(node *n)
			{
				node *tmp = n;

				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			}
			node *getRightMost(node *n)
			{
				node *tmp = n;

				while (tmp->right != NULL)
					tmp = tmp->right;
				return tmp;
			}
	};
}

#endif
