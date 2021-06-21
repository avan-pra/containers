#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <climits>
# include <sstream>
# include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef T									&reference;
			typedef const T								&const_reference;
			typedef T									*pointer;
			typedef const T								*const_pointer;
			//typedef Iterator<value_type>				iterator;
			//typedef const Iterator<value_type>			const_iterator;
			//typedef ReverseIterator<value_type>			reverse_iterator;
			//typedef const ReverseIterator<value_type>	const_reverse_iterator;
			typedef size_t								size_type;
			typedef std::ptrdiff_t						difference_type;

		private:
			Alloc			_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_size_alloc;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _size_alloc(0) { }
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _size_alloc(0)
			{
				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}
			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x) : _alloc(x._alloc), _ptr(NULL), _size(0), _size_alloc(0)
			{

			}

			~vector()
			{
				
			}

			//vector& operator= (const vector& x);

//   iterator begin();
// const_iterator begin() const;
//   iterator end();
// const_iterator end() const;
//   reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;
//   reverse_iterator rend();
// const_reverse_iterator rend() const;

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return ULONG_MAX / sizeof(value_type);
			}

			void resize (size_type n, value_type val = value_type())
			{

			}

			size_type capacity() const
			{
				return _size_alloc;
			}

			bool empty() const
			{
				return _size == 0;
			}

			void reserve (size_type n)
			{
				pointer new_hold;

				if (n <= _size_alloc)
					;//prblm
				new_hold = _alloc.allocate(n);
				for (size_t i = 0; i < _size; ++i)
					_alloc.construct(&new_hold[i], _ptr[i]);
				_alloc.deallocate(_ptr, _size);
				_alloc.destroy(_ptr);
				_size_alloc = n;
				_ptr = new_hold;
			}

    		reference operator[] (size_type n)
			{
				return _ptr[n];
			}
			
			const_reference operator[] (size_type n) const
			{

			}
			
			reference at (size_type n)
			{

			}
			
			const_reference at (size_type n) const
			{

			}

			reference front()
			{

			}
			
			const_reference front() const
			{

			}

			reference back()
			{

			}

			const_reference back() const
			{

			}

// template <class InputIterator>
// void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val)
			{

			}

			void push_back (const value_type& val)
			{
				if (_size == _size_alloc)
					reserve((_size_alloc == 0 ? 1 : _size_alloc) * 2);
				_alloc.construct(&_ptr[_size], val);
				++_size;
			}

			void pop_back()
			{

			}

			// iterator insert (iterator position, const value_type& val);
    		// void insert (iterator position, size_type n, const value_type& val);

			// template <class InputIterator>
    		// void insert (iterator position, InputIterator first, InputIterator last);
	
			// iterator erase (iterator position)
			// {

			// }

			// iterator erase (iterator first, iterator last)
			// {

			// }

			void swap (vector& x)
			{

			}

			void clear()
			{

			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}



	};
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}
	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{

	}
}

#endif
