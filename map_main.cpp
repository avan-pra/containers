#include <iostream>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

int main () 
{
    srand(time(NULL));

    ft::map<char, int> map;
    ft::map<char, int> map2;
    ft::pair<char, int> p;

    //INSERT
    std::cout << "Map Test" << std::endl;
    std::cout << "Test Insert" << std::endl;
    char c = 'a';

    for (int i = 1; i < 11; i++)
    {
        p.first = c++;
        p.second = i;
        std::cout << "map.insert(" << ")" << std::endl;
        map.insert(p);
    }
	std::cout << "yo" << std::endl;
    std::cout << "map.size() = " << map.size() << " |TOP = " << map.rbegin()->first << " |LOWER = " << map.begin()->first << std::endl;
    std::cout << "Print data in map via iterator:" << std::endl;
    for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }

    ft::map<char, int>::iterator it = map.begin();
    it++;
    it++;
    it++;
    std::cout << "\nAdd values in map2 with range iterator:" << std::endl;
    map2.insert(it, map.end());
    std::cout << "Print data in map2 via iterator:" << std::endl;
    for (ft::map<char, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }
    std::cout << "map.size() = " << map2.size() << std::endl;

    std::cout << "\nAdd three first values of map into map2 with hint:" <<std::endl;
    it = map.begin();
    ft::map<char, int>::iterator it2 = map2.begin();
    for (int i = 0; i < 3; i++)
    {
        map2.insert(it2, *it);
        it++;
        it2 = map2.begin();
        it2++;
    }
    std::cout << "Print data in map2 via iterator:" << std::endl;
    for (ft::map<char, int>::iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }
    std::cout << "map.size() = " << map2.size() << std::endl;
	std::cout << "Erase begin() of map being: " << map.begin()->first << std::endl;
    map.erase(map.begin());
    std::cout << "Print data in map via iterator:" << std::endl;
    for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }
    std::cout << "map.size() = " << map.size() << std::endl;

    ft::map<char, int>::iterator m_end = map.end();
    // std::cout << "LOL: " << map.end()->second << std::endl;
    it = map.begin();
    it++; it++;
    m_end--; m_end--; m_end--;
    std::cout << "Erase begin()+2 to end()-1 from map: " << it->first << " to " << m_end->first << std::endl;
    map.erase(it, m_end);
    std::cout << "Print data in map via iterator:" << std::endl;
    for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "[" << it->first << "] = " << it->second << std::endl;
    }

	{
		std::cout << "Testing all iterator type:" << std::endl;
		ft::map<char, int>::iterator it = map.begin();
		ft::map<char, int>::const_iterator it2 = map.begin();
		ft::map<char, int>::reverse_iterator it3 = map.rbegin();
		ft::map<char, int>::const_reverse_iterator it4 = map.rbegin();
		++it; ++it2; ++it3; ++it4;
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
		std::cout << "[" << it2->first << "] = " << it2->second << std::endl;
		std::cout << "[" << it3->first << "] = " << it3->second << std::endl;
		std::cout << "[" << it4->first << "] = " << it4->second << std::endl;
	}

    {
        std::cout << "Testing empty & size and clear" << std::endl;
        std::cout << "map size: " << map.size() << " empty ? " << map.empty() << std::endl;
        map.clear();
        std::cout << "map size: " << map.size() << " empty ? " << map.empty()  << std::endl;
    }
	return 0;
}