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
    vector< int > nums(7);
    for(int i = 0; i < 7; i++){
      cin >> nums[i];
    }

    int a = nums[0];
    int b = nums[1];
    int c;
    if(nums[2] == a + b){
      c = nums[3];
    } else {
      c = nums[2];
    }

    cout << a << " " << b << " " << c << "\n";
  }
  return 0;
}