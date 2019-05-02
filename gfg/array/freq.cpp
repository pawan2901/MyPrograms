#include<iostream>

using namespace std;

int first(int *a, int start, int end, int x, int n)
{
    int mid = (start + end) /2 ;
    if ( start <= end) {
        if((mid == 0 || a[mid-1] < x) && a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x)
            return first(a, mid+1, end, x, n);
        else
            return first(a, start, mid-1, x, n);
    }
    return -1;
}

int last(int *a, int start, int end, int x, int n)
{
    if ( start <= end) {
        int mid = (start + end) /2 ;
        if((mid == n-1 || a[mid+1] > x) && a[mid] == x) {
            return mid;
        }
        else if (a[mid] > x)
            return last(a, start, mid-1, x, n);
        else
            return last(a, mid+1, end, x, n);
    }
    return -1;
}

int frequency(int *a, int n, int x)
{

    int f = first(a, 0, n-1, x, n);
    cout << "f " << f << endl;
    if (f == -1)
        return 0;
    int l = last(a, 0, n-1, x, n);
    cout << "l " << l << endl;
    return l-f+1;
}

int main() {
    int a[] = {1,2,2,2,3,5,5,5,5};
    cout<< frequency(a, sizeof(a)/sizeof(a[0]), 2) << endl;
    return 0;
}
