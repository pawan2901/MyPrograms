#include<iostream>

using namespace std;

struct point{
    int start;
    int end;
};


void findMaxSumSubArrEff(int *a, int n, int sum)
{
    int cur_sum = a[0];
    int start = 0;
    for (int i=1; i<n; i++) {
        while (cur_sum > sum && start < i) {
            cur_sum = cur_sum - a[start];
            start++;
        }
        if (cur_sum == sum) {
            cout << start << " " << i-1 << endl;
        }

        cur_sum += a[i];
    }
}

void findMaxSumSubArr(int *a, int n, int sum)
{
    point resPoint[n];
    int tmp = 0;
    int j = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++) {
        j = i;
        tmp = sum;
        while (j<n && tmp > 0) {
            tmp = tmp - a[j];
            if(tmp == 0) {
                resPoint[cnt].start = i;
                resPoint[cnt].end = j;
                cnt++;
                break;
            } 
            j++;
        }
    }
    for (int i=0; i<cnt; i++)
        cout << resPoint[i].start << " " << resPoint[i].end << endl;
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int sum = 33;
    findMaxSumSubArr(arr, sizeof(arr)/sizeof(arr[0]), sum);
    findMaxSumSubArrEff(arr, sizeof(arr)/sizeof(arr[0]), sum);
    return 0;
}
