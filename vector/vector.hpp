#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <climits>
# include <sstream>
# include <iostream>
# include "../utils/utils.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef T										&reference;
			typedef const T									&const_reference;
			typedef T										*pointer;
			typedef const T									*const_pointer;
			typedef pointer									iterator;
			typedef const_pointer							const_iterator;
			typedef typename ft::reverse_iterator<iterator>	reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef size_t									size_type;
			typedef std::ptrdiff_t							difference_type;

		private:
			Alloc			_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_size_alloc;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _size_alloc(0) { }
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _size(0), _size_alloc(0)
			{
				_ptr = _alloc.allocate(n);
				_size_alloc = n;
				for (size_type i = 0; i < n; ++i)
					push_back(val);
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename utils::enable_if<!utils::is_integral<InputIterator>::value >::type* = 0) : _alloc(alloc), _ptr(NULL), _size(0), _size_alloc(0)
			{
				_ptr = _alloc.allocate(std::abs(last - first));
				_size_alloc = std::abs(last - first);
				for (; first != last; ++first)
					push_back(*first);
			}
			vector (const vector& x) : _alloc(x._alloc), _ptr(NULL), _size(0), _size_alloc(0) { *this = x; }

			~vector()
			{
				clear();
				_alloc.deallocate(_ptr, _size_alloc);
			}

			vector& operator= (const vector& x)
			{
				clear();
				if (_size_alloc < x.size())
				{
					_alloc.deallocate(_ptr, _size_alloc);
					_ptr = _alloc.allocate(x.size());
					_size_alloc = x.size();
				}
				for (size_type i = 0; i < x._size; ++i)
					push_back(x[i]);
				return *this;
			}

			iterator begin() { return iterator(_ptr); }
			const_iterator begin() const { return const_iterator(_ptr); }
			iterator end() { return iterator(_ptr + _size); }
			const_iterator end() const { return const_iterator(_ptr + _size); }
			reverse_iterator rbegin() { return reverse_iterator(_ptr + _size - 1); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(_ptr + _size - 1); }
			reverse_iterator rend() { return reverse_iterator(_ptr - 1); }
			const_reverse_iterator rend() const { return const_reverse_iterator(_ptr - 1); }

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
				while (_size < n)
					push_back(val);
				while (_size > n)
					pop_back();
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
					return ;//prblm
				new_hold = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
				{
					_alloc.construct(&new_hold[i], _ptr[i]);
					_alloc.destroy(&_ptr[i]);
				}
				_alloc.deallocate(_ptr, _size_alloc);
				_size_alloc = n;
				_ptr = new_hold;
			}

			reference operator[] (size_type n)
			{
				return _ptr[n];
			}
			
			const_reference operator[] (size_type n) const
			{
				return _ptr[n];
			}
			
			reference at(size_type n)
			{
				if (n < 0 || n >= _size_alloc)
					throw std::out_of_range(utils::ft_to_string(n));
				return _ptr[n];
			}
			
			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size_alloc)
					throw std::out_of_range(utils::ft_to_string(n));
				return _ptr[n];
			}

			reference front()
			{
				return _ptr[0];
			}
			
			const_reference front() const
			{
				return _ptr[0];
			}

			reference back()
			{
				return _ptr[_size - 1];
			}

			const_reference back() const
			{
				return _ptr[_size - 1];
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename utils::enable_if<!utils::is_integral<InputIterator>::value >::type* = 0)
			{
				clear();
				if (static_cast<size_type> (std::abs(last - first)) > _size_alloc)
				{
					_alloc.deallocate(_ptr, _size_alloc);
					_ptr = _alloc.allocate(std::abs(last - first));
					_size_alloc = std::abs(last - first);
				}
				for (; first != last; ++first)
					push_back(*first);
			}

			void assign (size_type n, const value_type& val)
			{
				value_type L = val;

				clear();
				if (n > _size_alloc)
				{
					_alloc.deallocate(_ptr, _size_alloc);
					_ptr = _alloc.allocate(n);
					_size_alloc = n;
				}
				for (size_type i = 0; i < n; ++i)
					push_back(L);
			}

			void push_back (const value_type& val)
			{
				value_type L = val;

				if (_size == _size_alloc)
					reserve((_size_alloc == 0 ? 1 : _size_alloc * 2));
				_alloc.construct(&_ptr[_size], L);
				++_size;
			}

			void pop_back()
			{
				_alloc.destroy(&(_ptr[_size - 1]));
				--_size;
			}

			iterator insert(iterator position, const value_type& val)
			{
				difference_type offset = position - begin();

				insert(position, 1, val);

				return (iterator(begin() + offset));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n > 0)
				{
					value_type L = val;
					difference_type offset = position - begin();

					_size + n > _size_alloc ? reserve((_size_alloc * 2 < _size + n ? _size + n : _size_alloc * 2)) : (void)0 ;

					position = begin() + offset;
					for (iterator it = end() + n; it != position + n - 1; --it)
						utils::swap(*it, *(it - n));
					while (n-- != 0)
					{
						_alloc.construct(position, L);
						++_size;
						++position;
					}
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename utils::enable_if<!utils::is_integral<InputIterator>::value >::type* = 0)
			{
				if (std::abs(last - first) > 0)
				{
					size_type n = std::abs(last - first);
					difference_type offset = position - begin();

					_size + n > _size_alloc ? reserve((_size_alloc * 2 < _size + n ? _size + n : _size_alloc * 2)) : (void)0 ;

					position = begin() + offset;
					for (iterator it = end() + n; it != position + n - 1; --it)
						utils::swap(*it, *(it - n));
					while (n-- != 0)
					{
						_alloc.construct(position, *first);
						++_size;
						++position;
						++first;
					}
				}
			}

			iterator erase(iterator position)
			{
				iterator it = position;				

				_alloc.destroy(position);
				for (; position != end() - 1; ++position)
					utils::swap(*position, *(position + 1));
				--_size;
				return it;
			}

			iterator erase (iterator first, iterator last)
			{
				for (; first != last; --last)
					first = erase(first);
				return last;
			}

			void swap(vector& x)
			{
				utils::swap(_ptr, x._ptr);
				utils::swap(_size, x._size);
				utils::swap(_size_alloc, x._size_alloc);
			}

			void clear()
			{
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_ptr[i]);
				_size = 0;
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		if (lhs.size() > rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] > rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		if (lhs.size() > rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] >= rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs < rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs <= rhs)
			return false;
		return true;
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		utils::swap(x, y);
	}
}

#endif
