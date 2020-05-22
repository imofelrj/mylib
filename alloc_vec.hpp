#pragma once

#include <memory>

template<class T>
class alloc_vec
{
protected:
    std::allocator<T> alloc;
    T* a = alloc.allocate(maxn);
    int maxn=100,sizenow=0;
    void update();
    
public:
    alloc_vec() {}
    ~alloc_vec() {}
    void push_back(const T& item0);
    T operator [] (const int & n);
};
template<class T> 
void alloc_vec<T>::push_back(const T& item0)
{
    if (sizenow==maxn-2)  update();
    this->alloc.construct(a+sizenow,item0);
    ++ sizenow ;
}
template<class T>
T alloc_vec<T>:: operator [] (const int & n)
{
    return *((this->a)+n);
}
template<class T>
void alloc_vec<T>::update()
{
    maxn *= 2;
    T* b = this->alloc.allocate(maxn);
    for (int i=0;i<sizenow;++i)
        *(b+i) = *(a+i);
    a = alloc.allocate(maxn);
    a = b;
}
