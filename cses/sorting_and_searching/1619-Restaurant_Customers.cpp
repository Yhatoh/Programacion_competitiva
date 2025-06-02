#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector< int > arrive(n);
  vector< int > leave(n);

  for (int i = 0; i < n; ++i){
    cin >> arrive[i] >> leave[i];
  }

  sort(arrive.begin(), arrive.end());
  sort(leave.begin(), leave.end());

  int i, j;

  i = j = 0;
  int ans = 0;
  int customers = 0;
  while(i < n && j < n){
    if(arrive[i] < leave[j]){
      customers++;
      i++;
    } else {
      j++;
      customers--;
    }

    ans = max(customers, ans);
  }

  cout << ans << "\n";
  return 0;
}