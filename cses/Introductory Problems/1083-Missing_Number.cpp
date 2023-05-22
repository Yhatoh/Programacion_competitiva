#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n; 
  cin >> n;
  vector< long long > nums(n - 1);
  for(int i = 0; i < n - 1; i++){
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());
  long long prev = 0;
  long long found = -1;
  int i;
  for(i = 0; i < n; i++){
    if(prev + 1 != nums[i]){
      found = prev + 1;
      break;
    }
    prev = nums[i];
  }

  if(found == -1 && i == n) cout << n << "\n";
  else cout << found << "\n";
  return 0;
}