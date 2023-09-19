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

bool check(vector< ll > &v, ll k, ll mid) {
  ll sum = 0;
  ll count = 0;
  fn(i, v.size()) {
    if(v[i] > mid) return false;
    if(sum + v[i] > mid) {
      count++;
      sum = 0;
    }
    if(count > k) return false;
    sum += v[i];
  }
  if(sum <= mid) count++;
  if(count <= k) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);

  ll n, k;
  cin >> n >> k;
  vector< ll > v(n);
  ll l = 1;
  ll r = 0;
  fn(i, n) {
    cin >> v[i];
    r += v[i];
  }

  while(l < r) {
    ll mid = (l + r) / 2;
    if(check(v, k, mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
  return 0;
}
