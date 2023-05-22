#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(2);
  int t;
  cin >> t;
  while(t--){
    long long a, b, c;
    cin >> a >> b >> c;

    if(a - b == b - c){
      cout << "YES\n";
    } else if((2 * b - c) % a == 0 && (2 * b - c) > 0){
      cout << "YES\n";
    } else if((2 * b - a) % c == 0 && (2 * b - a) > 0){
      cout << "YES\n";
    //a - mb = mb - c => 2mb = a + c
    } else if((a + c) % (2 * b) == 0){
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}