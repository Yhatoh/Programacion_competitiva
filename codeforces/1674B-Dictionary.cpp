#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int index = (s[0] - 'a') * 25;
    char c = 'a';
    while(true){
      if(c == s[0]){
        c++;
        continue;
      }
      index++;
      if(c == s[1]) {
        break;
      }

      c++;
    }
    cout << index << "\n";
  }
  return 0;
}
