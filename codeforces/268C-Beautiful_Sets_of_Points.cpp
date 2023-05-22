#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    set< pair< int, int > > sii;
    if(n > m) swap(n, m);
    for(int i = 0; i <= n; i++) {
      sii.insert({n - i, i});
    }
    cout << sii.size() << "\n";
    for(auto p : sii) {
      cout << p.first << " " << p.second << "\n";
    }
  }
  return 0;
}
