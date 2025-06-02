#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t;
  cin >> t;
  while(t--){
    ll x, y;

    cin >> x >> y;
    ll res = 0;

    if(x > y){
      ll x_2 = x * x;
      if(x % 2){
        res = x_2 - (x - 1) - (x - y);
      } else {
        res = x_2 - (y - 1); 
      }
    } else { 
      ll y_2 = y * y;
      if(y % 2){
        res = y_2 - (x - 1); 
      } else {
        res = y_2 - (y - 1) - (y - x);
      }
    }

    cout << res << "\n";
  }

  return 0;
}