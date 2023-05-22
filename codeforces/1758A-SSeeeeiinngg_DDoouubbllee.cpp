#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    string copy(s);
    reverse(copy.begin(), copy.end());
    cout << s + copy << "\n";
  }
  return 0;
}
