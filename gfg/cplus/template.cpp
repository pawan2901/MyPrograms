#include <iostream>

using namespace std;

template<typename T>

T fun(T x, T y)
{
    return (x*y);
}

int main()
{
    cout << fun(5,6) << endl;
    cout << fun(5.3,6.5) << endl;
}
