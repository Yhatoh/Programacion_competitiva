#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
  int t;
  cin >> t;
  vector< vector< long long > > dp(1000000 + 1, vector< long long >(2, 0));  
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i = 2; i < 1000000 + 1; i++){
    dp[i][0] = (dp[i - 1][1] + (dp[i - 1][0] * 2) % MOD) % MOD;
    dp[i][1] = ((dp[i - 1][1] * 4) % MOD + dp[i - 1][0]) % MOD;
  }
  while(t--){
    int n;
    cin >> n;
    
    cout << (dp[n][1] + dp[n][0]) % MOD << "\n";
  }
  return 0;
}
