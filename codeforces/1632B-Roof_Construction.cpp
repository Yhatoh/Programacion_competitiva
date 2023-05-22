#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int max_cost = (int) pow(2, (int) log2(n - 1));
    //cout << log2(n) << "\n";
    //cout << max_cost << "\n";
    int aux = max_cost - 1;
    while(aux >= 0){
      cout << aux << " ";
      aux--;
    }
    while(max_cost < n){
      cout << max_cost << " ";
      max_cost++;
    }
    cout << "\n";

  }
  return 0;
}