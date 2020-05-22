#pragma once

#include <memory> // std::allocator

template<class T>
class alloc_vec
{
protected:
    std::allocator<T> alloc;
    T* a = alloc.allocate(maxn);
    int maxn=100,sizenow=0;
    void update(const int&);
    
public:
    // alloc_vec() {}
    // ~alloc_vec() {}
    void push_back(const T& item0);
    T operator [] (const int & n);
};
template<class T> 
void alloc_vec<T>::push_back(const T& item0)
{
    if (sizenow==maxn-2)  maxn*=2,update(maxn);
    this->alloc.construct(a+sizenow,item0);
    ++ sizenow ;
}
template<class T>
T alloc_vec<T>:: operator [] (const int & n)
{
    return *(a+n);
}
template<class T>
void alloc_vec<T>::update(const int& maxn)
{
    T* b = this->alloc.allocate(maxn);
    for (int i=0;i<sizenow;++i)
        alloc.construct(b++,*(a++));    
    a = alloc.allocate(maxn);
    a = b;
}

