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
#define feach(x, e) for(auto &x : e)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< long long > vi;
typedef long long ll;
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
    vi l(n);
    vi r(n);
    vi c(n);
    fn(i, n) cin >> l[i];
    fn(i, n) cin >> r[i];
    fn(i, n) cin >> c[i];

    vector< pair< long long, long long > > lr;
    fn(i, n) {
      lr.push_back({l[i], 0});
      lr.push_back({r[i], 1});
    }
    vi diffs;
    sortv(lr);
    stack< long long > s;
    fn(i, (long long)lr.size()) {
      if(lr[i].second == 0) {
        s.push(lr[i].first);
      } else {
        diffs.push_back(lr[i].first - s.top());
        s.pop();
      }
    }

    sortv(diffs);
    sortv(c);
    ll sum = 0;
    fn(i, n) {
      sum += diffs[i] * c[n - i - 1];
    }
    cout << sum << "\n";
  }
  return 0;
}
