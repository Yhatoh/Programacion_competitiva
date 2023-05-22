#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< int > nums(n);
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
    }
    if(n == 1) cout << (nums[0] > 1 ? "NO" : "YES") << "\n";
    else{
      sort(nums.begin(), nums.end());
      bool flag = true;
      if(nums[n - 1] > nums[n - 2] + 1) flag = false;

      cout << (flag ? "YES" : "NO") << "\n";
    }
  }

  return 0;
}