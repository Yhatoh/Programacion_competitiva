#include <bits/stdc++.h>
using namespace std;
 
size_t findstem(vector<string>& arr){
    size_t n = arr.size();
 
    string s = arr[0];
    //cout << s << "\n";
    size_t len = s.length();
 
    string res = "";
 
    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j <= len; j++) {
            string stem = s.substr(i, j);
            size_t k = 1;
            for (k = 1; k < n; k++) {
                //if(stem.length() < 3) 
                    //cout << k << " " << stem << " " << arr[k].find(stem) << " " << string::npos << "\n";
                    
                if (arr[k].find(stem) == string::npos){

                    break;
                }
            }
            if (k == n && res.length() < stem.length())
                res = stem;
        }
    }
    return res.length();
}
 
int main(){
    vector<string> arr;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string h;
        cin >> h;
        arr.push_back(h);
    }
    cout << findstem(arr) << "\n";
}