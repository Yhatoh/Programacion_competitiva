#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<long long> nums(n);
    bool check = true;
    bool no_1 = true;
    bool no_0 = true;
    bool two_consec = false;
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
      if(nums[i] == 1 || nums[i] == 0){
        if(nums[i] == 1) no_1 = false;
        if(nums[i] == 0) no_0 = false;
        check = false;
      }
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i){
      if(i > 0 && nums[i] == nums[i - 1] + 1){
        two_consec = true;
        break;
      }
    }
    if(check) cout << "YES\n";
    else{
      if(no_1) cout << "YES\n";
      else{
        if(two_consec || !no_0) cout << "NO\n";
        else cout << "YES\n";
      }
    }
  }
  return 0;
}