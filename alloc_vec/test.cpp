#include <iostream>
#include "alloc_vec.hpp"

alloc_vec<int> v;

int main() 
{
    for (int i=0;i<1000000;i++)  v.push_back(i);
}
