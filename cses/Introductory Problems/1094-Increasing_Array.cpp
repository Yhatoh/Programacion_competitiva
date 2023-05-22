#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(vector< long long int > v){
  long long int i;
  for(i = 0; i < ((long long int) v.size()) - 1; i++){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

int main(){
  ll n;
  cin >> n;
  vector< ll > nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }

  ll moves = 0;
  for(int i = 1; i < n; i++){
    int res = nums[i - 1] - nums[i];
    if(res > 0){
      moves += res;
      nums[i] += res;
    }
  }

  cout << moves << "\n";
  return 0;
}