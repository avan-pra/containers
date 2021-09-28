#ifndef NODE_HPP
# define NODE_HPP

template <class T>
struct node
{
	public:
		typedef T		value_type;
		typedef value_type		*pointer;
		pointer		data;
		struct node	*left;
		struct node	*right;
		struct node	*parent;

		node() : data(NULL), left(NULL), right(NULL), parent(NULL) { }
		node(const pointer val) : data(val), left(NULL), right(NULL), parent(NULL) { }
		node(const value_type &val) : data(val), left(NULL), right(NULL), parent(NULL) { }
		~node() { }
		node(const node *node) : data(node->data), left(node->left), right(node->right), parent(node->parent) { }
		node(const node &node) : data(node.data), left(node.left), right(node.right), parent(node.parent) { }
		node(const pointer val, node *depend) : data(val), left(NULL), right(NULL), parent(depend) { }
		node(const value_type &val, node *depend) : data(val), left(NULL), right(NULL), parent(depend) { }
		node &operator=(const node &node)
		{
			data = node.data;
			left = node.left;
			right = node.right;
			parent = node.parent;
			return *this;
		}
		bool	operator==(const node &node)
		{
			if (&node == this)
				return true;
			return false;
		}
		value_type operator->() { return data; }
};

#endif