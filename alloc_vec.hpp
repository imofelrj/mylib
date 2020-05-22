#pragma once

#include <bits/stdc++.h>

using namespace std;

template<class T>
class alloc_vec
{
protected:
    allocator<T> alloc;
    T* a = alloc.allocate(100);
    int maxn=100,sizenow=0;
    
public:
    alloc_vec() {}
    ~alloc_vec() {}
    void push_back(const T& item0);
    T operator [] (const int & n);
};
template<class T> 
void alloc_vec<T>::push_back(const T& item0)
{
    this->alloc.construct(a+sizenow,item0);
    ++ sizenow ;
}
template<class T>
T alloc_vec<T>:: operator [] (const int & n)
{
    return *((this->a)+n);
}
