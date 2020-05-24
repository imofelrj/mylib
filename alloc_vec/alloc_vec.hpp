#pragma once

#include <memory>

template<class T>
class alloc_vec
{
protected:
    int maxn=100,sizenow=0;
    std::allocator<T> alloc;
    T * a = alloc.allocate(maxn);
    inline void update();
public:
    inline void push_back(const T & item0);
    alloc_vec() = default;
    ~alloc_vec();
    T operator [] (const int & n) const ;
};
template<class T>
inline
void alloc_vec<T>::update()
{
    maxn *= 2;
    T * b = alloc.allocate(maxn);
    for (int i=0;i<sizenow;++i)
        alloc.construct(b+i,*(a+i));
    a = b;
}
template<class T>
inline
void alloc_vec<T>::push_back(const T& item0)
{
    if (sizenow==maxn-1)    update();
    alloc.construct(a+sizenow,item0);
    ++ sizenow;
}
template<class T>
T alloc_vec<T>::operator [] (const int & n) const
{
    return *(a+n);
}
template<class T>
alloc_vec<T>::~alloc_vec()
{
    for (int i=0;i<maxn;i++)
        alloc.destroy(a+i);
    alloc.deallocate(a,maxn);
}
