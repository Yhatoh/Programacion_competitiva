#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(vector< ll > &v){
  int i;
  cout << v.size() << "\n";
  for(i = ((int) v.size()) - 1; i > 0; i--){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

int main(){
  ll n;
  cin >> n;

  ll total = n * (n + 1) / 2;

  if(total % 2){
    cout << "NO\n";
  } else {
    ll toSum = total / 2;

    vector< ll > ans1;
    vector< ll > ans2;

    ll acum = 0;
    for(ll i = n; i > 0; i--){
      if(acum + i > toSum){
        ans2.push_back(i);
      } else {
        acum += i;
        ans1.push_back(i);
      }
    }

    cout << "YES\n";
    print(ans1);
    print(ans2);
    
  }
  return 0;
}