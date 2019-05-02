#include <iostream>
using namespace std;

struct index{
    int first;
    int last;
};

index *printFirstLastOcc(int *arr, int start, int end, int num)
{
    //cout << start << " " << end << endl;
    static index *ret = new index;
    if (start >= end)
        return ret;
    int mid = (start + end) /2;
    if (arr[mid] == num && arr[mid-1] < num) {
        ret->first = mid;
        //cout << "f" << ret->first << endl;
    } else if (arr[mid] == num && arr[mid+1] > num) {
        ret->last = mid;
        //cout << "l" << ret->last << endl;
    }
    if (arr[mid] >= num)
        printFirstLastOcc(arr, start, mid-1, num);  
    if (arr[mid] <= num)
        printFirstLastOcc(arr, mid+1, end, num);  
    return ret;
}

void printFirstOcc(int *arr, int idx, int num)
{
    for(int i=0; i<idx; i++)
        cout << arr[i] << " ";
    cout << endl;
    index *ret = printFirstLastOcc(arr, 0, idx, num);
    cout << ret->first << " " << ret->last << endl;
    return;
}

int main() {
    int tc = 0;
    cin >> tc;
    for (int i=0; i<tc; i++) {
        int idx = 0;
        cin >> idx;
        int num = 0;
        cin >> num;
        int *arr = new int[idx];
        for (int i=0; i<idx; i++)
            cin >> arr[i];
        printFirstOcc(arr, idx, num);
    }
    //code
    return 0;
}
