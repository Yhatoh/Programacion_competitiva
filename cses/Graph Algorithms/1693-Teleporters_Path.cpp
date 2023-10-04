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
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector< set< int > > g(n);
    vector< int > in(n, 0);
    vector< int > out(n, 0);
    fn(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[a].insert(b);
      in[b]++; out[a]++;
    }
 
    int same = 0;
    int more_in = 0;
    int more_out = 0;
    int node_in = -1;
    int node_out = -1;
    fn(i, n) {
      if(in[i] == out[i]) same++;
      else if(in[i] == out[i] + 1) {
        more_in++;
        node_in = i;
      } else if(in[i] + 1 == out[i]){
        more_out++;
        node_out = i;
      }
    }

    if(node_out != 0 || node_in != n - 1) cout << "IMPOSSIBLE\n";
    else if(same != n - 2 || more_in != 1 || more_out != 1) cout << "IMPOSSIBLE\n";
    else {
      stack< int > st;
      st.push(0);
      vi ans;
      while(!st.empty()) {
        int now = st.top();
        if(out[now] == 0) {
          ans.push_back(now);
          st.pop();
        } else {
          int next = *g[now].begin();
          g[now].erase(next);
          out[now]--; in[next]--;
          st.push(next);
        }
      }
      if(ans.size() != m + 1) cout << "IMPOSSIBLE\n";
      else frle(i, 0, ans.size() - 1) cout << ans[i] + 1 << " ";
    }
  }
  return 0;
}
