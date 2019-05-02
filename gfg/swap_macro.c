#include<iostream>
#include<stdio.h>

#define SWAPMAC(a,b) \
    a = a + b; \
    b = a - b; \
    a = a - b;

#define rock \
    printf("ROCK: %s %d \n", __func__, __LINE__);

using namespace std;

int main() {
    int a = 5;
    int b = 6;
    cout << "swap two no's 5 and 6" << endl;
    SWAPMAC(a,b) ;
    cout << a << " " << b << endl;
    printf("ROCK: %s %d \n", __func__, __LINE__);
    rock;
    return 0;
}
