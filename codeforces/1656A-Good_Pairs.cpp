#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< int > nums(n);
    for (int i = 0; i < n; ++i){
      cin >> nums[i];
    }

    int max_i = max_element(nums.begin(), nums.end()) - nums.begin();
    int min_i = min_element(nums.begin(), nums.end()) - nums.begin();
    if(max_i < min_i)
      cout << max_i + 1 << " " << min_i + 1 << "\n";
    else
      cout << min_i + 1 << " " << max_i + 1 << "\n";
  }
  return 0;
}