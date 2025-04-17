/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define dbg(var) cout << #var << " = " << var << "\n";
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

struct query {
  int t, a, c;
  query() {}
  query(int t_, int a_, int c_) : t(t_), a(a_), c(c_) {}
};

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int h, w, m;
    cin >> h >> w >> m;

    vector< query > qs(m);
    fn(i, m) {
      cin >> qs[i].t >> qs[i].a >> qs[i].c;
      qs[i].a--;
    }

    int r_0 = h;
    int c_0 = w;

    vi r_used(h, 0);
    vi c_used(w, 0);

    map< int, ll > mp;
    frle(i, 0, m - 1) {
      if(qs[i].t == 1) {
        if(r_used[qs[i].a] == 0) {
          r_used[qs[i].a] = 1;
          r_0--;
          mp[qs[i].c] += c_0;
        }
      } else {
        if(c_used[qs[i].a] == 0) {
          c_used[qs[i].a] = 1;
          c_0--;
          mp[qs[i].c] += r_0;
        }
      }
    }

    mp[0] += (ll) r_0 * c_0;
    ll count = 0;
    for(auto p : mp) {
      count += p.second != 0;
    }
    cout << count << "\n";
    for(auto p : mp) {
      if(p.second != 0)
        cout << p.first << " " << p.second << "\n";
    }

  }
  return 0;
}
