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

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

void dijsktra(vvpll &g, vll &min_d, vll &cant_min, vll &min_flights, vll &max_flights, int node) {
  priority_queue< pll, vpll, greater< pll >> pq;
  min_d[node] = 0;
  cant_min[node] = 1;
  min_flights[node] = 0;
  max_flights[node] = 0;

  pq.push({0, node});
  while(!pq.empty()) {
    ll d = pq.top().first;
    ll act = pq.top().second;
    pq.pop();
    if(d > min_d[act]) continue;

    fn(i, g[act].size()) {
      ll next = g[act][i].first;
      ll w = g[act][i].second;
      if(w + d == min_d[next]) {
        cant_min[next] = (cant_min[next] + cant_min[act]) % 1000000007;
        min_flights[next] = min(min_flights[next], min_flights[act] + 1);
        max_flights[next] = max(max_flights[next], max_flights[act] + 1);
      } else if(w + d < min_d[next]) {
        min_d[next] = w + d;
        cant_min[next] = cant_min[act];
        min_flights[next] = min_flights[act] + 1;
        max_flights[next] = max_flights[act] + 1;
        pq.push({w + d, next});
      }
    }
  }
}

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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vvpll g(n);
    fn(i, m) {
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      g[a].push_back({b, c});
    }

    vll min_d(n, 1000000000000000);
    vll cant_min(n, 0);
    vll min_flights(n, 0);
    vll max_flights(n, 0);
    dijsktra(g, min_d, cant_min, min_flights, max_flights, 0);
    cout << min_d[n - 1] << " ";
    cout << cant_min[n - 1] << " ";
    cout << min_flights[n - 1] << " ";
    cout << max_flights[n - 1] << "\n";
  }
  return 0;
}
