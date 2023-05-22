#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    string number, res1, res2;
    cin >> number;
    res1 = number;
    res2 = number;

    int dl, dr;
    dl = number[0] - '0';
    dr = number[1] - '0';
    bool booli = false;
    string dldr = to_string(dl + dr);
    res1.replace(0, 2, dldr);
    for(int i = res2.length() - 2; i >= 0; i--){
      dl = res2[i] - '0';
      dr = res2[i + 1] - '0';
      if(dl + dr >= 10){
        string dldr = to_string(dl + dr);
        res2.replace(i, 2, dldr);
        booli = true;
        break;
      } 
    }

    if(booli) cout << res2 << "\n";
    else cout << res1 << "\n";

  }
  return 0;
}