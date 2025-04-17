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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}
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
    int n, m, q;
    cin >> n >> m >> q;
    vi teachers(m);
    fn(i, m) cin >> teachers[i];
    vi queries(q);
    fn(i, q) cin >> queries[i];

    sort(teachers.begin(), teachers.end());
    fn(i, q) {
      int s = queries[i];
      auto t1 = lower_bound(teachers.begin(), teachers.end(), s);
      vector< int >::iterator t2;
      if(t1 == teachers.end()) {
        t1 = prev(t1);
        t2 = t1;
      } else if(t1 == teachers.begin()) {
        t2 = t1;
      } else {
        t2 = prev(t1);
      }

      if(s < *t1 && s < *t2) {
        cout << (s - 1) + min(*t1,*t2) - (s - 1) - 1 << "\n";
      } else if(s > *t1 && s > *t2) {
        cout << (n - s) + n - (max(*t1, *t2) + (n - s)) << "\n";
      } else {
        int aux = min(*t1, *t2);
        int aux2 = max(*t1, *t2);
        int x1 = aux;
        int x2 = aux2;
        int mid_point = (x2 + x1) / 2;

        cout << abs(mid_point - s) + min(mid_point - (x1 + abs(mid_point - s)), (x2 - abs(mid_point - s)) - mid_point) << "\n"; 
      }

    }
  }
  return 0;
}
