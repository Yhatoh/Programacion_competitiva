#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector< pair< int, int > > movies(n);

  for (int i = 0; i < n; ++i){
    cin >> movies[i].second >> movies[i].first;
  }

  sort(movies.begin(), movies.end());

  int ans = 1;
  int prevS = movies[0].second;
  int prevF = movies[0].first;
  for (int i = 1; i < n; ++i){
    if(movies[i].second >= prevF){
      ans++;
      prevS = movies[i].second;
      prevF = movies[i].first; 
    }
  }

  cout << ans << "\n";
  return 0;
}