#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int flag = false;
    vector<int> input = {1,2,1,3,5,4};

    for (int i=0; i<input.size(); i++) {
        input[i] = input[i] * input[i];
    }
    sort(input.begin(), input.end());

    for (int i=input.size()-1; i >= 2; i--) {
        int l = 0;
        int r = i-1;
        while (l < r) {
            if(input[l] + input[r] == input[i])
                flag = true;
            input[l]+input[r]<input[i] ? l++ : r--;
        }
    }

    if (flag == true)
        cout << true << endl;
    else
        cout << false << endl;

    vector<int>::iterator itr;
    for(itr = input.begin(); itr != input.end(); itr++)
        cout << *itr << endl;

    return 0;
}
