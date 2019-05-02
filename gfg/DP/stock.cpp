#include<iostream>

using namespace std;

struct interval{
    int buy;
    int sell;
};

int maxProfit(int *arr, int n)
{
    interval stock[n/2+1];
    int count = 0;
    int i = 0;
    while (i < n-1) {
        while( i < n -1 && arr[i] > arr[i+1]) {
            i++;
        }
        
        if (i == n -1)
            break;

        stock[count].buy = i;

        while( i < n -1 && arr[i] < arr[i+1]) {
            i++;
        }
        stock[count].sell = i;
        count++;
    }  
    if (count == 0)
        cout << "no profit will gain" << endl;
    else {
        for ( i = 0; i < count ; i++) 
            cout << stock[i].buy << " " << stock[i].sell << endl;
    }
}

int main() {
    int arr[] = {100,180,260,40,535,680};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxProfit(arr, n);
    return 0;
}
