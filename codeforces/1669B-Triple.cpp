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

    sort(nums.begin(), nums.end());

    int prev = -1;
    int times = 1;
    bool flag = false;
    for(int i = 0; i < n; i++){
      if(prev == nums[i]) times++;
      else {
        times = 1;
      }
      prev = nums[i];
      if(times == 3){ flag = true; break;}
    }

    cout << (flag ? prev : -1) << "\n";
  }
  return 0;
}
