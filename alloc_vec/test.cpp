#include <iostream>
#include "alloc_vec.hpp"

alloc_vec<int> v;

int main() 
{
    for (int i=0;i<10000;i++)   v.push_back(i),std::cout<<v[i]<<std::endl;
}
