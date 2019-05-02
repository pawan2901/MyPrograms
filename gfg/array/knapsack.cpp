#include<iostream>

using namespace std;

int knapsack(int *w, int *v, int n, int W) {
    int T[n+1][W+1] ;
    cout << "n " << n << endl;
    for(int i=0; i<n; i++)
	cout << w[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
	cout << v[i] << " ";
    cout << endl;
    for(int r = 0; r<n+1; r++) {
	for(int c = 0; c<W+1; c++) {
	    if(r == 0 || c == 0)
		T[r][c] = 0;
	    else if(c >= w[r-1]) {
		T[r][c] = T[r-1][c] < (v[r-1]+T[r-1][c- w[r-1]]) ?(v[r-1]+T[r-1][c- w[r-1]]) :T[r-1][c];
	    }else {
		T[r][c] = T[r-1][c];
	    }
	}
    }
   
    cout << "====" << endl;
    for(int r = 0; r<n+1; r++) {
	for(int c = 0; c<W+1; c++) {
	    cout << T[r][c] << " " ;
	}
	cout << endl;
    }
    return T[n][W];
}

int main() {
    int w[]= {1,3,4,5};
    int v[]={1,4,5,7};
    int W = 7;
    cout << knapsack(w,v,sizeof(w)/sizeof(int),W)<< endl;
    if( 5 >= 9)
	cout << "TRUE" << endl;
    return 0;
}
