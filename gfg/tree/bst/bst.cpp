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
#include <stack>
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
    node *left;
    node *right;
};

node *getNewNode(int ele)
{
    node *tmp = new node;
    tmp->data = ele;
    tmp->left = tmp->right = NULL;
}

void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

node *insertNode(node *root, int ele)
{
    if (root == NULL) {
        node *tmp = getNewNode(ele);
        return tmp;
    } 
    if (root->data > ele) {
        root->left = insertNode(root->left, ele);
    } else {
        root->right = insertNode(root->right, ele);
    }
    return root;
}

node *getMinNode(node *root)
{
    node *cur = root;
    while(cur->left != NULL)
        cur = cur->left;
    return cur;
}

node *deleteNode(node *root, int ele)
{
    if (root == NULL) {
        return root;
    }

    if (root->data > ele) {
        root->left = deleteNode(root->left, ele);
    } else if (root->data < ele) {
        root->right = deleteNode(root->left, ele);
    } else {
        if( root->left == NULL) {
            node *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            node *tmp = root->left;
            free(root);
            return tmp;
        } else {
            node *tmp = getMinNode(root->right);
            root->data = tmp->data;
            deleteNode(root->right, tmp->data);
            return root;
        }
    }
}

node *lcaBtUtil(node *root, int e1, int e2)
{
    if (root == NULL)
        return root;
        cout << "-->" << root->data << endl;
    if (root->data == e1 || root->data == e2) {
        return root;
    }
    node *l = lcaBtUtil(root->left, e1, e2);
    node *r = lcaBtUtil(root->right, e1, e2);
    if ( l != NULL && r!= NULL) {
        cout << "b" << endl;
        cout << l->data << endl;
        cout << r->data << endl;
        cout << root->data << endl;
        return root;
    } else if (l != NULL) {
        cout << l->data << endl;
        return l;
    } else
        return r;
}

int lcaBt(node *root, int e1, int e2)
{
    if (root == NULL)
        return 0;
    node * trp = lcaBtUtil(root, e1, e2);
    cout << "t" << trp->data << endl;
    return trp->data;
}

int lca(node *root, int e1, int e2)
{
    if (root == NULL)
        return 0;
    if (root->data > e1 && root->data > e2) {
        return lca(root->left, e1, e2);
    } else if (root->data < e1 && root->data < e2) {
        return lca(root->right, e1, e2);
    } else {
        return root->data;
    }
}

void printPreorderI(node * root)
{
    if(root == NULL)
        return;
    stack<node *> st;
    st.push(root);
    while (st.size() != 0) {
        root = st.top();
        cout << root->data << " ";
        st.pop();
        if(root->left)
            st.push(root->left);
        if(root->right)
            st.push(root->right);
    }
}

int distaceTwoNode(node *root, int e1, int e2)
{
}
   
int kthEleUtil(node *root, int k, int *i)
{
   if(root==NULL)
       return 0;
   int l = 0;
   int r = 0;
   if ((l = kthEleUtil(root->left, k, i)) != 0)
       return l;
   if ( *i == k)
       return root->data;
   cout << *i << endl;
   *i += 1;
   if ((r = kthEleUtil(root->right, k, i)) != 0)
       return r;
}

int kthEle(node *root, int k)
{
   if(root==NULL)
       return 0;
   int i = 0;
   return kthEleUtil(root, k, &i);
}

int getLarLestUtil(node *root, int k, int &pre)
{
    if(root == NULL)
        return 0;
    int l = 0;
    int r = 0;
    if ((l = getLarLestUtil(root->left, k, pre)) != 0)
        return l;
    if (root->data >= k && k > pre)
        if(pre == -1)
            return root->data;
        else
            return pre;
    pre = root->data;
    if (( r = getLarLestUtil(root->right, k, pre)) != 0)
        return r;
}

int getLarLest(node *root, int k)
{
    if(root == NULL)
        return NULL;
    int pre = -1;
    return getLarLestUtil(root, k, pre);
}

int main() {
    node *root;
    root = getNewNode(50);
    root->left = getNewNode(25);
    root->right = getNewNode(75);
    root->left->left = getNewNode(15);
    root->left->right = getNewNode(35);
    root->right->left = getNewNode(65);
    root->right->right = getNewNode(85);


    cout << "Inorder ";
    printInorder(root);
    cout << endl;

    cout << "kth element : 1 pos" << endl;
    cout << kthEle(root, 0) << endl;

    cout << "kth element : 3 pos" << endl;
    cout << kthEle(root, 2) << endl;

    cout << "kth element : 7 pos" << endl;
    cout << kthEle(root, 6) << endl;

    cout << "largest bust less from 84" << endl;
    cout << getLarLest(root, 84) << endl;
    cout << "largest bust less from 36" << endl;
    cout << getLarLest(root, 36) << endl;
    cout << "largest bust less from 100" << endl;
    cout << getLarLest(root, 100) << endl;
    cout << "largest bust less from 85" << endl;
    cout << getLarLest(root, 85) << endl;

    root = insertNode(root, 100); 

    cout << "Inorder ";
    printInorder(root);
    cout << endl;

    cout << "pre0rder ";
    printPreorderI(root);
    cout << endl;
    

#if 0
    deleteNode(root, 15);

    cout << "Inorder ";
    printInorder(root);
    cout << endl;

    deleteNode(root, 25);

    cout << "Inorder ";
    printInorder(root);
    cout << endl;

    deleteNode(root, 50);

    cout << "Inorder ";
    printInorder(root);
    cout << endl;

    root = insertNode(root, 15); 
    root = insertNode(root, 25); 
    root = insertNode(root, 50); 

    cout << "Inorder ";
    printInorder(root);
    cout << endl;
#endif

    cout << "lca of 15 and 25 = ";
    cout << endl;
    cout << lca(root, 15, 25);
    cout << endl;
        
    cout << "lca of 15 and 35 = ";
    cout << endl;
    cout << lca(root, 15, 35);
    cout << endl;

    cout << "lca of 15 and 100 = ";
    cout << lca(root, 15, 100);
    cout << endl;

    
    cout << "lca of bt 15 and 100 = ";
    cout << endl;
    cout << lcaBt(root, 15, 100);
    cout << endl;
    cout << "lca of bt 15 and 25 = ";
    cout << endl;
    cout << lcaBt(root, 15, 25);
    cout << endl;

    cout << "dis between two node" << endl;
    cout << distaceTwoNode(root, 15, 25);
    cout << endl;



    return 0;
}
