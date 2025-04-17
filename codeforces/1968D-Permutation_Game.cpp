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
typedef long double ld; typedef vector< ld > vld;
typedef vector< vld > vvld; typedef pair< ld, ld > pldld;
typedef vector< pldld > vpldld; typedef vector< vpldld >  vvpldld;

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  cin >> t;
  while(t--) {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    pb--;
    ps--;
    vi permut(n);
    fn(i, n) {
      cin >> permut[i];
      permut[i]--;
    }

    vll values(n);
    fn(i, n) cin >> values[i];

    vi vis_b(n, 0);

    ll max_b = 0;
    ll acum_sum_b = 0;
    ll k_b = k;
    while(k_b > 0 && !vis_b[pb]) {
      vis_b[pb] = 1;
      max_b = max(max_b, acum_sum_b + values[pb] * k_b);

      acum_sum_b += values[pb];
      pb = permut[pb];
      k_b--;
    }

    vi vis_s(n, 0);

    ll max_s = 0;
    ll acum_sum_s = 0;
    ll k_s = k;
    while(k_s > 0 && !vis_s[ps]) {
      vis_s[ps] = 1;
      max_s = max(max_s, acum_sum_s + values[ps] * k_s);

      acum_sum_s += values[ps];
      ps = permut[ps];
      k_s--;
    }

    if(max_b > max_s) cout << "Bodya";
    else if(max_s > max_b) cout << "Sasha";
    else cout << "Draw";
    cout << "\n";
  }
  return 0;
}
