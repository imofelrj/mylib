#include <iostream>
#include "alloc_vec_new.hpp"

alloc_vec<int> v;

int main()
{
    for (int i=0;i<1000000;i++)  v.push_back(i);
    v.clear();
    v.push_back(1);
    std::cout<<v[0];
    alloc_vec<int> v1;
    v1=v;
    std::cout<<v1[0]<<std::endl;
}
