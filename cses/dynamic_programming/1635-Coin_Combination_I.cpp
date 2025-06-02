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

ll intercambioMonedas(ll v, ll n){
  vector< ll > valores(v + 1, 0);

  valores[0] = 1;
  for(ll i = 1; i <= v; i++){
    for(ll j = 0; j < n; j++){
      if(i - monedas[j] >= 0){
        valores[i] =(valores[i] + valores[i - monedas[j]]) % 1000000007;
      }
    }
  }

  //print(valores);
  return valores[v];
}

int main(){
  int v, n;
  cin >> n >> v;

  for(int i = 0; i < n; i++){
    int moneda;
    cin >> moneda;
    monedas.push_back(moneda);
  }

  cout << intercambioMonedas(v, n) << "\n";
  return 0;
}