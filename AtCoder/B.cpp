#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vector< int > players(n + 1, 2);
    while(q--) {
      int t, x;
      cin >> t >> x;
      if(t == 1) {
        if(players[x] > 0) players[x]--;
      } else if(t == 2) {
        players[x] = 0;
      } else {
        cout << (players[x] == 0 ? "Yes" : "No") << "\n";
      }
    }
  }
  return 0;
}
