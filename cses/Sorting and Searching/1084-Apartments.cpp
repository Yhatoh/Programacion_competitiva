#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector< int > applicants(n);
  vector< int > apartments(m);
  for (int i = 0; i < n; ++i){
    cin >> applicants[i];
  }
  
  for (int i = 0; i < m; ++i){
    cin >> apartments[i];
  }

  sort(applicants.begin(), applicants.end());
  sort(apartments.begin(), apartments.end());


  int i, j;
  i = j = 0;

  int ans = 0;
  while(i < n && j < m){
    //cout << applicants[i] << " " << apartments[j] << "\n";
    if(abs(applicants[i] - apartments[j]) <= k){
      i++; j++; ans++;
    } else if(applicants[i] > apartments[j] + k){
      j++;
    } else {
      i++;
    }
  }
  cout << ans << "\n";
  return 0;
}