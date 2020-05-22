/*
 * @Author: hero_brine 
 * @Date: 2020-05-06 22:31:48 
 * @Last Modified by:   hero_brine 
 * @Last Modified time: 2020-05-06 22:31:48 
 */
#include "alloc_vec.hpp"
#include <bits/stdc++.h>
using namespace std;
alloc_vec<int> v;
int main(){
    for (int i=0;i<10;i++)  v.push_back(i);
    for (int i=0;i<10;i++)  cout<<v[i]<<" ";
}
