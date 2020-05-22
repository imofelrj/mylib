#include "alloc_vec.hpp"
#include <bits/stdc++.h>
using namespace std;
alloc_vec<int> v;
int main(){
    for (int i=0;i<10000;i++)  v.push_back(i);
    for (int i=0;i<10000;i++)  cout<<v[i]<<" ";
}
