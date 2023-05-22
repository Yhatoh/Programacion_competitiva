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
    bool same = true;
    for(long long i = 0; i < n; i++){
      cin >> d2[i];
      if(d1[i] != d2[i]) same = false;
    }

    if(same == true){
      cout << "Case #" << cas << ": " << (k % 2 == 0 ? "YES\n" : "NO\n");
      cas++;
      continue;   
    }

    int ap = 0;
    int bp = 0;
    bool ftw = true;
    bool flag = true;
    while(ap < n){
      if(d1[ap] == d2[bp]){
        ap++;
        if(bp < n - 1) bp++;
        else {
          ftw = false;
          bp = 0;
        }
      } else if(ftw && bp < n - 1){
        bp++;
      } else {
        flag = false;
        break;
      }
    }

    cout << "Case #" 
         << cas << ": " 
         << (((k > 0 && n == 2 && k % 2 == 1) ||
              (k > 0 && n > 2) || 
              (k > 0 && n > 2 && k % 2 == 1) || 
              (k > 0 && n > 2 && k % 2 == 0)) && flag ? "YES" : "NO") << "\n";
    cas++;
  }
  return 0;
}
