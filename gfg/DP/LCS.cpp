#include<iostream>
#include<string.h>

using namespace std;

int LCS(char *x, char *y, int m, int n)
{
    if (m == 0 || n == 0)
	return 0;
    if (x[m] == y[n]) 
	return (1 + LCS(x,y,m-1,n-1));
    return max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
}

int LCS_DP(char *x, char *y, int m, int n)
{
    int lookup[m+1][n+1];
    for (int i=0; i<m+1; i++) {
	for (int j=0; j<n+1; j++) {
	    if (j ==0 || i ==0) {
		lookup[i][j] = 0;
	    } else if (x[i] == y[j]) {
		lookup[i][j] = lookup[i-1][j-1] + 1;
	    } else {
		lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
	    }
	}
    }
    return lookup[m][n];
}

int main() {
    char *x = "AXYT";
    char *y = "AYZX";
    cout<< "recursive naive solution" << endl;
    cout<< LCS(x,y, strlen(x), strlen(y)) << endl;
    cout<< "DP bottom-up solution" << endl;
    cout<< LCS_DP(x,y, strlen(x), strlen(y)) << endl;
    return 0;
}
