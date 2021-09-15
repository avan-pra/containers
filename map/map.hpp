#ifndef MAP_HPP
# define MAP_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <climits>
# include <sstream>
# include <iostream>
# include "../utils/utils.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "node.hpp"

# define LOWER 0
# define UPPER 1

class test1212
{
	public:
		test1212() { std::cout << "hola" << std::endl; }
		~test1212() { std::cout << "ciao" << std::endl; }
};

namespace ft
{
	template <
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type 
			>
	class map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef Compare								key_compare;
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type &a, const value_type &b) const { return comp(a.first, b.first); }
				
			};
			typedef Alloc								allocator_type;
			typedef value_type							&reference;
			typedef const value_type					&const_reference;
			typedef value_type							*pointer;
			typedef const value_type					*const_pointer;

			typedef ft::iterator<value_type, map<key_type, mapped_type> >						iterator;
			typedef ft::iterator<const value_type, const map<key_type, mapped_type> >			const_iterator;
			typedef ft::reverse_iterator<value_type, map<key_type, mapped_type> >				reverse_iterator;
			typedef ft::reverse_iterator<const value_type, const map<key_type, mapped_type> >	const_reverse_iterator;

			typedef ptrdiff_t							difference_type;
			typedef size_t								size_type;


		private:
			typedef	node<value_type> node;
			Alloc			_alloc;
			key_compare		_comp;
			node			*top;
			node			*lower;
			node			*upper;
			node			*dummy[2];
			size_type		_size;

		public:
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				top = NULL;
				lower = NULL;
				upper = NULL;
				dummy[LOWER] =	typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[LOWER]);
				dummy[UPPER] =	typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[UPPER]);
				_size = 0;
			}

			// template <class InputIterator>
  			// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			// map(const map& x)
			// {

			// }

			~map()
			{
				//clear();
			}

			map& operator=(const map& x)
			{
				//keep allocator
				//copy remote map
			}

			iterator begin()
			{
				return iterator(lower);
			}
			const_iterator begin() const
			{
				return const_iterator(lower);
			}
      		iterator end()
			{
				return iterator(upper->right);
			}
			const_iterator end() const
			{
				return const_iterator(upper->right);
			}
			
			/*
			** reverse iterator
			*/

			bool empty() const
			{
				return _size == 0;
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const //pas sur de celle la mdr
			{
				return (ULONG_MAX / (sizeof(node) + sizeof(value_type)));
			}

			mapped_type& operator[](const key_type& k)
			{

			}

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				if (_size == 0)
				{
					pointer tmp = _alloc.allocate(1);
					_alloc.construct(tmp, val);

					top = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
					typename allocator_type::template rebind<node>::other(_alloc).construct(top, tmp);
					++_size;
					set_lower_bound();
					set_upper_bound();
					return ft::pair<iterator, bool>(iterator(top), true);
				}
				else
				{
					node *traversal = top;
					while (1)
					{
						if (_comp(val.first, traversal->data->first))
						{//goto left
							if (traversal->left == NULL || traversal->left == dummy[LOWER] || traversal->left == dummy[UPPER])
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->left = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(traversal->left, tmp, traversal);
								++_size;
								set_lower_bound();
								set_upper_bound();
								return ft::pair<iterator, bool>(iterator(traversal->left), true);
							}
							else
								traversal = traversal->left;
						}
						else if (_comp(traversal->data->first, val.first))
						{//goto right
							if (traversal->right == NULL || traversal->right == dummy[LOWER] || traversal->right == dummy[UPPER])
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->right = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(traversal->right, tmp, traversal);
								++_size;
								set_lower_bound();
								set_upper_bound();
								return ft::pair<iterator, bool>(iterator(traversal->right), true);
							}
							else
								traversal = traversal->right;
						}
						else
							return ft::pair<iterator, bool>(iterator(traversal), false);
					}
				}
			}

			// iterator insert (iterator position, const value_type& val);

			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);

			void clear() //not done, need to do this for every node in the map
			{
				_alloc.destroy(top->data);
				_alloc.deallocate(top->data, 1);
				delete top;
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}

			private:
			void set_lower_bound()
			{
				// std::cout << "low" << std::endl;
				lower = getLeftMost(top);

				// // lower = (lower == dummy ? lower = lower->parent : lower);
				lower->left = dummy[LOWER];
				dummy[LOWER]->parent = lower;
			}

			void set_upper_bound()
			{
				upper = getRightMost(top);

				upper->right = dummy[UPPER];
				dummy[UPPER]->parent = upper;
				// dummy->left = upper;
				// dummy->left = upper;
			}

			private:
			node *getLeftMost(node *n)
			{
				node *tmp = n;

				while (tmp->left != NULL && tmp->left != dummy[LOWER] && tmp->left != dummy[UPPER])
					tmp = tmp->left;
				return tmp;
			}
			node *getRightMost(node *n)
			{
				node *tmp = n;

				while (tmp->right != NULL && tmp->right != dummy[LOWER] && tmp->right != dummy[UPPER])
					tmp = tmp->right;
				return tmp;
			}
	};
}

#undef LOWER
#undef UPPER

#endif
