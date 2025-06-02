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
#define feach(a, x) for (auto &a : x)
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

const int MAXNODES = 200005;
typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

int max_len;
ll mul = 1;
ll ans;
int n, l, r;
vi g[MAXNODES];

int get_prefix(const deque<int> &a, int mx) {
	if (mx < 0) return 0;
	if (mx + 1 >= a.size()) return a[0];
	return a[0] - a[mx + 1];
}

void comb(deque<int> &a, deque<int> &b) {
	if (a.size() < b.size()) swap(a, b);
	fn(i, b.size() - 1) b[i] -= b[i + 1];
	fn(i, b.size())
	ans += (ll) b[i] * (get_prefix(a, r - i) - get_prefix(a, l - 1 - i));
	frle(i, 0, b.size() - 2) b[i] += b[i + 1];
	fn(i, b.size()) a[i] += b[i];
}

deque<int> dfs(int x, int p) {  // each deque stores prefix sums
	deque<int> res{1};
	feach(y, g[x]) if (y != p) {
		deque<int> a = dfs(y, x);
		a.push_front(a.front());
		comb(res, a);
	}
	return res;
}
int main() {
  scanf("%d %d %d", &n, &l, &r);
  fn(i, n - 1) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  max_len = l - 1;
  mul = -1;
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
