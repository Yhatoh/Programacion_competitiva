#include<bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  cin >> t;
  while(t--){
    long long n, m;
    cin >> n >> m;

    long long res = 0;

    long long suma = ((m + 1) * m / 2) % (1000000000 + 7);
    long long mul = ((n + 1) * n / 2) % (1000000000 + 7);
    res = (res + suma * mul) % (1000000000 + 7);
    cout << res << "\n";
  }
}
