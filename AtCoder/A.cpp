#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    string s;
    cin >> s;
    for(auto c : s) 
      cout << (char) ((c - 'a') + 'A');
    cout << "\n";
  }
  return 0;
}
