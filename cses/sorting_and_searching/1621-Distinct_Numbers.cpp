#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  set< int > nums;
  cin >> n;
  while(n--){
    cin >> x;
    nums.insert(x);
  }

  cout << nums.size() << "\n";
  return 0;
}