#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    string word;
    cin >> word;
    vector< int > frec(26, 0);
    for(auto c : word){
      frec[c - 'a']++;
    }
    for(int i = 0; i < 26; i++){
      for(int j = 0; j < frec[i]; j++){
        cout << (char)('a' + i);
      }
    }
    cout << "\n";
  }
  return 0;
}