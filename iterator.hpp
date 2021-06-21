#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
		  class Pointer = T*, class Reference = T&>
	struct iterator {
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
		private:
			pointer		_ptr;
		public:

	};

}

#endif
