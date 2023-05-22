#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    string s = "";
    bool flag = true;
    while(m > n) {
      if(flag) {
        s += "11";
        m -= 2;
        flag = false;
      } else {
        s += "0";
        n--;
        flag = true;
      }
    }
    if(n - m > 1 || m < 0 || n < 0) {
      cout << -1 << "\n";
      break;
    }
    if(n - m == 1) flag = false;
    
    for(int i = 0; i < m + n; i++) {
      if(flag) {
        s += "1";
        flag = false;
      } else {
        s += "0";
        flag = true;
      }
    }
    cout << s << "\n";
  }
  return 0;
}
