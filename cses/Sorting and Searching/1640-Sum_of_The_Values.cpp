#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  map< int, int > sum;
  int i;
  for(i = 0; i < n; i++){
    int num;
    cin >> num;
    if(num <= x){
      auto itr = sum.find(num);
      if(itr != sum.end()){
        cout << itr->second << " " << i + 1 << "\n";
        break;
      }
      sum.insert(pair< int, int >(abs(x - num), i + 1));
    }
  }

  if(i == n) cout << "IMPOSSIBLE\n";
  return 0;
}