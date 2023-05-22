#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  long long t = 1;
  while(t--) {
    long long n;
    cin >> n;
    vector< long long > nums(100001);
    for(long long i = 1; i <= n; i++) {
      long long a;
      cin >> a;
      nums[a]++;
    }

    vector< long long > dp(100001, 0);
    dp[1] = nums[1];
    for(long long i = 2; i <= 100000; i++) {
      dp[i] = max(dp[i - 2] + nums[i] * i, dp[i - 1]);
    }
    cout << dp[100000] << "\n";
  }
  return 0;
}
