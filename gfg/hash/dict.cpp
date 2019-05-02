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

#define pr1(x) printf("˝%d\n",x)
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

struct dict{
    int pos;
    int occ;
};

int firstChar(string str)
{
    dict my_dict[26];
    int pos = 1;
    for (int i=0; i<26;i++) {
        my_dict[i].pos = 0;
        my_dict[i].occ = 0;
        cout << my_dict[i].pos << " "<< my_dict[i].occ << endl;
    }
    for(int i=0; i<str.size(); i++) {
        cout << str[i] << endl;
        if (!(my_dict[str[i] - 'a'].pos)) 
            my_dict[str[i] - 'a'].pos = pos;
        pos++;
        my_dict[str[i] - 'a'].occ += 1;
    }
    for (int i=0; i<26;i++) {
        cout << my_dict[i].pos << " "<< my_dict[i].occ << endl;
    }
    cout << endl;
    int min = 27;
    int res = 0;
    for (int i=0; i<26;i++) {
        if (my_dict[i].occ ==1 && min > my_dict[i].pos) {
            min = my_dict[i].pos;
            res = i;
            cout << min << endl;
        }
        cout << my_dict[i].pos << " "<< my_dict[i].occ << endl;
    }
    return res;
}

int main() {
    string str = "hello";
    cout << (char)('a' + firstChar(str)) << endl;
    str = "zxvczbtxyzvy";
    cout << (char)('a' + firstChar(str)) << endl;
    return 0;
}
