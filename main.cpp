#include "vector.hpp"
#include <vector>
#include <iostream>

int main(void)
{
	ft::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	ft::vector<int>::reverse_iterator it(vec.begin());
	ft::vector<int>::reverse_iterator it2(vec.end());

	std::cout << (it < it2) << std::endl;
}
