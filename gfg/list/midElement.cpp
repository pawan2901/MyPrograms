#include<iostream>

using namespace std;

struct listNode {
    int data;
    listNode *next;
};

listNode *createListNode(int data) {
    listNode *newNode = new listNode;
    newNode->data = data;
    newNode->next = NULL;
}

void createListLast(listNode **head, int data) {
    listNode *tmp ;
    listNode *newNode = createListNode(data);
    cout << newNode->data <<endl;
    if(*head == NULL) {
	*head = newNode;
	return;
    } 
    tmp = *head;
    while(tmp->next != NULL) {
	   tmp = tmp->next; 
    }
    tmp->next = newNode;
}

void printList(listNode *head) {
    listNode *tmp = head;
    while(tmp != NULL){
	cout << tmp->data << " ";
	tmp = tmp->next;
    }
    cout<< endl;
}

void printMidEle(listNode *head) {
    if(!head) 
	return;
    listNode *mid = 0;
    int idx = 0;
    mid = head;
    while(head != NULL) {
	if(idx & 1) {
	    mid = mid->next;
	}
	idx++;
	head= head->next;
    }
    if(mid)
	cout << "Mid element " << mid->data << endl;
}

int main(){
    int i;
    int arr[]= {1,2,3,4,5,6,7,8};
    listNode *head = NULL;
    for(int i=0; i < sizeof(arr)/sizeof(int); i++) {
	createListLast(&head, arr[i]);
    }
    cout << "print list " << endl; 
    printList(head);
    printMidEle(head);

    return 0;
}
