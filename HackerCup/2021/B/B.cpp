#include<bits/stdc++.h>
using namespace std;

typedef pair< int,  vector< vector< int > > > pivvi;

int minimum = 100000;
map< int,  set< vector< vector< int > > >  > mapita;

void printVec(vector< vector< int > > &k){
  for(int i = 0; i < k.size(); i++){
    for(int j = 0; j < k.size(); j++){
      cout << k[i][j] << " ";
    }
    cout <<"\n";
  }
  cout <<"\n";
}

int counting(vector< string >& grid, char c){
  minimum = 100000;
  
  int impossible = 1;
  for(int i = 0; i < (int) grid.size(); i++){

    int possibleRow = 1;
    int possibleCol = 1;
    int row = grid.size();
    int col = grid.size();

    vector< int > gamer1(grid.size(), 0);
    vector< int > gamer2(grid.size(), 0);
    vector< vector< int > > pos1(grid.size(), gamer1);
    vector< vector< int > > pos2(grid.size(), gamer2);
    for(int j = 0; j < (int) grid.size(); j++){
      if(grid[i][j] == c){
        row--;
      } else if(grid[i][j] != c && grid[i][j] != '.'){
        possibleRow = 0;
      } else {
        pos1[i][j] = 1;
      }

      if(grid[j][i] == c){
        col--;
      } else if(grid[j][i] != c && grid[j][i] != '.'){
        possibleCol = 0;
      } else {
        pos2[j][i] = 1;
      }
    }
    //cout << i << "\n";
    if(possibleCol) {
      //printVec(pos2);
      mapita[col].insert(pos2);
      impossible = 0;
      if(minimum > col){
        minimum = col;
      }
    }
    if(possibleRow) {
      //printVec(pos1);
      mapita[row].insert(pos1);
      impossible = 0;
      if(minimum > row){
        minimum = row;
      }
    }
  }

  return (impossible == 0 ? minimum : -1);
}

int main(){
  int t, i;
  i = 1;
  cin >> t;
  while(t >= i){
    int n;
    cin >> n;
    vector< string > grid(n);
    for(int i = 0; i < n; i++){
      cin >> grid[i];
    }

    mapita.clear();
    int X = counting(grid, 'X');

    cout << "Case #" << i << ": ";
    if(X == -1){
      cout << "Impossible\n";
    } else {
      cout << minimum << " " << mapita[minimum].size() << "\n";
    }
    i++;
  }
}