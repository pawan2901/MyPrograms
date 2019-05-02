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

int findNearest2Power(int n)
{
    cout<< __func__<< endl;
    int cnt = 1;
    while(n != 1) {
        n = n/2;
        cnt++;
    }
    return pow(2,cnt);
}

int getSaIsMul(int sa, int n)
{
    cout<< __func__<< endl;
    if(sa%n == 0)
        return sa;
    else {
        return (sa-(sa%n));
    }
}

int findLimitUtil(int &l_sa, int &l_n)
{
    cout<< __func__<< endl;
    l_n = findNearest2Power(l_n);
    cout << l_n << endl;
    l_sa = getSaIsMul(l_sa, l_n);
    cout << l_sa<< endl;
    return 1;
}

int findLimit(int sa, int n){
    cout<< __func__<< endl;
    int l_sa = sa;
    int l_n = n;
    findLimitUtil(l_sa, l_n);
    if(l_sa > sa || l_sa+n <sa+n)
        return findLimit(l_sa, l_n);
    else 
        return l_n*2+1;
}

int main() {
    cout<< __func__<< endl;
    int sa = 13;
    int n = 5;
    cout << findLimit(sa,n);
    return 0;
}

