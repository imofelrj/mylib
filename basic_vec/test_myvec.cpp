#include <iostream>
#include "basic_vector.hpp"
myvector<int> v;
int main()
{
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.erase(2);
    std::cout<<v[0]<<v[1]<<v[2]<<std::endl;
}

