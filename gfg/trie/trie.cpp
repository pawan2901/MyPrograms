#include<iostream>

using namespace std;

#define ALPHABET_MAX 26

struct trieNode {
    trieNode *children[ALPHABET_MAX];
    bool isEndOfWord;
};

trieNode *getNode(void)
{
    trieNode *tmpNode = new trieNode;
    tmpNode->isEndOfWord = NULL;
    for(int i = 0; i < ALPHABET_MAX; i++) {
        tmpNode->children[i] = NULL;
    }
    return tmpNode;
}

void insertKey(trieNode *root, string key)
{
    trieNode *pCrawl = root;
    for( int i = 0; i < key.size(); i++) {
        int idx = key[i] - 'a';
        if (!pCrawl->children[idx]) {
            pCrawl->children[idx] = getNode();
        }
        pCrawl = pCrawl->children[idx];
    }
    pCrawl->isEndOfWord = true;
}

bool search(trieNode *root, string key)
{
    trieNode *pCrawl = root;
    for( int i = 0; i < key.size(); i++) {
        int idx = key[i] - 'a';
        if (!pCrawl->children[idx]) {
            return false;
        }
        pCrawl = pCrawl->children[idx];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
    string key[] = {"the", "their", "hot","hottest"};
    int n = sizeof(key)/sizeof(key[0]);
    cout << sizeof(key) << " " << sizeof(key[0]) << endl;
    trieNode *root = getNode();
    for(int i = 0; i < n; i++) {
        insertKey(root, key[i]);
    }
    search(root, "the") ? cout << "true" : cout << "false";
    cout << endl;
    search(root, "there") ? cout << "true" : cout << "false";
    cout << endl;
    return 0;
}
