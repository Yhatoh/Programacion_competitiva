#include<bits/stdc++.h>
using namespace std;

typedef pair< int, int > pii;

int main(){
  int n;
  cin >> n;
  vector< pii > nums(n);
  for (int i = 0; i < n; ++i){
    cin >> nums[i].first;
    nums[i].second = i;
  }

  sort(nums.begin(), nums.end());

  int rounds = 0;
  int actual_pos = -1;
  for(int i = 0; i < n; i++){
    if(actual_pos == -1){
      rounds++;
    } else if(actual_pos > nums[i].second){
      rounds++;
    }
    actual_pos = nums[i].second;
  }
  
  cout << rounds++ << "\n";
  return 0;
}