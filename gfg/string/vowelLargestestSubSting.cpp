#include<iostream>
#include<string.h>

using namespace std;

int findLargestStringCount( char *str)
{
    int cnt = 0;
    char *t1, *t2;
    int vis[26] = {0};
    char vowel[] = "aeiou\n";
    t1 = str;
    t2 = vowel;
    while(*t1 != '\n' && *t2 != '\n') {
        //cout << " t1 "<<*t1;
        //cout << " t2 "<< *t2;
        if (!(*t1 == 'a' || *t1 == 'e'
            || *t1 == 'i' || *t1 == 'o'
            || *t1 == 'u'))
            t1++;
        if (vis[*t1-'a']) {
            //cout << 1 << endl;
            t1++;
            continue;
        }
        if (*t1 == *t2) {
            //cout << 2 << endl;
            cnt++;
            t1++;
        } else {
            //cout << 3 << endl;
            vis[*t2-'a'] = 1;
            t2++;
        }
    }
    cout << cnt << endl;
    return cnt;
}

int main() {
    char str[] = "aeiaaioooaauu\n";
    //cout << str << endl;
    //cout << strlen(str) << endl;
    cout << findLargestStringCount(str) << endl;
    return 0;
}
