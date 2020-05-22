// github test

#pragma once
#include <cstring> // memset
#include <algorithm> // std::fill, std::lower_bound
#include <stdexcept> //std::out_of_range
#include <ostream> // std::ostream

template<typename T>
class myvector;

template<typename T>
std::ostream& operator << (std::ostream& os,const myvector<T> &mv)
{
    for (int i=0;i<mv.size();i++)   os<<mv[i]<<" ";
    return os;
}

template<typename T>
class myvector{
    protected:
        int maxn=100,sizenow=0;
        T * item = new T[100];T null = item[0];
        void update(int maxn);
    public:
        friend std::ostream& operator << <> (std::ostream& os,const myvector<T> &mv);
        myvector()  {}
        myvector(int size,T it);
        myvector(const myvector<T> &mv)  {*this = mv;}
        ~myvector() {delete[] item;}
        inline void push_back(const T& item0);
        inline void push_front(const T& item0) {insert(0,item0);}
        inline void erase(const int& pos);
        inline void insert(const int& pos,const T& it);
        inline void pop_back() {erase(sizenow-1);}
        inline void pop_front() {erase(0);}
        inline void clear();
        inline bool accuratefind(const int& left,const int& right,const T& item0) const ;
        inline bool find(const T& item0) const ;
        inline bool empty() const ;
        inline T * begin() const {T * res = &item[0];return res;}
        inline T * end() const {T * res = &item[sizenow-1];return res;}
        inline T front() const {return *begin();}
        inline T back() const {return *end();}
        inline int size()  const {return sizenow;}
        inline int capacity() const {return maxn;}
        inline T& operator [] (const int& n) const ;
        myvector operator = (const myvector<T> &mv);
        myvector operator = (const int& n);
        myvector operator + (const myvector<T> &mv);
        myvector operator += (const myvector<T> &mv);
        bool operator == (const myvector<T> &mv) const ;
        bool operator != (const myvector<T> &mv) const ;
    /*
        TOTAL:
            20 functions
            7 operators
            faster than std::vector
            easy to control
            no iterator
    */
};
template<typename T>
inline
void myvector<T>::update(int maxn) {
    T * copied = new T[maxn];
    for (int i=0;i<sizenow;i++)
        copied[i] = item[i];
    delete[] item;
    item = new T[maxn];
    for (int i=0;i<sizenow;i++)  item[i] = copied[i];
    delete[] copied;
}
template<typename T>
inline
myvector<T>::myvector(int size,T it)  {
    fill(item,item+size,it);
    maxn = size;
    sizenow = maxn;
}
template<typename T>
inline
void myvector<T>::push_back(const T& item0)
{
    if (sizenow==maxn-1)   maxn *= 2,update(maxn);
    item[sizenow] = item0;
    ++ sizenow;
}
template<typename T>
inline
bool myvector<T>::empty() const
{
    return sizenow==0;
}
template<typename T>
inline
void myvector<T>::erase(const int& pos)
{
    T end = item[sizenow-1];
    sizenow--;
    if (pos==sizenow-1) return;
    for (int i=pos;i<sizenow-1;i++){
        item[i] = item[i+1];
    }
    item[sizenow-1] = end;
}
template<typename T>
inline
void myvector<T>::insert(const int& pos,const T& it)
{
    if (sizenow==maxn-1)    maxn*=2,update(maxn);
    T end = item[sizenow-1];
    ++ sizenow;
    for (int i=sizenow-1;i>pos;--i) item[i] = item[i-1];
    item[pos] = it;
}
template<typename T>
inline
void myvector<T>::clear()
{
    memset(item,0,sizenow);
    sizenow = 0;
}
template<typename T>
inline
bool myvector<T>::accuratefind(const int& left,const int& right,const T& item0) const
{
    for (int i=left;i<right;i++)
        if (item[i]==item0) return true;
    return false;
}
template<typename T>
inline
bool myvector<T>::find(const T& item0) const
{
    return accuratefind(0,sizenow,item0);
}
template<typename T>
inline
T& myvector<T>::operator [] (const int& n) const
{
    if (n<sizenow)
        return this->item[n];
    if (n==-1)
        return this->item[sizenow-1];
    else
        throw std::out_of_range("out of range error\n");
}
template<typename T>
inline
myvector<T> myvector<T>::operator = (const myvector<T> &mv)
{
    this->clear();
    for (int i=0;i<mv.size();i++)   this->push_back(mv[i]);
    return *this;
}
template<typename T>
inline
myvector<T> myvector<T>::operator + (const myvector<T> &mv)
{
    for (int i=0;i<mv.size();i++)   this->push_back(mv[i]);
    return *this;
}
template<typename T>
inline
myvector<T> myvector<T>::operator = (const int& n)
{
    this->clear();
    return *this;
}
template<typename T>
inline
bool myvector<T>::operator == (const myvector<T> &mv) const
{
    if (this->sizenow!=mv.size())   return false;
    for (int i=0;i<this->sizenow;i++)
        if (this->item[i]!=mv[i])   return false;
    return true;
}
template<typename T>
inline
myvector<T> myvector<T>::operator += (const myvector<T> &mv)
{
    myvector<T> res;
    res = *this + mv;
    return res;
}
template<typename T>
inline
bool myvector<T>::operator != (const myvector<T> &mv) const
{
    return *this==mv;
}


