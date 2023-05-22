#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n > 2){
      cout << "NO\n";
    } else if(n == 2){
      if(s[0] == s[1]){
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}