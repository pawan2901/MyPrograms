#include<iostream>
#include<stack>

using namespace std;

void findNextGreaterElement(int *arr, int n) {
    int inx = 0;
    stack<int> stk;
    stk.push(arr[inx++]);
    while(inx < n) {
	if( arr[inx] > stk.top()) {
	    cout << stk.top() << "->" <<  arr[inx] << endl;
	    stk.pop();
	    if(stk.size() == 0) {
		stk.push(arr[inx++]);
	    }
	} else {
	    stk.push(arr[inx++]);
	}
    }
    while(stk.size() != 0) {
	cout << stk.top() << "->" << -1 << endl;
	stk.pop();
    }
}

int main() {
    int arr[] = {6,9,11,2,1,5};
    findNextGreaterElement(arr,sizeof(arr)/sizeof(int));
    return 0;
}
