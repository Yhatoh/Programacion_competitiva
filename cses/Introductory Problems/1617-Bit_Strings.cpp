#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}

int main(){
  ll n;
  cin >> n;

  cout << binpow(2, n) << "\n";
  return 0;
}