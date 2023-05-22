#include <bits/stdc++.h>
using namespace std;

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]\n";
  return os;
}

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
vector< ll > pows(10000 + 2, 0);
set< ll > a;

struct RollingHashing {
  ll p, m, ns;
  vector< ll > hash;

  RollingHashing(string s, ll p_=31, ll m_=1e9 + 7) {
    // if WA then other p and other m
    // if still WA then double hashing
    // if still WA maybe is not the answer RH
    p = p_; m = m_;	
    ns = s.size();
  
    hash.resize(ns + 1);
    hash[0] = 0;
    for(int i = 1; i <= ns; i++) {
      ll char_to_num = s[i - 1] - 'a' + 1;  
      ll prev_hash = hash[i - 1];
      hash[i] = ((char_to_num * pows[i - 1]) % m + prev_hash) % m; 
    }
  }
  
  ll compute_hashing(ll i, ll j) {
    return (hash[j] - hash[i - 1] + m) % m * pows[ns - i + 1] % m;
  }
};

int main() {
  int t;
  cin >> t;
  int cases = 1;
  pows[0] = 1;
  for(int i = 1; i < 10000 + 2; i++) 
    pows[i] = (pows[i - 1] * 31) % ((ll) 1e9 + 7);

  while(t--) {
    string s;
    cin >> s;
    RollingHashing h(s);
    //RollingHashing h2(s, 37, 1e9 + 9);
    int p, q;
    cin >> p >> q;
    for(int i = 1; (uint64_t) i <= s.size(); i++) {
      for(int j = p; (uint64_t) i + j - 1 <= s.size() && j <= q; j++) {
        //cout << i <<  " " << j << "\n";
        //cout << h.compute_hashing(i, i + j - 1) << " " << h2.compute_hashing(i, i + j - 1) << "\n";
        a.insert(h.compute_hashing(i, i + j - 1));
      }
    }
    cout << "Case " << cases++ << ": " << a.size() << "\n";
    a.clear();
  }
  return 0;
}
