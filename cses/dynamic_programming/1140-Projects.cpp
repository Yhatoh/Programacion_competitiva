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
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {  
    int n;
    cin >> n;

    vector< pair< pair< ll, ll >, ll > > v(n);
    set< ll > days;
    fn(i, n) {
      cin >> v[i].first.first >> v[i].first.second >> v[i].second;
      v[i].first.second++;
      days.insert(v[i].first.first);
      days.insert(v[i].first.second);
    }

    map< ll, ll > compress;
    int coords = 1;
    for(auto x : days) compress[x] = coords++;

    vector< vector< pair< ll, ll > > > end(coords);
    fn(i, n) end[compress[v[i].first.second]].push_back({compress[v[i].first.first], v[i].second});

    vector< ll > dp(coords, 0);
    flr(i, 1, coords) {
      dp[i] = dp[i - 1];
      for(auto x : end[i]) {
        dp[i] = max(dp[i], dp[x.first] + x.second);
      }
    }
    cout << dp[coords - 1] << "\n";
  }
  return 0;
}
