#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector< long long > nums(n);
  for (int i = 0; i < n; ++i){
    cin >> nums[i];
  }

  long long ans = -1000000000;
  long long sumMax = -1000000000;

  for (int i = 0; i < n; ++i){
    sumMax = max(sumMax + nums[i], nums[i]);
    ans = max(sumMax, ans);
  }
  cout << ans << "\n";
  return 0;
}