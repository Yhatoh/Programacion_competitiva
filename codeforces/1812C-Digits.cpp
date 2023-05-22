#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  string s = "3141592653589793238462643383279502884197";
  int pos = 0;
  while(t--) {
    int acum = 1;
    for(int i = 0; i < s[pos] - '0'; i++) {
      int num;
      cin >> num;
      acum *= num;
    }
    pos++;
    cout << acum << "\n";
  }
  return 0;
}
