#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define MAX 100


int findMedian(int A[][MAX], int r, int c)
{
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < r; i++) {
        if (A[i][0] < min)
            min = A[i][0];

        if (A[i][c-1] > max)
            max = A[i][c-1];
    }

    while (min < max) {
        int place = 0;
        int mid = (min + max) / 2;
        for (int i = 0; i < c; i++)
            place += upper_bound(A[i], A[i]+c, mid) - A[i];
        if (place < (r*c+1)/2)
            min = mid+1;
        else
            max = mid;
    }
    return min;
}

int main() {
    int A[][MAX] = {{1,3,5},{2,6,9},{3,6,9}};
    cout << findMedian(A, 3, 3) << endl;
    return 0;
}
