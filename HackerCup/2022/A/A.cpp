#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int cas = 1;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector< int > clocks(n);
    for(int i = 0; i < n; i++){
      cin >> clocks[i];
    }

    bool possible = false;
    if(n <= k * 2){
      set< int > c1, c2; 
      int i;
      for(i = 0; i < n; i++){
        if(c1.find(clocks[i]) != c1.end()){
          if(c2.find(clocks[i]) != c2.end()){
            break;
          } else {
            c2.insert(clocks[i]);
          }
        } else {
          c1.insert(clocks[i]);
        }
      }
      if(i == n) possible = true;
    }
    cout << "Case #" << cas << ": " << (possible ? "YES" : "NO") << "\n";
    cas++;
  }
  return 0;
}
