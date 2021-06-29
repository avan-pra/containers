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

	ft::vector<int>::iterator it = vec.begin() + 2;
	vec.insert(it, 9);

	for (ft::vector<int>::iterator iti = vec.begin(); iti != vec.end(); ++iti)
		std::cout << *iti << std::endl;
}
