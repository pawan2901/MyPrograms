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

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort012(int *arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high) {
        switch(arr[mid]) {
            case 0:
                swap(&arr[mid++], &arr[low++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid], &arr[high--]);
                break;
        }
    }
}

char *compress(char *str)
{
    int len  = strlen(str);
    char *res = new char[len*2+1];
    int cnt = 0;
    int k = 0;
    int j = 0;

    cout << str << endl;
    for (int i=0; i<len;) {
        cnt = 0;
        while (str[i] == str[k]) {
            k++;
            cnt++;
        }
        res[j++] = str[i];
        sprintf((res +j), "%d", cnt);
        j++;
        i = k;
    }
    res[j] = '\0';
    return res;
}

int main() {
    int arr[]= {1,0,2,1,0,0,0,2,1,0,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);

    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    char *str = "aabbcddee";
    char *res = compress(str);
    
    for(int i=0; i<strlen(res); i++) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}
