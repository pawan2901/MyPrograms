#include<iostream>
#include<string.h>

using namespace std;

void swap(char *a, char *b) 
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void per(char *s, int l, int r)
{
    if (l == r)
        cout<< s << endl;
    else {
        for (int i = l; i < r; i++) {
            swap(s+l,s+i);
            per(s, l+1, r);
            swap(s+l,s+i);
        }
    }
}

int main() {
    char s[] = "abc";
    per(s,0,strlen(s));
    return 0;
}
