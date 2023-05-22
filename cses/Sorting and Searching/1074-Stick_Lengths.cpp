#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  vector< long long > nums(n);
  for (long long i = 0; i < n; ++i){
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  long long target = nums[n / 2];
  long long cost = 0;
  for (long long i = 0; i < n; ++i){
    cost += abs(target - nums[i]);
  }

  cout << cost << "\n";
  return 0;
}