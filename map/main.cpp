#include "map.hpp"
#include <map>
#include <iostream>

int             main(void)
{
	// test1212 bjr;

	std::map<int, int> m;			//tree is from: https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
	m.insert(std::make_pair(8, 1));
	m.insert(std::make_pair(3, 1));
	m.insert(std::make_pair(10, 1));
	m.insert(std::make_pair(14, 1));
	m.insert(std::make_pair(13, 1));
	m.insert(std::make_pair(1, 1));
	m.insert(std::make_pair(6, 1));
	m.insert(std::make_pair(4, 1));
	m.insert(std::make_pair(7, 1));

	std::map<int, int>::iterator it = m.begin();
	std::map<int, int>::iterator it2 = m.begin();
	it--;
	std::cout << (it == it2) << std::endl;
	// ft::cout << it->first << std::endl;
	// ft::map<int, int>::iterator it = m.begin();

	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// --it;
	// std::cout << it->first << std::endl;

	// --it;
	// m.test();

}