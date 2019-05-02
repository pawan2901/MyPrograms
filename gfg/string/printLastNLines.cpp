#include<iostream>
#include<string.h>

using namespace std;
#define DELMTR '\n'

void printLastNLines(char *str, int n) {
    int cnt = 0;
    char *pos = NULL;
    if(!str) return;
    pos = strrchr(str, DELMTR);
    if(!pos) {
	cout<< "DELMTR not present"<< endl;
    }
    while(cnt < n) {
	while(str < pos && *pos != DELMTR) {
	    pos--;
	}
	if(*pos == DELMTR) {
	    pos--; cnt++;
	}
	else
	    break;
    }
    cout << pos << endl;
    if(str < pos)
	pos += 2;
    cout << "logs starts" << endl;
    cout << pos << endl;
}


int main() {
    char *str1="str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8";
    char *str2="str1\nstr2\nstr3\nstr4";
    char *str3="\n";
    char *str4="";
    printLastNLines(str1,4);
    return 0;
}
