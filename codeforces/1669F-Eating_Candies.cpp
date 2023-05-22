#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< int > nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }

    int ans = 0;
    int l = 0;
    int r = n - 1;

    int sum_l = nums[l];
    int sum_r = nums[r];

    while(l < r){
      if(sum_l == sum_r && ans < l + 1 + n - r)
        ans = l + 1 + n - r;

      if(sum_l <= sum_r){
        l++;
        sum_l += nums[l];
      } else if(sum_r < sum_l){
        r--;
        sum_r += nums[r];
      }
    }

    cout << ans << "\n";

  }
}
