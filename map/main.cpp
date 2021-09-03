#include "map.hpp"
#include <map>
#include <iostream>

int             main(void)
{
	// test1212 bjr;

	ft::map<int, int> m;
	m.insert(ft::make_pair(1, 1));
	m.insert(ft::make_pair(2, 2));
	m.insert(ft::make_pair(3, 3));
	m.insert(ft::make_pair(0, 72));

	m.test();
}