#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct point{
    int first;
    int second;
    int third;
};


bool findMaxTripSumSubArrEff(int *a, int n, int sum)
{
    //create map for hashing
    unordered_set<int> s;
    //tripelate required so this loop must be end before remaining two elements.
    for (int i = 0; i<n-2; i++) {
        //lets assume first element is searched, so remove from the sum.
        sum = sum - a[i];
        for (int j=i+1; j<n; j++) {
            if(s.find(sum-a[j]) != s.end())
                return true;
            s.insert(a[j]);
        }
    }
}


int main() {
    int arr[] = {12, 3, 4, 1, 6, 9};
    int sum = 24;
    cout << findMaxTripSumSubArrEff(arr, sizeof(arr)/sizeof(arr[0]), sum)<< endl;
    return 0;
}
