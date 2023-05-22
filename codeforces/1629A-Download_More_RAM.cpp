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
    int n, k;
    cin >> n >> k;
    vector< pair< int, int > > memory(n);
    for (int i = 0; i < n; ++i){
      cin >> memory[i].first;
    }
    for (int i = 0; i < n; ++i){
      cin >> memory[i].second;
    }

    sort(memory.begin(), memory.end());

    for (int i = 0; i < n; ++i){
      if(memory[i].first > k){
        break;
      }
      k += memory[i].second;
    }

    cout << k << "\n";
  }
  return 0;
}