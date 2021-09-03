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

			// iterators

			typedef ptrdiff_t							difference_type;
			typedef size_t								size_type;


		private:
			typedef	node<value_type> node;
			Alloc			_alloc;
			key_compare		_comp;
			node			*top;
			size_type		_size;

		public:
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				top = NULL;
				_size = 0;
			}

			// template <class InputIterator>
  			// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			map(const map& x)
			{
				_comp = x._comp;
				_alloc = x._alloc;
				_size = x._size;
				// parse tt la map et dupliquer ?
			}

			~map()
			{
				//clear();
			}

			map& operator=(const map& x)
			{
				//keep allocator
				//copy remote map
			}

			mapped_type& operator[](const key_type& k)
			{

			}

			void test()
			{
				std::cout << top->data->first << std::endl;
				std::cout << top->left << std::endl;
				std::cout << top->right << std::endl;
				std::cout << top->right->right->data->first << std::endl;
				std::cout << top->left->data->second << std::endl;
			}

			void insert(const value_type& val) //mauvais return type
			{//verify that an already existing key doesnt exist ou pas
				if (_size == 0)
				{
					pointer tmp = _alloc.allocate(1);
					_alloc.construct(tmp, val);

					top = new node(tmp);
					++_size;
				}
				else
				{
					node *traversal = top;
					while (1)
					{
						if (_comp(val.first, traversal->data->first))
						{//goto left
							if (traversal->left == NULL)
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->left = new node(tmp, traversal);
								++_size;
								return ;
							}
							else
								traversal = traversal->left;
						}
						else
						{//goto right
							if (traversal->right == NULL)
							{
								pointer tmp = _alloc.allocate(1);
								_alloc.construct(tmp, val);

								traversal->right = new node(tmp, traversal);
								++_size;
								return ;
							}
							else
								traversal = traversal->right;
						}
					}
				}
			}

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
	};
}

#endif
