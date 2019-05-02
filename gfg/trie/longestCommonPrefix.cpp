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

#define ALBHABET_SIZE 26
#define CHAR_TO_INDX(c) (c-'a')

struct Trie {
    Trie *children[ALBHABET_SIZE];
    int isLeaf;
};

Trie *getTrieNode()
{
    Trie *tmp = new Trie();
    if (tmp) {
        for (int i=0; i<ALBHABET_SIZE; i++) {
            tmp->children[i] = NULL;
        }
        tmp->isLeaf = false;
    }
    return tmp;
}



void insert(string arr, Trie *myTrie)
{
    int len = arr.length();
    Trie *pCrawl = myTrie;
    for (int i=0; i<len; i++) {
        int index = CHAR_TO_INDX(arr[i]); 
        if (pCrawl->children[index] == NULL) {
            pCrawl->children[index] = getTrieNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}

void constructTrie(string arr[], int n, Trie *myTrie)
{
    for(int i=0; i<n; i++) {
        insert(arr[i], myTrie);
    }
}

int countChildren(Trie *myTrie, int &index)
{
    cout << __func__<< endl;
    int cnt = 0;
    for(int i=0; i<ALBHABET_SIZE; i++) {
        if(myTrie->children[i]) {
            cnt++;
            index = i;
        }
        cout << cnt << endl;
    }
    return cnt;
}

string walkPrefix(Trie *myTrie)
{
    int index = 0;
    string prefix;
    Trie *pCrawl;
    pCrawl = myTrie;
    while (countChildren(pCrawl, index) == 1 && pCrawl->isLeaf == false) {
        pCrawl = pCrawl->children[index];
        prefix.push_back('a'+index);
    }
    return prefix;
}

string longestPrefix(string *arr, int n)
{
    string prefix;
    Trie *myTrie = getTrieNode();
    constructTrie(arr, n, myTrie);   
    return walkPrefix(myTrie);
}

int main() {
    string arr[] = {"geekforgeek", "geek", "geeks", "geezs"};
    int n = sizeof(arr)/sizeof(arr[0]);
    string ans = longestPrefix(arr, n);
    if(ans.length())
        cout << ans << endl;
    else
        cout << "No prefix found " << endl;
    return 0;
}
