#include <iostream>
#include "alloc_vec.hpp"

alloc_vec<int> v;

int main() 
{
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.insert(1,2);
    // 2 2 3 4
    v.erase(2);
    std::cout<<v[0]<<v[1]<<v[2]<<std::endl;
}
