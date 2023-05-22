#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n > 19) cout << "NO\n";
    else {
      cout << "YES\n";
      int to_print = 1;
      for (int i = 0; i < n - 1; ++i){
        cout << to_print << " ";
        to_print *= 3;
      }
      cout << to_print << "\n";
    }
  }
  return 0;
}