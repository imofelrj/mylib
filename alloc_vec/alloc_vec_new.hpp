// github test

#pragma once
#include <cstring> // memset
#include <algorithm> // std::fill, std::lower_bound
#include <stdexcept> //std::out_of_range
#include <ostream> // std::ostream
#include <memory> // std::allocator

template<typename T>
class alloc_vec;

template<typename T>
std::ostream& operator << (std::ostream& os,const alloc_vec<T> &mv)
{
    for (int i=0;i<mv.size();i++)   os<<mv[i]<<" ";
    return os;
}

template<typename T>
class alloc_vec{
    protected:
        int maxn=100,sizenow=0;
        std::allocator<T> alloc;
        T * a = alloc.allocate(maxn);
        inline void update();
    public:
        friend std::ostream& operator << <> (std::ostream& os,const alloc_vec<T> &mv);
        alloc_vec()  {}
        alloc_vec(const alloc_vec<T> &mv)  {*this = mv;}
        ~alloc_vec();
        inline void push_back(const T& item0);
        inline void push_front(const T& item0) {insert(0,item0);}
        inline void erase(const int& pos);
        inline void insert(const int& pos,const T& it);
        inline void pop_back() {erase(sizenow-1);}
        inline void pop_front() {erase(0);}
        inline void clear();
        inline bool empty() const ;
        inline T front() const {return *a;}
        inline T back() const {return *(a+sizenow);}
        inline int size()  const {return sizenow;}
        inline int capacity() const {return maxn;}
        inline T& operator [] (const int& n) const {return *(a+n);};
        alloc_vec & operator = (const alloc_vec<T> &mv);
        /*
        alloc_vec operator = (const int& n);
        alloc_vec operator + (const alloc_vec<T> &mv);
        alloc_vec operator += (const alloc_vec<T> &mv);
        bool operator == (const alloc_vec<T> &mv) const ;
        bool operator != (const alloc_vec<T> &mv) const ;
        */
};
template<typename T>
alloc_vec<T>::~alloc_vec()
{
    for (int i=0;i<maxn;i++)
        alloc.destroy(a+i);
    alloc.deallocate(a,maxn);
}
template<typename T>
inline
void alloc_vec<T>::update() {
    maxn *= 2;
    T * b = alloc.allocate(maxn);
    for (int i=0;i<sizenow;++i)
        alloc.construct(b+i,*(a+i));
    a = b;
}
template<typename T>
inline void alloc_vec<T>::clear()
{
    for (int i=0;i<sizenow;i++)
        alloc.destroy(a+i);
    alloc.deallocate(a,maxn);
    a = alloc.allocate(maxn);
    sizenow = 0;
}
template<typename T>
inline
void alloc_vec<T>::push_back(const T& item0)
{
    if (sizenow==maxn)   maxn *= 2,update();
    alloc.construct(a+sizenow,item0);
    ++ sizenow;
}
template<typename T>
inline
bool alloc_vec<T>::empty() const
{
    return sizenow==0;
}
template<typename T>
inline
void alloc_vec<T>::erase(const int& pos)
{
    auto end = a+sizenow-1;
    -- sizenow ;
    if (pos==sizenow-1)
        return;
    for (int i=pos;i<sizenow-1;++i)
        alloc.construct(a+i,*(a+i+1));
    alloc.construct(a+sizenow-1,*end);
}
template<typename T>
inline
void alloc_vec<T>::insert(const int& pos,const T& item0)
{
    if (sizenow==maxn-1)    update();
    ++ sizenow;
    for (int i=sizenow-1;i>pos;--i)
        alloc.construct(a+i,*(a+i-1));
    alloc.construct(a+pos,item0);
}
/*
template<typename T>
inline
void alloc_vec<T>::clear()
{
    memset(item,0,sizenow);
    sizenow = 0;
}
*/
template<typename T>
inline
alloc_vec<T>& alloc_vec<T>::operator = (const alloc_vec<T> &mv)
{
    for (int i=0;i<mv.size();++i)
        this->push_back(mv[i]);
    return *this;
}
/*
template<typename T>
inline
alloc_vec<T> alloc_vec<T>::operator + (const alloc_vec<T> &mv)
{
    for (int i=0;i<mv.size();i++)   this->push_back(mv[i]);
    return *this;
}
template<typename T>
inline
alloc_vec<T> alloc_vec<T>::operator = (const int& n)
{
    this->clear();
    return *this;
}
template<typename T>
inline
bool alloc_vec<T>::operator == (const alloc_vec<T> &mv) const
{
    if (this->sizenow!=mv.size())   return false;
    for (int i=0;i<this->sizenow;i++)
        if (this->item[i]!=mv[i])   return false;
    return true;
}
template<typename T>
inline
alloc_vec<T> alloc_vec<T>::operator += (const alloc_vec<T> &mv)
{
    alloc_vec<T> res;
    res = *this + mv;
    return res;
}
template<typename T>
inline
bool alloc_vec<T>::operator != (const alloc_vec<T> &mv) const
{
    return *this==mv;
}
*/
