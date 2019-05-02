#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort012(int *arr, int n)
{
    int lo = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high) {
	switch(arr[mid]) {
	    case 0:
		swap(&arr[mid++], &arr[lo++]);
		break;
	    case 1:
		mid++;
		break;
	    case 2:
		swap(&arr[mid], &arr[high--]);
		break;
	}
    }
}

int main() {
    int arr[] = {0,1,2,0,1,2};
    sort012(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
	cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
