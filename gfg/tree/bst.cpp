#include<iostream>

using namespace std;

struct treeNode{
    int data;
    treeNode *left;
    treeNode *right;
};


treeNode *createNode(int data) {
    treeNode *tmp = new treeNode;
    tmp->data  = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void inOrder(treeNode *root) {
    if(!root) return;
    inOrder(root->left);
    cout << root->data << " " ;
    inOrder(root->right);

}

int isBst(treeNode *root) {
    static treeNode *prev;
    if(root) {
	if(!isBst(root->left))
	    return false;
	if(prev != NULL && prev->data >= root->data)
	    return false;
	prev = root;
	return isBst(root->right);
    }
    return 1;
}

int kthElementBst(treeNode *root, int k, int &cnt) {
    if(!root) return 0;
    kthElementBst(root->left, k, cnt);
    cout<< cnt << " " << k << " " << root->data << endl;
    cnt++;
    if(cnt == k)
	return root->data;
    kthElementBst(root->right, k, cnt);
}

treeNode *removeLeafNode(treeNode *root)
{
    if(root == NULL)
	return NULL;
    if (root->left == NULL && root->right == NULL) {
	delete(root);
	return NULL;
    } else {
	root->left = removeLeafNode(root->left);
	root->right = removeLeafNode(root->right);
    }
    return root;
}

void bstDllUtil(treeNode *root, treeNode **head)
{
    if (root == NULL)
        return;
    static treeNode *prev = NULL;

    bstDllUtil(root->left, head); 

    if( *head == NULL) {
        *head = root;
    } 

    root->left = prev;

    if (prev)
        prev->right = root;

    prev = root;

    bstDllUtil(root->right, head);
}

void printDll(treeNode *head)
{
    if(head == NULL)
        return;
    while(head != NULL) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    treeNode *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(40);
    root->left->left = createNode(1);
    root->left->right = createNode(7);
    root->right->right = createNode(90);
    cout<< " inorder traversal "<< endl;
    inOrder(root);
    cout << endl;
    cout << "Is tree is BST = " << isBst(root) << endl;

    treeNode *root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(40);
    root2->left->left = createNode(11);
    root2->left->right = createNode(7);
    root2->right->right = createNode(90);
    cout<< " inorder traversal "<< endl;
    inOrder(root2);
    cout << endl;
    cout << "Is tree is BST = " << isBst(root2) << endl;

    int cnt = 0;
    cout << " kth element in BST " << endl;
    cout << kthElementBst(root,3, cnt);

    cout<< " inorder traversal "<< endl;
    inOrder(root);
    cout << endl;

    removeLeafNode(root);

    cout<< " inorder traversal "<< endl;
    inOrder(root);
    cout << endl;

    cout << " BST to Doubly link list " << endl;
   //Not implemented need to check again 
    treeNode *head = NULL;
    bstDllUtil(root, &head);
    cout << endl;
    printDll(head);


    return 0;
}
