#include <bits/stdc++.h>
using namespace std;

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  ll t = 1;
  cin >> t;
  ll cases = 1;
  while(t--) {
    map< char, ll > code;
    char letter = 'A';
    for(ll i = 0; i < 26; i++) {
      ll c;
      cin >> c;
      code[letter++] = c;
    }
    set< ll > s;
    ll w;
    cin >> w;
    bool flag = true;
    for(ll i = 0; i < w; i++) {
      string word;
      cin >> word;
      ll encode = 1;
      for(char x : word) {
        encode *= 10;
        encode += code[x];
      }
      if(flag && s.find(encode) != s.end()) {
        flag = false;
      } else if(flag) {
        s.insert(encode);
      }
    }
    if(flag) cout << "Case #" << cases << ": NO\n";
    else cout << "Case #" << cases << ": YES\n";
    cases++;
  }
  return 0;
}
