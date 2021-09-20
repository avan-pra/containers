#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
		
		private:
			container_type c;

		public:
			explicit stack (const container_type& ctnr = container_type()) { }

			bool empty() const { return c.empty(); }

			size_type size() const { return c.size(); }

			value_type& top() { return c[c.end() - 1]; }
			
			const value_type& top() const { return c[c.end() - 1];}

			void push (const value_type& val) { c.push_back(val); }

			void pop() { c.pop_back(); }
	
			template <class T2, class Container2>
			friend bool operator== (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs) { return lhs.c == rhs.c; }
	
			template <class T, class Container>
			friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; }
	};

	template <class T2, class Container2>
	bool operator!= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs) { return !(lhs == rhs); }

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs == rhs ? true : (lhs < rhs)); }

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return !(lhs < rhs) }

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs == rhs ? true : !(lhs < rhs)); }
}

#endif
