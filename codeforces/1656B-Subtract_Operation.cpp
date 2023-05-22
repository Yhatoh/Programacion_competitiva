#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    long long k;
    cin >> n >> k;
    vector< long long > nums(n);
    set<long long> checks;
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
    }

    bool check = false;
    for(int i = 0; i < n; i++){
      if(checks.find(nums[i] - k) != checks.end() || checks.find(nums[i] + k) != checks.end()){
        check = true;
        break;
      }
      checks.insert(nums[i]);
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}