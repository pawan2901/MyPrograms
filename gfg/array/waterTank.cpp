#include<iostream>

using namespace std;

int waterOnTank(int *arr, int len)
{
    int total_water = 0;
    int l = 0;
    int r = 1;
    int breadth = 0;
    while ( r < len-1) {
        int block = 0;
        breadth = 0;
        while ( arr[l] <= 0 )
            l++;
        r = l + 1;
        while ( arr[r] <= arr[l]) {
            breadth++;
            block += arr[r];
            r++;
        }
        cout << arr[l] << " " << arr[r] << " " << breadth << " " << block << endl;
        if ( arr[l] > arr[r]) {
            total_water += (arr[r]*(breadth))-block;
        } else {
            total_water += (arr[l]*(breadth))-block;
        }
        cout << "total_water " << total_water << endl;
         l  = r;
         if ( r == len -1) {
             l ++; r = l ; 
         }
    }
    return total_water;
}

int main() {
    int arr[] = {2,0,1,3,2,1,1,4};
    int len  = sizeof(arr)/sizeof(int);
    cout << waterOnTank(arr,len) << endl;
    cout << " first " << endl;
    int arr1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    len  = sizeof(arr1)/sizeof(int);
    cout << waterOnTank(arr1,len) << endl;
    
    return 0;
}
