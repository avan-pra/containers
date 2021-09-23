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
			class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type 
			>
	class map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
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

			typedef ft::iterator<value_type, map<key_type, mapped_type> >				iterator;
			typedef ft::iterator<const value_type, const map<key_type, mapped_type> >	const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

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
				dummy[UPPER] =	typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[UPPER]);
				dummy[LOWER] =	dummy[UPPER];
				lower = dummy[UPPER];
				upper = dummy[UPPER];
				_size = 0;
			}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				_comp = comp;
				_alloc = alloc;
				top = NULL;
				dummy[UPPER] =	typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[UPPER]);
				dummy[LOWER] =	dummy[UPPER];
				lower = dummy[UPPER];
				upper = dummy[UPPER];
				_size = 0;
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			map(const map& x)
			{
				_comp = x._comp;
				_alloc = x._alloc;
				top = NULL;
				dummy[UPPER] =	typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[UPPER]);
				dummy[LOWER] =	dummy[UPPER];
				lower = dummy[UPPER];
				upper = dummy[UPPER];
				_size = 0;

				iterator first = x.begin();
				iterator last = x.end();
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			~map()
			{
				clear();
				typename allocator_type::template rebind<node>::other(_alloc).destroy(dummy[UPPER]);
				typename allocator_type::template rebind<node>::other(_alloc).deallocate(dummy[UPPER], 1);
			}

			map& operator=(const map& x)
			{
				clear();

				iterator first = x.begin();
				iterator last = x.end();
				while (first != last)
				{
					insert(*first);
					++first;
				}
				return *this;
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
				return iterator(dummy[UPPER]);
			}
			const_iterator end() const
			{
				return const_iterator(dummy[UPPER]);
			}
			
			reverse_iterator rbegin()
			{
				return reverse_iterator(upper);
			}
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(upper);
			}
			reverse_iterator rend()
			{
				return reverse_iterator(dummy[LOWER]);
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(dummy[LOWER]);
			}

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
				return insert(ft::make_pair(k, mapped_type())).first->second;
			}

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				if (_size == 0)
				{
					pointer tmp = _alloc.allocate(1);
					_alloc.construct(tmp, val);

					top = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
					typename allocator_type::template rebind<node>::other(_alloc).construct(top, tmp);
					set_bound('i');
					++_size;
					return ft::pair<iterator, bool>(iterator(top), true);
				}
				else
				{
					node *traversal = top;
					while (1)
					{
						if (_comp(val.first, traversal->data->first))
						{//goto left
							if (is_null(traversal->left))
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->left = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(traversal->left, tmp, traversal);
								set_bound('i');
								++_size;
								return ft::pair<iterator, bool>(iterator(traversal->left), true);
							}
							else
								traversal = traversal->left;
						}
						else if (_comp(traversal->data->first, val.first))
						{//goto right
							if (is_null(traversal->right))
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->right = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
								typename allocator_type::template rebind<node>::other(_alloc).construct(traversal->right, tmp, traversal);
								set_bound('i');
								++_size;
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

			iterator insert(iterator position, const value_type& val) //mdr nn sah
			{
				return insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			void erase(iterator position)	
			{
				node *er = position._ptr;

				if (is_null(er->right) && is_null(er->left))
					erase_leaf(er);
				else if ((is_null(er->right) && !is_null(er->left)) || (!is_null(er->right) && is_null(er->left)))
					erase_single(er);
				else if (!is_null(er->right) && !is_null(er->left))
					erase_double(er);
				--_size;
				set_bound('e');
			}

			size_type erase(const key_type& k)
			{
				iterator it = find(k);

				if (it == end())
					return 0;
				else
					erase(it);
				return 1;
				// return (find(k) != end() && erase(find(k)) ? 1 : 0);
			}

			void erase(iterator first, iterator last)
			{
				iterator it;

				while (first != last)
				{
					it = first;
					++first;
					erase(it);
				}
			}

			void swap (map& x)
			{
				utils::swap(*this, x);
			}

			void clear() //not done, need to do this for every node in the map
			{
				erase(begin(), end());
			}

			key_compare key_comp() const
			{
				return _comp;
			}

			value_compare value_comp() const
			{
				return value_compare();
			}

			iterator find(const key_type& k)
			{
				node *traversal = top;

				while (1)
				{
					if (is_null(traversal))
						return iterator(dummy[UPPER]);
					if (_comp(k, traversal->data->first))
					{//goto left
						traversal = traversal->left;
					}
					else if (_comp(traversal->data->first, k))
					{//goto right
						traversal = traversal->right;
					}
					else //we found it
						return iterator(traversal);
				}
			}

			const_iterator find (const key_type& k) const
			{
				node *traversal = top;

				while (1)
				{
					if (is_null(traversal))
						return const_iterator(dummy[UPPER]);
					if (_comp(k, traversal->data->first))
					{//goto left
						traversal = traversal->left;
					}
					else if (_comp(traversal->data->first, k))
					{//goto right
						traversal = traversal->right;
					}
					else //we found it
						return const_iterator(traversal);
				}
			}

			size_type count (const key_type& k) const
			{
				return (find(k) != end() ? 1 : 0);
			}

			iterator lower_bound(const key_type& k)
			{
				node *traversal = top;
				node *result;

				while (!is_null(traversal))
				{
					if (!_comp(traversal->data->first, k))
					{
						result = traversal;
						traversal = traversal->left;
					}
					else
						traversal = traversal->right;
				}
				return iterator(result);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				node *traversal = top;
				node *result;

				while (!is_null(traversal))
				{
					if (!_comp(traversal->data->first, k))
					{
						result = traversal;
						traversal = traversal->left;
					}
					else
						traversal = traversal->right;
				}
				return const_iterator(result);
			}

			iterator upper_bound(const key_type& k)
			{
				node *traversal = top;
				node *result;

				while (!is_null(traversal))
				{
					if (_comp(k, traversal->data->first))
					{
						result = traversal;
						traversal = traversal->left;
					}
					else
						traversal = traversal->right;
				}
				return iterator(result);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				node *traversal = top;
				node *result;

				while (!is_null(traversal))
				{
					if (_comp(k, traversal->data->first))
					{
						result = traversal;
						traversal = traversal->left;
					}
					else
						traversal = traversal->right;
				}
				return const_iterator(result);
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}

			private:
			void erase_double(node *n)
			{
				node *traversal = n->left;

				traversal = getRightMost(traversal);
				utils::swap(traversal->data, n->data);
				if (is_null(traversal->right) && is_null(traversal->left))
					erase_leaf(traversal);
				else if ((is_null(traversal->right) && !is_null(traversal->left)) || (!is_null(traversal->right) && is_null(traversal->left)))
					erase_single(traversal);
			}

			void erase_single(node *n)
			{
				node *attach;

				if (is_null(n->left))
					attach = n->right;
				else if (is_null(n->right))
					attach = n->left;
				if (n == top)
					top = attach;
				else
				{
					n->parent->right = (n->parent->right == n) ? attach : n->parent->right;
					n->parent->left = (n->parent->left == n) ? attach : n->parent->left;
				}
				attach->parent = n->parent;
				_alloc.destroy(n->data);
				_alloc.deallocate(n->data, 1);
				typename allocator_type::template rebind<node>::other(_alloc).destroy(n);
				typename allocator_type::template rebind<node>::other(_alloc).deallocate(n, 1);
			}

			void erase_leaf(node *n)
			{
				bool is_last_node = (n->parent == NULL);

				if (!is_last_node)
				{
					n->parent->right = (n->parent->right == n) ? NULL : n->parent->right;
					n->parent->left = (n->parent->left == n) ? NULL : n->parent->left;
				}
				_alloc.destroy(n->data);
				_alloc.deallocate(n->data, 1);
				typename allocator_type::template rebind<node>::other(_alloc).destroy(n);
				typename allocator_type::template rebind<node>::other(_alloc).deallocate(n, 1);
				if (is_last_node)
					top = NULL;
			}

			bool is_null(node *n)
			{
				if (n == NULL || n == dummy[LOWER] || n == dummy[UPPER])
					return true;
				return false;
			}

			void set_bound(char c)
			{
				if (c == 'i' && _size == 0)
				{
					dummy[LOWER] = typename allocator_type::template rebind<node>::other(_alloc).allocate(1, (node *)0);
					typename allocator_type::template rebind<node>::other(_alloc).construct(dummy[LOWER]);
					set_lower_bound();
					set_upper_bound();
				}
				else if (c == 'e' && _size == 0)
				{
					set_upper_bound();
					typename allocator_type::template rebind<node>::other(_alloc).destroy(dummy[LOWER]);
					typename allocator_type::template rebind<node>::other(_alloc).deallocate(dummy[LOWER], 1);
					lower = dummy[UPPER];
					upper = dummy[UPPER];
					dummy[LOWER] = dummy[UPPER];
				}
				else
				{
					set_lower_bound();
					set_upper_bound();
				}
			}

			void set_lower_bound()
			{
				lower = getLeftMost(top);
				lower->left = dummy[LOWER];
				dummy[LOWER]->parent = lower;
			}

			void set_upper_bound()
			{
				if (top == NULL)
					return ;
				upper = getRightMost(top);
				upper->right = dummy[UPPER];
				dummy[UPPER]->parent = upper;
			}

			private:
			node *getLeftMost(node *n)
			{
				node *tmp = n;

				while (tmp && !is_null(tmp->left))
					tmp = tmp->left;
				return tmp;
			}
			node *getRightMost(node *n)
			{
				node *tmp = n;

				while (tmp && !is_null(tmp->right))
					tmp = tmp->right;
				return tmp;
			}
	};
}

#undef LOWER
#undef UPPER

#endif
