#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <sstream>
#include <cstring>

using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)
#define ASST(x, l, r) assert( x <= r && x >= l )


using namespace std;

struct node
{
        int data;
        struct node* next;
};

void insert(node **retList, node **tmp)
{
    cout << (*tmp)->data << endl;
    if(!*retList) {
        *retList = *tmp;
        (*tmp)->next = NULL;
        return;
    }
    node *prev = *retList;
    node *cur = *retList;
    while (cur && cur->data < (*tmp)->data && cur->data != (*tmp)->data) {
        prev = cur;
        cur = cur->next;
    }
    if (cur && cur->data == (*tmp)->data) {
        free(*tmp);
        return;
    }
    if(cur == NULL) {
        prev->next = *tmp;
        (*tmp)->next = NULL;
    } else if (prev == cur){
        (*tmp)->next = cur;
        *retList = *tmp;
    } else {
        (*tmp)->next = cur;
        prev->next = *tmp;
    }
}

node* makeUnion(struct node* head1, struct node* head2)
{
    node *retList = NULL;
    node *tmp1 = head1;
    node *newHead1 = head1;
    node *tmp2 = head2;
    node *newHead2 = head2;
    while (newHead1 || newHead2 ) {
        if(newHead1 && newHead2) {
            cout << newHead1->data << " " << newHead2->data << endl;
            if (newHead1->data < newHead2->data) {
                tmp1 = newHead1;
                newHead1 = newHead1->next;
                insert(&retList, &tmp1);
            } else {
                tmp2 = newHead2;
                newHead2 = newHead2->next;
                insert(&retList, &tmp2);
            }
        } else if (newHead1) {
            tmp1 = newHead1;
            newHead1 = newHead1->next;
            insert(&retList, &tmp1);
        } else if(newHead2) {
            tmp2 = newHead2;
            newHead2 = newHead2->next;
            insert(&retList, &tmp2);
        }
        node *tmp = retList;
        cout << " LIST ";
        while(tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    return retList;
}

node *getNode(int data)
{
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

int main() {
    node *list1 = getNode(5);
    list1->next = getNode(9);
    list1->next->next = getNode(1);
    list1->next->next->next = getNode(2);

    node *list2 = getNode(3);
    list2->next = getNode(4);
    list2->next->next = getNode(2);
    list2->next->next->next = getNode(8);

    makeUnion(list1, list2);

    return 0;
}

