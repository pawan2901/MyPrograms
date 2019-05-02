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

class myStruct{
    map<int, int> myMap;
    vector<int> myVec;
   
    public:
    
    void add(int x) {
        if (myMap.find(x) != myMap.end())
            return;
        int idx = myVec.size();
        myVec.push_back(x);
        myMap.insert(std::pair<int, int>(x, idx));
    }

    void del(int x) {
        if (myMap.find(x) == myMap.end())
            return;
        int idx = myMap.at(x);
        myMap.erase(x);
        int last = myVec.size() -1;
        swap(myVec[last], myVec[idx]);
        myVec.pop_back();
        myMap.at(myVec[idx]) = idx;
    }

    int search(int x) {
        if (myMap.find(x) == myMap.end())
            return -1;
        return myMap.at(x);
    }
    
    int findRand() {
        srand(time(NULL));
        cout << "rand " << rand() << endl;
        int idx = rand() % myVec.size();
        return myVec.at(idx);
    }
};

int main() {
    myStruct mySt;
    mySt.add(1);
    cout << "ele 1 at loc " << mySt.search(1) << endl;
    mySt.add(2);
    cout << "ele 2 at loc " << mySt.search(2) << endl;
    mySt.add(3);
    cout << "ele 3 at loc " << mySt.search(3) << endl;
    mySt.add(10);
    cout << "ele 10 at loc " << mySt.search(10) << endl;
    mySt.del(1);
    mySt.add(10);
    cout << "ele 10 at loc " << mySt.search(10) << endl;
    cout << "ele 11 at loc " << mySt.search(11) << endl;
    
    cout << mySt.findRand() << endl;
    sleep(1);
    cout << mySt.findRand() << endl;
    sleep(2);
    cout << mySt.findRand() << endl;

    return 0;
}
