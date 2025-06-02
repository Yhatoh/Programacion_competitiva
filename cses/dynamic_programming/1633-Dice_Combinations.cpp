#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector< ll > dp(n + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    ll throws = 0;
    for(int j = 1; j <= 6 && i - j >= 0; j++){
      throws += dp[i - j];
    }
    dp[i] = throws % 1000000007;
  }

  cout << dp[n] << "\n";
  return 0;
}