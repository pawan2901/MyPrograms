#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool myCompare(string x, string y)
{
    string xy = x.append(y);
    string yx = y.append(x);
    return ((xy.compare(yx) >  0) ? 1 : 0);
}

void printLargetNo( vector <string> vec)
{
    sort(vec.begin(), vec.end(), myCompare);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];
    cout << endl;
}

int main() {
    vector<string> vec;
    vec.push_back("54");
    vec.push_back("60");
    vec.push_back("548");
    vec.push_back("546");
    printLargetNo(vec);
    return 0;
}
