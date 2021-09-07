#include "map.hpp"
#include <map>
#include <iostream>

int             main(void)
{
	// test1212 bjr;

	ft::map<int, int> m;			//tree is from: https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
	ft::pair<ft::map<int, int>::iterator, bool> test = m.insert(ft::make_pair(8, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test1 = m.insert(ft::make_pair(3, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test2 = m.insert(ft::make_pair(10, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test3 = m.insert(ft::make_pair(14, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test4 = m.insert(ft::make_pair(13, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test5 = m.insert(ft::make_pair(1, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test6 = m.insert(ft::make_pair(6, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test7 = m.insert(ft::make_pair(4, 1));
	ft::pair<ft::map<int, int>::iterator, bool> test8 = m.insert(ft::make_pair(7, 1));

	ft::map<int, int>::iterator it = m.begin();

	++it;
	++it;
	// std::cout << it->first;
	++it;
	// std::cout << it->first;
	++it;
	// std::cout << it->first;
	++it;
	std::cout << it->first;
	++it;
	++it;
	std::cout << it->first;
	++it;
	std::cout << it->first;
	// m.test();
}