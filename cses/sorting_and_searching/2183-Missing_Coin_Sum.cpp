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

  vector< long long > acum(n, 0);
  acum[0] = nums[0];
  for(long long i = 1; i < n; i++){
    acum[i] = acum[i - 1] + nums[i];
  }


  if(nums[0] != 1){
    cout << 1 << "\n"; 
  } else {
    long long num_print = acum[n - 1] + 1;
    for(long long i = 1; i < n; i++){
      //cout << acum[i - 1] << " " << nums[i] << "\n";
      if(acum[i - 1] + 1 < nums[i]){
        num_print = acum[i - 1] + 1;
        break;
      }
    }

    cout << num_print << "\n";
  }
  return 0;
}