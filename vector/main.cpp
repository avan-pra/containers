#include "vector.hpp"
#include <vector>
#include <iostream>

# define TESTED_NAMESPACE std
# define TESTED_TYPE int

template <typename T>
void    printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = 1)
{
        std::cout << "size: " << vct.size() << std::endl;
        std::cout << "capacity: " << vct.capacity() << std::endl;
        std::cout << "max_size: " << vct.max_size() << std::endl;
        if (print_content)
        {
                typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
                typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
                std::cout << std::endl << "Content is:" << std::endl;
                for (; it != ite; ++it)
                        std::cout << "- " << *it << std::endl;
        }
        std::cout << "###############################################" << std::endl;
}

int             main(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

        for (int i = 0; i < size; ++i)
                vct[i] = (i + 1) * 5;
        printSize(vct);

        // std::cout << (it_ == it.base()) << std::endl;
        // std::cout << (it_ == (it + 3).base()) << std::endl;

        // std::cout << *(it.base() + 1) << std::endl;
        // std::cout << *(it - 3) << std::endl;
        // std::cout << *(it - 3).base() << std::endl;
        it -= 3;
        // std::cout << *it.base() << std::endl;

        std::cout << "TEST OFFSET" << std::endl;
        std::cout << *(it) << std::endl;
        std::cout << *(it).base() << std::endl;
        // std::cout << *(it - 0) << std::endl;
        // std::cout << *(it - 0).base() << std::endl;
        // std::cout << *(it - 1).base() << std::endl;

        return (0);
}