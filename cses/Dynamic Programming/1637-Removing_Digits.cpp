#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > monedas;

void print(vector< long long int > &v){
  long long int i;
  for(i = 0; i < ((long long int) v.size()) - 1; i++){
    cout << v[i] << " ";
  }
  cout << v[i] << "\n";
}

ll remove_digits(ll v){
  vector< ll > valores(v + 1, 1000000009);

  valores[0] = 0;
  for(ll i = 1; i <= v; i++){
    ll num = i;
    //cout << "--\n";
    //cout << num << "\n";
    while(num > 0){
      ll digit = num % 10;
      //cout << digit << "\n";
      num /= 10;
      if(i - digit >= 0){
        valores[i] = min(valores[i - digit] + 1, valores[i]);
      }
    }
  }

  //print(valores);
  return valores[v];
}

int main(){
  int n;
  cin >> n;

  cout << remove_digits(n) << "\n";
  return 0;
}