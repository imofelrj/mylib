#include <iostream>
#include "myvector.hpp"
myvector<int> v;
int main()
{
    v.push_back(2);
    std::cout<<v[0]<<std::endl;
}

