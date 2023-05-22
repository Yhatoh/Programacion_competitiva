#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n % 2 == 1) 
      for(int i = 0; i < n; i++) 
        cout << 1 << " ";
    else {
      cout << 1 << " " << 3 << " ";
      for(int i = 2; i < n; i++) 
        cout << 2 << " ";
    }
    cout << "\n";
  }
  return 0;
}
