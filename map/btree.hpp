#ifndef BTREE_HPP
# define BTREE_HPP

template <class T>
struct node
{
	T data;
	struct node* left;
	struct node* right;
};

template <class T>
class Tree
{
	private:
		node<T> *tree;

	public:
		Tree() { }
		~Tree() { }
		
};

#endif