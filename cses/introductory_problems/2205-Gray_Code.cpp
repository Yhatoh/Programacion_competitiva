#include<bits/stdc++.h>
using namespace std;

void GrayCode(string code, int n, int bit, bool change){
  if(bit == n){
    cout << code << "\n";
    return;
  }

  if(change){
    GrayCode(code + "0", n, bit + 1, change);
    GrayCode(code + "1", n, bit + 1, !change);
  } else {
    GrayCode(code + "1", n, bit + 1, !change);
    GrayCode(code + "0", n, bit + 1, change);
  }
}

int main(){
  int n;
  cin >> n;
  GrayCode("", n, 0, true);
  return 0;
}