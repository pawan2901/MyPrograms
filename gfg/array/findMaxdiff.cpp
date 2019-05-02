#include<iostream>

using namespace std;

class array{
public:
    int arr [7] ; 
    array();
    int findMaxDiff();
};

array::array() {
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 10;
    arr[4] = 6;
    arr[5] = 4;
    arr[6] = 8;
    arr[7] = 1;
}

int array::findMaxDiff() {
   int max_diff = arr[1] -arr[0];
   int min_ele = arr[0];
   for(int i=1; i<sizeof(arr)/sizeof(int);i++) {
       if(max_diff < arr[i] - min_ele)
	   max_diff  = arr[i] -min_ele;
       if(arr[i] < min_ele) {
	   min_ele = arr[i];
       }
   }
   return max_diff;
}

int main() {
    array a;
    cout << a.findMaxDiff()<< endl;
    return 0;
}
