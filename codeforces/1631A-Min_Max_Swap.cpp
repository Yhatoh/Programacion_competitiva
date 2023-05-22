#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector< int > a(n);
    vector< int > b(n);
    for (int i = 0; i < n; ++i){
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
      cin >> b[i];
    }

    for (int i = 0; i < n; ++i){
      if(a[i] < b[i]){
        int aux = a[i];
        a[i] = b[i];
        b[i] = aux;
      }
    }

    cout << (*max_element(a.begin(), a.end())) * (*max_element(b.begin(), b.end())) << "\n";

  }
  return 0;
}