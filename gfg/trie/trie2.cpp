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

#define ALPHABET_SIZE 26

struct trie{
    int isEndOfWord;
    trie *child[ALPHABET_SIZE];
};

trie *getNode(void)
{
    trie * newNode = new trie;
    newNode->isEndOfWord = 0;
    for(int i=0; i<ALPHABET_SIZE; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

void insert(trie *root, string data)
{
    trie *crawl = root;
    for(int i=0; i<data.size(); i++) {
        cout << data[i] << endl;
        int idx = data[i] - 'a';
        cout << idx << endl;
        if (!(crawl->child[idx])) {
            crawl->child[idx] = getNode();
        }
        cout << crawl->child[idx] << endl;
        crawl = crawl->child[idx];
    }
    if (!crawl)
    cout << crawl << endl;
    crawl->isEndOfWord = 1;
    cout << " insert successfully" << endl;
}

int search(trie *root, string data)
{
    int ret = 0;
    trie *crawl = root;
    for (int i=0; i<data.size(); i++) {
        if (crawl->child[data[i]-'a'] != NULL) {
            crawl = crawl->child[data[i] - 'a'];
        } else {
            return ret;
        }
    }
    if (crawl->isEndOfWord == 1)
        ret = 1;
    return ret;
}

int main() {
    trie *trieRoot = getNode();
    string data[] = {"hot", "hottest", "cat", "catters"};
    int ele = sizeof(data)/sizeof(data[0]);
    for(int i=0; i<ele; i++) {
        insert(trieRoot, data[i]);
    }
    cout << search(trieRoot, data[1]) << endl;
    cout << search(trieRoot, "hote") << endl;
    return 0;
}

