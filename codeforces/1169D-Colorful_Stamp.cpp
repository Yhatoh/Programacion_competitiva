#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int amount = 0;
    int amount_r = 0;
    int amount_b = 0;
    bool flag = true;
    for(int i = 0; i < s.length(); i++){
      if(s[i] != 'W'){
        amount++;
        if(s[i] == 'R'){
          amount_r++;
        } else {
          amount_b++;
        }
      } else {
        if(amount == 1){
          flag = false;
          break;
        }
        
        if(amount > 1 && (amount_r == 0 || amount_b == 0)){
          flag = false;
          break;
        }

        amount = amount_b = amount_r = 0;
      }
    }       
     if(amount == 1){
          flag = false;
        }
        
        if(amount > 1 && (amount_r == 0 || amount_b == 0)){
          flag = false;
        }


    cout << (flag ? "YES\n" : "NO\n");
  } 
  return 0;
}

