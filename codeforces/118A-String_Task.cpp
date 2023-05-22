#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string ans = "";
  cin >> s;
  string vowels = "aoyeuiAOYEUI";
  for(char c : s) {
    if(vowels.find(c) == string::npos) {
      ans += ".";
      ans += tolower(c);
    }
  }
  cout << ans << "\n";
  return 0;
}
