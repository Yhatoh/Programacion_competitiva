#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector< string > grid(n);
    for(int i = 0; i < n; i++){
      cin >> grid[i];
    }
    bool flag = true;
    while(flag){
      bool change = false;
      for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < m; j++){
          if(grid[i][j] == '*'){
            if(grid[i + 1][j] == '.'){
              change = true;
              grid[i + 1][j] = grid[i][j];
              grid[i][j] = '.';
            }
          }
        }
      }

      if(!change) flag = false;
    }

    for(int i = 0; i < n; i++){
      cout << grid[i] << "\n";
    }
  }
  return 0;
}
