#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  vector< int > children(n);
  for (int i = 0; i < n; ++i){
    cin >> children[i];
  }

  sort(children.begin(), children.end());

  int i, j;

  i = 0;
  j = n - 1;  
  
  int ans = 0;
  while(i < j){
    if(children[i] + children[j] <= x){
      ans++;
      i++;
      j--;
    } else {
      ans++;
      j--;
    }
  }

  if(i == j) ans++;
  cout << ans << "\n";
  return 0;
}