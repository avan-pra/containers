#ifndef BTREE_HPP
# define BTREE_HPP

#include <cstddef>

template <class T>
struct node
{
	public:
		typedef T		value_type;
		value_type	data;
		struct node	*left;
		struct node	*right;
		struct node	*parent;

		node();
		node(const value_type &val = value_type()) : data(val), left(NULL), right(NULL), parent(NULL) { }
		~node() { }
		node(const node &node) : data(node.data), left(node.left), right(node.right), parent(node.parent) { }
		node(const value_type &val, node *depend) : data(val), left(NULL), right(NULL), parent(depend) { }
		node &operator=(const node &node)
		{
			data = node.data;
			left = node.left;
			right = node.right;
			parent = node.parent;
			return *this;
		}
		value_type operator->() { return data; }
};

#endif