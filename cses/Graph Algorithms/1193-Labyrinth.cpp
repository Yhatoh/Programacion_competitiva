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
  int n, m;
  cin >> n >> m;

  vector< string > v(n);
  pair< int, int > s;
  pair< int, int > f;
  fn(i, n) {
    cin >> v[i]; 
    fn(j, m) {
      if(v[i][j] == 'A') {
        s.first = i; s.second = j;
      } else if(v[i][j] == 'B') {
        f.first = i; f.second = j;
      }
    }
  }

  queue< pair< int, int > > q;
  vector< vector< int > > d(n, vector< int >(m, 1000000000));
  vector< vector< pair< int, int > > > p(n, vector< pair< int, int > >(m));
  q.push(s);
  d[s.first][s.second] = 0;
  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    if(i > 0 && v[i - 1][j] != '#' && d[i - 1][j] > d[i][j] + 1) {
      d[i - 1][j] = d[i][j] + 1;
      p[i - 1][j] = {i, j};
      q.push({i - 1, j});
    }
    if(j > 0 && v[i][j - 1] != '#' && d[i][j - 1] > d[i][j] + 1) {
      d[i][j - 1] = d[i][j] + 1;
      p[i][j - 1] = {i, j};
      q.push({i, j - 1});
    }
    if(i < n - 1 && v[i + 1][j] != '#' && d[i + 1][j] > d[i][j] + 1) {
      d[i + 1][j] = d[i][j] + 1;
      p[i + 1][j] = {i, j};
      q.push({i + 1, j});
    }
    if(j < m - 1 && v[i][j + 1] != '#' && d[i][j + 1] > d[i][j] + 1) {
      d[i][j + 1] = d[i][j] + 1;
      p[i][j + 1] = {i, j};
      q.push({i, j + 1});
    }
  }

  if(d[f.first][f.second] == 1000000000) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << d[f.first][f.second] << "\n";
  string ans = "";
  for(int i = f.first, j = f.second; 
      i != s.first || j != s.second;) {
    int n_i = p[i][j].first;
    int n_j = p[i][j].second;
    int diff_i = i - n_i;
    int diff_j = j - n_j;
    if(diff_i < 0) {
      ans += "U";
    } else if(diff_i > 0) {
      ans += "D";
    } else if(diff_j < 0) {
      ans += "L";
    } else {
      ans += "R";
    }
    i = n_i; j = n_j;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
  cout << "\n";
  return 0;
}
