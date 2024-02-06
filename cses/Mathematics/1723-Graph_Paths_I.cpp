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
#define feach(x, ds) for(auto &x : ds)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

const ll MOD = 1000000007;

void mod(vvll &a, ll MOD) {
  vvll b(a.size(), vll(a[0].size(), 0));
  fn(i, a.size()) {
    fn(j, a[0].size()) {
      a[i][j] %= MOD;
    }
  }
}

void mult(vvll &a, vvll &b, ll MOD) {
  vvll c(a.size(), vll(a[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int k = 0; k < a[0].size(); k++) {
      for (int j = 0; j < a[0].size(); j++) {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  swap(a, c);
}

void expo(vvll &a, ll b, ll MOD) {
  vvll res(a.size(), vll(a[0].size(), 0));
  fn(i, res.size()) res[i][i] = 1;

  while(b > 0) {
    if(b % 2) {
      mult(res, a, MOD);
    }
    mult(a, a, MOD);
    b /= 2;
  }
  swap(a, res);
}

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vvll g(n, vll(n, 0));
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a][b]++;
    }
    expo(g, k, MOD);
    cout << g[0][n - 1] << "\n";
  }
  return 0;
}
