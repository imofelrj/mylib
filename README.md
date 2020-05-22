# mylib in C++
[my luogu account](https://www.luogu.com.cn/user/312489)

This project contains :
+ myvector
+ myio
+ mymath

You can use them easily like this :
```cpp
#include "myvector.hpp"
#include "myio.hpp"
#include "mymath.hpp"
#include <bits/stdc++.h>
using namespace std;
int n;myvector<int> v;bign b;
int main() {
    n = read(); // in myio.hpp
    cin >> n; // in mymath.hpp
    v.push_back(n); // in myvector.hpp
    return 0;
}
```
