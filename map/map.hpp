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
			class value_compare : public binary_function<value_type, value_type, bool>
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
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				top = NULL;
				_size = 0;
			}

			// template <class InputIterator>
  			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			map (const map& x)
			{
				_comp = x._comp;
				_alloc = x._alloc;
				_size = x._size;
				// idk top
			}







			allocator_type get_allocator() const
			{
				return _alloc;
			}
	};
}

#endif
