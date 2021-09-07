#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class _T1, class _T2>
	struct pair
	{
		public:
			typedef _T1 first_type;
			typedef _T2 second_type;

			_T1 first;
			_T2 second;

			pair() : first(), second() { }
			template<class U, class V>
			pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { }
			pair(const first_type& a, const second_type& b) : first(a), second(b) { }
			pair& operator= (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return *this;
			}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) { return ft::pair<T1, T2> (x, y); }
}

#endif
