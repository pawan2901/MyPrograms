#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int i) {
    node *tmp = new node;
    tmp->data = i;
    tmp->next = NULL;
    return tmp;
}

bool findLoop(node *head)
{
    unordered_set<node *>s;
    while( head != NULL) {
        if(s.find(head) != s.end()) {
            return 1;
        }
        s.insert(head);
        head = head->next;
    }
    return 0;
}

bool findLoopPointer(node *head)
{
    node *slow;
    node *fast;
    slow = fast = head;
    while (slow && fast && fast->next){
        if(slow == fast) {
            cout << "loop found" << endl;
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main() {
    node *head;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next = head-> next; 
    cout << findLoop(head) << endl;

    cout << "find loop through pointers " << endl;
    cout << findLoopPointer(head) << endl;
    return 0;
}
