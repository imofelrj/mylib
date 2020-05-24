#include <cstdio> // getchar && putchar
#include <cctype> // isdigit

inline int read()
{
    int x = 0 , ch = getchar();
    // if you are using C++98 or C++ 03
    // please add 'register' before int in Line 6 so as to get faster velocity
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0' , ch = getchar();
    return x;
} //regular
inline void print(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
} //regular
