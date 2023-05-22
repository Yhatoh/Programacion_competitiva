#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(5); 

  int n;
  cin >> n;

  vector< int > quant(n - 1);
  for(int i = 0; i < n - 1; i++){
    cin >> quant[i];
  }

  double res, needed, side;

  side = pow(2.0, -3.0/4.0);
  res = 0;
  needed = 1;

  for(int i = 0; i < n - 1; i++){
    double toSum = needed * side;
    needed = needed * 2 - quant[i];
    side /= sqrt(2);

    res += toSum;

    if(needed <= 0) break;
  }

  if(needed <= 0){
    cout << res << "\n";
  } else {
    cout << "impossible\n";
  }
  return 0;
}