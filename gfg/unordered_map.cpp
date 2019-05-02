#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<string, double> umap;
    umap["PI"] = 3.14;
    umap["squ2"] = 2;
    umap["squ3"] = 3;

    unordered_map<string, double>::iterator itr;
    for(itr = umap.begin() ; itr != umap.end(); itr++) {
        cout << itr->first << "  " << itr->second << endl;
    }


    return 0;
}
