#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  long long t = 1;
  while(t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for(long long i = 1; i <= n / 2; i++) {
      long long x = i;
      long long y = n - i;
      long long AB = 0;
      for(long long j = 1; j * j <= x; j++) {
        if(x % j == 0) {
          AB += 2;
        }
        if(j * j == x) AB--;
      }
      long long CD = 0;
      for(long long j = 1; j * j <= y; j++) {
        if(y % j == 0) {
          CD += 2;
        }
        if(j * j == y) CD--;
      }
      ans += AB * CD;
    }
    ans *= 2; 
    if(n % 2 == 0) {
      long long mid = 0;
      long long y = n / 2;
      for(long long j = 1; j * j <= y; j++) {
        if(y % j == 0) {
          mid += 2;
        }
        if(j * j == y) mid--;
      }
      ans -= mid * mid;
    }
    cout << ans << "\n";
  }
  return 0;
}
