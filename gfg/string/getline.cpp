#include<iostream> 
#include<string> // for string class 
#include<vector>
using namespace std; 
int main() 
{ 
        // Declaring string 
        vector<string> str; 
        string tmp_str;

        // Taking string input using getline() 
        // "geeksforgeek" in givin output 
        int i  = 0;
        while(1) {
            getline(cin,tmp_str); 
            cout << tmp_str << endl;
            if(tmp_str.size() == 0)
                break;
            // Displaying string 
            cout << "The initial string is : "; 
            cout << tmp_str << endl;
            str.push_back(tmp_str);
            i++;
        }
        // Displaying string 
        cout << "The initial string is : "; 
        cout << endl;
        for(int i=0; i<str.size(); i++)
            cout << str[i] << endl; 

        return 0; 

} 

