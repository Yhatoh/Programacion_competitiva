#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair< ll, ll > pll;


int main(){
  ll t;
  ll cas = 1;
  cin >> t;
  while(t--){
    ll n, q;
    cin >> n;
    vector< pll > trees(n);
    for(long long i = 0; i < n; i++){
      cin >> trees[i].first >> trees[i].second;
    }
    cin >> q;
    vector< pll > shit(q);
    for(long long i = 0; i < q; i++){
      cin >> shit[i].first >> shit[i].second;
    }

    ll suma = 0;
    for(ll i = 0; i < n; i++){
      ll xt = trees[i].first;
      ll yt = trees[i].second;
      for(ll j = 0; j < q; j++){
        ll xs = shit[j].first;
        ll ys = shit[j].second;
        ll a = ((xt - xs) * (xt - xs)) % 1000000007;
        ll b = ((yt - ys) * (yt - ys)) % 1000000007;
        ll ab = (a + b) % 1000000007;
        suma = (suma + ab) % 1000000007;
      }
    }

 
    cout << "Case #" << cas << ": " << suma << "\n";
    cas++;
  }
  return 0;
}
