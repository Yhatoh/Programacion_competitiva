#include <bits/stdc++.h>
using namespace std;

int main(){
  long long t;
  long long cas = 1;
  cin >> t;
  while(t--){
    long long n, k;
    cin >> n >> k;
    vector< long long > d1(n);
    vector< long long > d2(n);
    for(long long i = 0; i < n; i++){
      cin >> d1[i];
    }
    for(long long i = 0; i < n; i++){
      cin >> d2[i];
    }

    long long start = 0;
    for(long long i = 0; i < n; i++){
      if(d2[0] == d1[i]){
        start = i;
        break;
      }
    }

    long long steps = 0;
    bool flag = true;
    while(steps < n){
      if(d1[(start + steps) % n] != d2[steps]){
        flag = false;
        break;
      }
      steps++;
    }
/*    cout << n << " " << k << "\n";
    for(long long i = 0; i < n; i++){
      cout << d1[i] << " ";
    }cout << "\n";
    for(long long i = 0; i < n; i++){
      cout << d2[i] << " ";
    }cout << "\n";*/
    cout << "Case #" 
         << cas << ": " 
         << (((k % 2 == 0 && start == 0) || 
              (k > 0 && n == 2 && start != 0 && k % 2 == 1) ||
              (k > 0 && n > 2 && k <= start && start != 0) || 
              (k > 0 && n > 2 && k % 2 == 1 && k > start && start != 0) || 
              (k > 0 && n > 2 && k % 2 == 0 && k > start && start != 0)) && flag ? "YES" : "NO") << "\n";
    cas++;
  }
  return 0;
}
