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

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;
vvi adj, adj_rev;
vector<bool> used;
vi order, component;

void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u])
      dfs1(u);

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v])
    if (!used[u])
      dfs2(u);
}

#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vll cost(n);
    fn(i, n) cin >> cost[i];

    adj.assign(n, vi());
    adj_rev.assign(n, vi());
    int m;
    cin >> m;
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      adj[a].push_back(b);
      adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    fn(i, n)
      if (!used[i])
        dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());
    ll sum = 0;
    ll ways = 1;
    feach(v, order) {
      if(!used[v]) {
        dfs2(v);
        ll mini = 10000000000;
        feach(w, component) {
          mini = min(mini, cost[w]);
        }
        ll amount = 0;
        feach(w, component) {
          amount += cost[w] == mini;
        }

        ways = (ways * amount) % MOD;
        sum += mini;
        component.clear();
      }
    }
    cout << sum << " " << ways << "\n";
  }
  return 0;
}
