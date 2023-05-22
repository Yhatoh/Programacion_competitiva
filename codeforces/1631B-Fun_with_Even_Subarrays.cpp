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
    int n;
    cin >> n;
    vector< int > a(n);
    for (int i = 0; i < n; ++i){
      cin >> a[i];
    }
    
    int ops = 0;
    int element = a[n - 1];
    int i_eq = 1;
    int i = n - 2;

    while(i >= 0){
      if(a[i] != element){
        ops += 1;
        i -= i_eq;
        i_eq += i_eq;
      } else {
        i_eq++;
        i--;
      }
    }

    cout << ops << "\n";
  }
  return 0;
}