#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(vector< long long int > &v){
  long long int i;
  for(i = 0; i < ((long long int) v.size()) - 1; i++){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

void print(vector< vector< ll > > &v){
  long long int i;
  for(i = 0; i < ((long long int) v.size()); i++){
    long long int j; 
    for(j = 0; j < ((long long int) v[i].size()) - 1; j++){
      cout << v[i][j] << " ";
    }
    cout << v[i][j] << "\n";
  }
}

ll count_path(vector< string > &grid){

  int n = (int) grid.size(); 

  vector< vector< ll > > res(n, vector< ll >(n, 0));

  res[n - 1][n - 1] = 1;
  for(int i = n - 1; i >= 0; i--){
    for(int j = n - 1; j >= 0; j--){
      if(grid[i][j] != '*'){
        if(i < n - 1){
          res[i][j] = (res[i][j] + res[i + 1][j]) % 1000000007;
        }

        if(j < n - 1){
          res[i][j] = (res[i][j] + res[i][j + 1]) % 1000000007;
        }
      }
    }
  }

  //print(res);
  return res[0][0];
}

int main(){
  int n;
  cin >> n;

  vector< string > grid(n);

  for(int i = 0; i < n; i++){
    cin >> grid[i];
  }
  if(grid[n - 1][n - 1] == '.')
    cout << count_path(grid)<< "\n";
  else
    cout << 0 << "\n";
  return 0;
}