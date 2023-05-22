#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long l, r, a;
    cin >> l >> r >> a;
    if(a == 1){
      cout << r + r % a << "\n";
    }else if(r % a == 0){
      if(l == r) 
        cout << (r) / a + (r) % a << "\n";
      else
        cout << (r - 1) / a + (r - 1) % a << "\n";
    } else if ((r + 1) % a == 0){
      cout << (r) / a + (r) % a << "\n";
    } else {
      long long cand1 = r / a + r % a;
      long long cand2 = -1;
      long long new_value = (r - (r % a)) - 1;
      if(new_value >= l)
        cand2 = (new_value) / a + (new_value) % a;
      cout << max(cand1, cand2) << "\n";
    }
  }
  return 0;
}