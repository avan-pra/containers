#include "map.hpp"
#include <map>
#include <iostream>

int             main(void)
{
	// test1212 bjr;

	ft::map<int, int> m;			//tree is from: https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
	m.insert(ft::make_pair(8, 1));
	m.insert(ft::make_pair(3, 1));
	m.insert(ft::make_pair(10, 1));
	m.insert(ft::make_pair(14, 1));
	m.insert(ft::make_pair(13, 1));
	m.insert(ft::make_pair(1, 1));
	m.insert(ft::make_pair(6, 2));
	m.insert(ft::make_pair(4, 1));
	m.insert(ft::make_pair(7, 1));
	m.insert(ft::make_pair(-1, 1));


	m.clear();
	m.insert(ft::make_pair(10, 1));
	
	
	// m[25] = 12;
	// m[26] = 13;

	ft::map<int, int>::iterator it;
	// ft::map<int, int>::iterator it = m.begin();
	// std::cout << it->second << std::endl;
	// m.erase(it);

	//std::cout << m.erase(8) << std::endl;
	for (it = m.begin(); it != m.end(); ++it)
	{
		std::cout << it->first << std::endl;
	}
	std::cout << "yo" << std::endl;
	// ft::map<int, int>::iterator it = m.begin();
	// ft::map<int, int>::iterator it2 = m.begin();
	// --it;
	// std::cout << (it == it2) << std::endl;
	// std::cout << it->first << std::endl;
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
	// m.test();

}