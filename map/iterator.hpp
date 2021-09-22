#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/traits.hpp"
# include "node.hpp"

namespace ft
{
	template <class T, class Container, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&, class Category = traits::bidirectional_iterator_tag>
	struct iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer  	pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
			typedef size_t		size_type;
			typedef	Container	container_type;		//new shit

		private:
			typedef		node<typename Container::value_type> node;

		public:
			node	*_ptr;
 
		public:
			iterator() : _ptr(NULL) { }
			~iterator() { }
			iterator(node *elem): _ptr(elem) { }
			// iterator(iterator *other): _ptr(other->_ptr) { }

			iterator(const typename Container::iterator &it) : _ptr(it._ptr) { }
			iterator(const typename Container::const_iterator &it) : _ptr(it._ptr) { }

			iterator	operator=(const iterator &it) { _ptr = it._ptr; return *this; }
			
			bool		operator==(const iterator &it) const
			{
				return (_ptr == it._ptr);
			}

			bool		operator!=(const iterator &it) const { return !(_ptr == it._ptr); }

			value_type operator*()
			{
				return *(_ptr->data);
			}

			pointer operator->()
			{
				return _ptr->data;
			}

			iterator	&operator++()
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

			iterator	operator++(int f)
			{
				iterator f1(*this);

				(void)f;
				++(*this);
				return (f1);
			}

			iterator	&operator--()
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

			iterator	operator--(int f)
			{
				iterator f1(*this);

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
