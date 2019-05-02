#include <bits/stdc++.h>
using namespace std;

int main()
{
     unordered_map<string, double> umap;
     umap["PI"] = 3.14;
     umap["root2"] = 1.414;
     umap["root3"] = 1.732;
     umap["log10"] = 2.302;
     umap["loge"] = 1.0;

     unordered_map<string, double>:: iterator itr;
     cout << "\nAll Elements : \n";
     for (itr = umap.begin(); itr != umap.end(); itr++)
     {
         cout << itr->first << "  " << itr->second << endl;
     }

        //independent_ref 
        int x=10, y=9;
        int &r = x;
        r++;
        r=y; 
        --r;
        cout << x << " " << y << endl;

     return 0;
}
