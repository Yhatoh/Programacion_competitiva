#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    if(n != 15 && n != 21 && n != 20) {
      cout << "YES\n";
    } else {
      cout <<  "NO\n";
    }
  }
  return 0;
}
