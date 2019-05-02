#include<iostream>
#include<limits.h>

using namespace std;

void fun(int i = 100) {
    cout << i << endl;
}

int main() {
    cout << " min " << INT_MIN << endl;
    cout << " max " << INT_MAX << endl;
    fun(1);
    fun();
    return 0;
}
