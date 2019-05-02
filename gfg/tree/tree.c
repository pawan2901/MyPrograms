#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include <bits/stdc++.h>
#define MAX_ELE 10


using namespace std;

struct treeNode {
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode *createTree(int ele) {
    treeNode *tmp = new treeNode;
    tmp->data = ele;
    tmp->left = NULL;
    tmp->right = NULL;
}

void printTree(treeNode *root) {
    if(!root)
	return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void PreOrderTraversal(treeNode *root) {
    if(!root)
	return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(treeNode *root) {
    if(!root)
	return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PostOrderTraversal(treeNode *root) {
    if(!root)
	return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(treeNode *root) {
    treeNode *tmp;
    if(!root)
	return;
    queue<treeNode *> que;
    que.push(root);
    while(!que.empty()) {
	tmp = que.front();
	cout << tmp->data << " " ;
	que.pop();
	if(tmp->left)
	    que.push(tmp->left);
	if(tmp->right)
	    que.push(tmp->right);
    }
}

int longestDept(treeNode *root) {
    if(!root) {
       return 0;
    }
    int left = 0;
    left += longestDept(root->left);
    int right = 0;
    right += longestDept(root->right);
    if(left > right)
	return left+1;
    else
	return right+1;
}

treeNode * lowestCommonAncestor(treeNode *root, int n1, int n2) {
    if(!root) return NULL;

    if(root->data == n1 || root->data == n2)
	return root;
    treeNode *left = lowestCommonAncestor(root->left, n1, n2);
    treeNode *right = lowestCommonAncestor(root->right, n1, n2);
    if(left && right)
	return root;
    return (left != NULL)? left : right;
}

int findLevel(treeNode *root, int n, int level) {
    int l = 0;
    if(!root) return -1;
    //cout << " " << root->data << " " << n << " " << level << endl;
    if(root->data == n)
	return level;
    l = findLevel(root->left, n, level+1);
    if(l == -1)
	l = findLevel(root->right, n, level+1);
    return l;
}

int distacneVector(treeNode *root, int n1, int n2) {
    int l = 0;
    int r = 0;
    if (!root)
	return 0;
    treeNode *tmp = lowestCommonAncestor(root, n1, n2);
    cout << " DEBUG LOG: lowest common ancestor " << tmp->data << endl;
    l = findLevel(root, n1, 0);
    r = findLevel(root, n2, 0);
    cout << " DEBUG LOG:  depth " << l << " " << r << endl;
    return ((l+r != 0)? (l+r) : 0);    
}

void levelOrderPrintOnLine(treeNode *root) {
    if(!root)
	return;
    queue<treeNode *> tmpque;
    treeNode *tmp;
    tmpque.push(root);
    while(1) {
	int nodeCnt = tmpque.size();
	if(tmpque.size() == 0)
	    break;
	while(nodeCnt > 0) {
	    tmp =  tmpque.front();
	    tmpque.pop();
	    cout << tmp->data << " ";
	    if(tmp->left)
		tmpque.push(tmp->left);
	    if(tmp->right)
		tmpque.push(tmp->right);
	    nodeCnt--;
	}
	cout<< endl;
    }
}

void diagonalVector(treeNode *root,int d, map<int, vector<int> > &diagonalPoint) {
    if(!root) return;
    diagonalPoint[d].push_back(root->data);
    if(root->left) {
	diagonalVector(root->left, d+1, diagonalPoint);
    }
    if(root->right) {
	diagonalVector(root->right, d, diagonalPoint);
    }
}

void diagonalPrint(treeNode *root) {
    map<int, vector<int> > diagonalPoints;
    map<int, vector<int> >::iterator it;
    vector<int>::iterator itr;
    diagonalVector(root, 0, diagonalPoints);
    cout << " diagonal Traversal of binary tree " << endl;
    for(it = diagonalPoints.begin(); it != diagonalPoints.end(); ++it) {
	for(itr = it->second.begin(); itr != it->second.end(); ++itr) {
	    cout << *itr << " ";
	}
	cout << endl;
    }
}

void inorderIterative(treeNode *root) {
    if(!root) return;
    stack<treeNode *> stk;
    treeNode *curr;
    treeNode *tmp;
    curr = root;
    stk.push(curr);
    while(stk.size() != 0) {
	while(curr && curr->left != NULL) {
	    curr = curr->left;
	    stk.push(curr);
	}
	tmp = stk.top();
	cout << tmp->data << " ";
	stk.pop();
	if(tmp->right)
	    stk.push(tmp->right);
	curr = tmp->right;
    }
}

int isBst(treeNode *root, treeNode * l = NULL, treeNode * r = NULL) {
    if(!root)
	return true;
    else if((l && root->data < l->data) || (r && root->data > r->data ))
	return false;
    return (isBst(root->left, l, root) && isBst(root->right, root,r));
}


treeNode *kthSmallestElement(treeNode *root, int k)
{
    stack<treeNode *> st;
    treeNode *crwl = root;
    while(crwl) {
	st.push(crwl);
	crwl = crwl->left;
    }
    while (crwl = st.top()) {
	st.pop();
	if ((--k) == 0) {
	    break;
	}
	if (crwl->right) {
	    crwl = crwl->right;
	    while (crwl) {
		st.push(crwl);
		crwl = crwl->left;
	    }
	}
    }
    return crwl;
}

void inOrder(treeNode *r, vector<int> &v) 
{
    if (r == NULL)
	return;
    inOrder(r->left,v);
    v.push_back(r->data);
    inOrder(r->right,v);
}

int isIdentical(treeNode *r1, treeNode *r2)
{
    vector<int> v1;
    vector<int> v2;
    inOrder(r1,v1);
    inOrder(r2,v2);
    return (v1 == v2 ? 1 : 0);
}

void printLeftBoundary(treeNode *root)
{
    if (root == NULL)
        return;
    if (root->left) {
        cout << root->data << " ";
        printLeftBoundary(root->left);
    } else if (root->right) {
        cout << root->data << " ";
        printLeftBoundary(root->right);
    }
}

void printleafBoundaryNode(treeNode *root)
{
    if (root == NULL) 
        return;
    if (root ->left) {
        printleafBoundaryNode(root->left);
    } 
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    if (root->right) {
        printleafBoundaryNode(root->right);
    } 
}

void printrightBoundary( treeNode *root)
{
    if (root == NULL)
        return;
    if (root->right) {
        printrightBoundary(root->right);
        cout << root->data << " ";
    } else if (root->left) {
        printrightBoundary(root->left);
        cout << root->data << " ";
    }
}

void printBoundary( treeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printleafBoundaryNode(root->left);
    printleafBoundaryNode(root->right);
    printrightBoundary(root->right);
}

void insertMap(treeNode *root, int hd, map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;
    mp[hd].push_back(root->data);
    insertMap(root->left, hd-1, mp);
    insertMap(root->right, hd+1, mp);
}

void printVerifcalOrder(treeNode *root) 
{
    map<int, vector<int>> mp;
    insertMap(root, 0, mp);
    map<int, vector<int>>::iterator itr;
    for ( itr=mp.begin(); itr!=mp.end(); itr++) {
        for(int i=0; i<itr->second.size(); i++) {
            cout << itr->second[i] << " ";
        }
        cout << endl;
    }
}


int main(){
    int arr[MAX_ELE] = {0,};
    for(int i=0; i<MAX_ELE; i++) {
	arr[i] = i+1;
    }

    treeNode *root = createTree(arr[0]);
    root->left = createTree(arr[1]);
    root->right = createTree(arr[2]);
    root->left->left = createTree(arr[3]);
    root->left->right = createTree(arr[4]);
    root->right->left = createTree(arr[5]);
    root->right->right = createTree(arr[6]);

    treeNode *nullTree ;
    treeNode *oneNodeTree = createTree(arr[0]);
    treeNode *unBalancedTree = createTree(arr[0]);
    unBalancedTree->left = createTree(arr[1]);
    unBalancedTree->right = createTree(arr[2]);
    unBalancedTree->left->left = createTree(arr[3]);


    treeNode *root1 = createTree(4);
    root1->left = createTree(2);
    root1->right = createTree(5);
    root1->left->left = createTree(1);
    root1->left->right = createTree(3);

    // First BST
    treeNode* root11 = createTree(15);
    root11->left = createTree(10);
    root11->right = createTree(20);
    root11->left->left = createTree(5);
    root11->left->right = createTree(12);
    root11->right->right = createTree(25);

    // Second BST
    treeNode* root12 = createTree(15);
    root12->left = createTree(12);
    root12->right = createTree(20);
    root12->left->left = createTree(5);
    root12->left->left->right = createTree(10);
    root12->right->right = createTree(25);

    cout<< "Preorder Traversal" << endl;
    PreOrderTraversal(root);
    cout<< endl;
    cout<< "Inorder Traversal" << endl;
    InOrderTraversal(root);
    cout<< endl;
    cout<< "Postorder Traversal" << endl;
    PostOrderTraversal(root);
    cout<< endl;
    cout<< "LevelOrder Traversal" << endl;
    levelOrderTraversal(root);
    cout<< endl;

    cout << "Longest dept of Tree"<< endl;
    cout << " " << longestDept(root)<< endl;

    cout << "Longest dept of NULL Tree"<< endl;
    cout << " " << longestDept(nullTree)<< endl;


    cout << "Longest dept of unBalaced Tree"<< endl;
    cout << " " << longestDept(unBalancedTree)<< endl;

    cout << "LowestCommonAncester " << endl;
    cout << " " << lowestCommonAncestor(root, 4, 5)->data << endl;

    cout << "LowestCommonAncester " << endl;
    cout << " " << lowestCommonAncestor(root, 1, 5)->data << endl;

    cout << "LowestCommonAncester " << endl;
    cout << " " << lowestCommonAncestor(root, 4, 3)->data << endl;

    cout << "distace vector between (2,3) Nodes" << endl;
    cout << " " << distacneVector(root, 2, 3) << endl; 

    cout << "distace vector between (1,5) Nodes" << endl;
    cout << " " << distacneVector(root, 1, 5) << endl; 

    cout << "distace vector between (4,3) Nodes" << endl;
    cout << " " << distacneVector(root, 4, 3) << endl; 

    cout << " Level Order in Seperate Lines " << endl;
    levelOrderPrintOnLine(root);

    cout << " diagonal Print " << endl;
    diagonalPrint(root);

    cout << " inorder iterative method " << endl;
    inorderIterative(root);
    cout << endl;

    cout << "is BST " << ((isBst(root1, NULL, NULL) == 1) ? "TRUE" : "FALSE") << endl; 
    cout << " inorder iterative method for tree root1" << endl;
    inorderIterative(root1);
    cout << endl;
    cout << "is BST " << ((isBst(root, NULL, NULL) == 1) ? "TRUE" : "FALSE") << endl; 
    cout << " inorder iterative method for tree root" << endl;
    inorderIterative(root);
    cout << endl;

    cout << "1 smallest element " << kthSmallestElement(root,1)->data << endl;
    cout << "3 smallest element " << kthSmallestElement(root,3)->data << endl;
    cout << "5 smallest element " << kthSmallestElement(root,5)->data << endl;

    cout << " identical tree " << endl;
        
    cout << " identical tree element " << isIdentical(root11, root12) << endl;

    cout << " print boundary " << endl;
    printBoundary(root);
    cout << endl;

    cout << "print vertical order" << endl;
    printVerifcalOrder(root);

    return 0;
}
