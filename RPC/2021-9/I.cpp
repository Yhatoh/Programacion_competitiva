#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
  ll n, ans, l;
  cin >> n;

  ans = l = 0;
  for(ll k = 45; k >= 0; k--){
    if(n & (1L << k)){
      ans += powl(2L, l) * powl(3L, k);
      l++;
    }
  }
  cout << ans << "\n";
  return 0;
}