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

    bool flag = true;
    int prev = nums[0] % 2;
    for(int i = 0; i < n; i += 2){
      if(nums[i] % 2 != prev){
        flag = false;
        break;
      }
    }

    prev = nums[1] % 2;
    for(int i = 1; i < n; i += 2){
      if(nums[i] % 2 != prev){
        flag = false;
        break;
      }
    }

    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
