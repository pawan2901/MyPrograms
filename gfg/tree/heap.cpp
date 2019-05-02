#include<iostream>

using namespace std;

class MinHeap {
    int hsize;
    int cap;
    int *harr;
    public:
    MinHeap(int cap);
    void heapify(int i);
    void heapInsert(int k);
    int par(int i) {return ((i-1)/2);};
    int left(int i) {return (2*i+1);};
    int right(int i) {return (2*i+2);};
    void display();
};

MinHeap::MinHeap(int capacity) {
    cap = capacity;
    hsize = 0;
    harr = new int[cap];
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void MinHeap::heapInsert(int k) {
    if(hsize == 0) {
	harr[hsize++] = k;
	return ;
    }
    int i = hsize++;
    harr[i] = k;
    while(i > 0 && (harr[par(i)] > harr[i])) {
	swap(&harr[par(i)], &harr[i]);
	i--;
    }
}

void MinHeap::display() {
    for(int i=0; i< hsize; i++) {
	cout << " " <<  harr[i] << " ";
    }
    cout << endl;
}

int main() {
    MinHeap h(10);
    h.heapInsert(5);
    h.heapInsert(9);
    h.heapInsert(19);
    h.heapInsert(8);
    h.display();
    return 0;
}
