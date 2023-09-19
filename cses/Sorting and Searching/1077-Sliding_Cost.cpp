/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector< int > v(n);
  fn(i, n) cin >> v[i];
 
  multiset< int > up;
  multiset< int > low;
 
  ll sum_low = 0;
  ll sum_up = 0;
  fn(i, n) {
    int x = v[i];
    if(up.size() + low.size() == (unsigned int)k) {
      if(low.size() == up.size()) {
        ll mid = (*prev(low.end()) + *up.begin()) / 2;
        cout << abs(mid * (ll)low.size() - sum_low) + abs(sum_up - mid * (ll)up.size()) << " ";
      } else {
        ll mid = (*prev(low.end()));
        cout << abs(mid * (ll)low.size() - sum_low) + abs(sum_up - mid * (ll)up.size()) << " ";
      }

      int destroy = v[i - k];
      if(destroy <= *prev(low.end())) {
        sum_low -= destroy;
        low.erase(low.find(destroy));
      } else {
        sum_up -= destroy;
        up.erase(up.find(destroy));
      }
    }
 
    if(low.size() > 0 && x <= *prev(low.end())) {
      sum_low += x;
      low.insert(x);
    } else if(up.size() > 0 && x >= *up.begin()){
      sum_up += x;
      up.insert(x);
    } else {
      sum_low += x;
      low.insert(x);
    }
 
    if(low.size() + up.size() > 1) {
      if(low.size() < up.size()) {
        sum_low += *up.begin();
        sum_up -= *up.begin();
        low.insert(*up.begin());
        up.erase(up.begin());
      } else if(k % 2 && low.size() > up.size() + 1) {
        sum_low -= *prev(low.end());
        sum_up += *prev(low.end());
        up.insert(*prev(low.end()));
        low.erase(prev(low.end()));
      } else if(k % 2 == 0 && low.size() > up.size()) {
        sum_low -= *prev(low.end());
        sum_up += *prev(low.end());
        up.insert(*prev(low.end()));
        low.erase(prev(low.end()));
      }
    }
  }
  if(low.size() == up.size()) {
    ll mid = (*prev(low.end()) + *up.begin()) / 2;
    cout << abs(mid * (ll)low.size() - sum_low) + abs(sum_up - mid * (ll)up.size()) << " ";
  } else {
    ll mid = (*prev(low.end()));
    cout << abs(mid * (ll)low.size() - sum_low) + abs(sum_up - mid * (ll)up.size()) << " ";
  }
 
  cout << "\n";
  return 0;
}
