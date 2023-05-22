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
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector< string > grid(n);
    for (int i = 0; i < n; ++i){
      cin >> grid[i];
    }

    r--;
    c--;

    bool imp, zero, one, two;
    imp = zero = one = two = false;
    imp = true;

    if(grid[r][c] == 'B'){
      zero = true;
      imp = false;
    }

    if(!zero){
      for(int i = 0; i < m; i++){
        if(grid[r][i] == 'B'){
          one = true;
          imp = false;
        }
      }

      for(int i = 0; i < n; i++){
        if(grid[i][c] == 'B'){
          one = true;
          imp = false;
        }
      }

      if(!one){
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
              two = true;
              imp = false;
              break;
            }
          }
          if(two){
            break;
          }
        }
      }
    }
    
    if(zero) cout << "0\n";
    else if(one) cout << "1\n";
    else if(two) cout << "2\n";
    else if(imp) cout << "-1\n";

  }
  return 0;
}