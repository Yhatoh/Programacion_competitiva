#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long n, k;
    cin >> n >> k;
    long long suma = 0;
    if(k == n - 1 && n == 4) cout << -1 << "\n";
    else if(k == n - 1){
      for(long long i = 0; i < n / 2; i++){
        if(i == k - (n / 2)){
          suma += 0 & (n / 2);
          cout << "0 " << n / 2 << "\n";
          suma += 1 & (k - (n / 2));
          cout << k - (n / 2) << " 1\n";
          suma += k & (k - 1);
          cout << n - 1 << " " << n - 2 << "\n";
        } else if(i != 0 && i != 1){
          suma += i & (n - i - 1);
          cout << i << " " << n - i - 1 << "\n";
        }
      }
    } else {
      for(long long i = 0; i < n / 2; i++){
        if(k == 0){
          suma += i & (n - i - 1);
          cout << i << " " << n - i - 1 << "\n";
        } else if(i == k || n - i - 1 == k){
          cout << "0 ";
          if(i == k){
            suma += 0 & (n - i - 1);
            cout << n - i - 1;
          } else {
            suma += 0 & (i);
            cout << i;
          }
          cout << "\n";
          if(i == k){
            suma += i & (n - 1);
            cout << i << " ";
          } else {
            suma += (n - i - 1) & (n - 1);
            cout << n - i - 1 << " ";
          }
          cout << n - 1 << "\n";
        } else if(i != 0){
          suma += i & (n - i - 1);
          cout << i << " " << n - i - 1 << "\n";
        }
      }
    }
    //cout << "SUMA: " << suma << "\n";
  }
  return 0;
}