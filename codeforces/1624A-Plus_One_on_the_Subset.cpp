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

    cout << *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) << "\n";
  }
  return 0;
}