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

void BFS(vector< string > &g, vector< vector< int > > &ds, vector< pair< int, int > > &m) {
  queue< pair< int, int > > q;
  fn(i, m.size()) {
    ds[m[i].first][m[i].second] = 0;
    q.push({m[i].first, m[i].second});
  }
  while(!q.empty()) {
    int nx = q.front().first;
    int ny = q.front().second;
    q.pop();

    if(nx > 0 && g[nx - 1][ny] != '#') {
      if(ds[nx - 1][ny] > ds[nx][ny] + 1) {
        ds[nx - 1][ny] = ds[nx][ny] + 1;
        q.push({nx - 1, ny});
      }
    }
    if(ny > 0 && g[nx][ny - 1] != '#') {
      if(ds[nx][ny - 1] > ds[nx][ny] + 1) {
        ds[nx][ny - 1] = ds[nx][ny] + 1;
        q.push({nx, ny - 1});
      }
    }
    if(nx < g.size() - 1 && g[nx + 1][ny] != '#') {
      if(ds[nx + 1][ny] > ds[nx][ny] + 1) {
        ds[nx + 1][ny] = ds[nx][ny] + 1;
        q.push({nx + 1, ny});
      }
    }
    if(ny < g[0].size() - 1 && g[nx][ny + 1] != '#') {
      if(ds[nx][ny + 1] > ds[nx][ny] + 1) {
        ds[nx][ny + 1] = ds[nx][ny] + 1;
        q.push({nx, ny + 1});
      }
    }
  }
}

void BFS(vector< string > &g, vector< vector< int > > &ds, vector< vector< int > > &ds2, int sx, int sy, vector< vector< pair< int, int > > > &p) {
  ds[sx][sy] = 0;
  ds2[sx][sy] = 0;
  queue< pair< int, int > > q;
  q.push({sx, sy});
  while(!q.empty()) {
    int nx = q.front().first;
    int ny = q.front().second;
    q.pop();

    if(nx > 0 && g[nx - 1][ny] != '#') {
      if(ds[nx - 1][ny] > ds[nx][ny] + 1 && ds2[nx - 1][ny] > ds2[nx][ny] + 1) {
        ds[nx - 1][ny] = ds[nx][ny] + 1;
        ds2[nx - 1][ny] = ds2[nx][ny] + 1;
        p[nx - 1][ny] = {nx, ny};
        q.push({nx - 1, ny});
      }
    }
    if(ny > 0 && g[nx][ny - 1] != '#') {
      if(ds[nx][ny - 1] > ds[nx][ny] + 1 && ds2[nx][ny - 1] > ds2[nx][ny] + 1) {
        ds[nx][ny - 1] = ds[nx][ny] + 1;
        ds2[nx][ny - 1] = ds2[nx][ny] + 1;
        p[nx][ny - 1] = {nx, ny};
        q.push({nx, ny - 1});
      }
    }
    if(nx < g.size() - 1 && g[nx + 1][ny] != '#') {
      if(ds[nx + 1][ny] > ds[nx][ny] + 1 && ds2[nx + 1][ny] > ds2[nx][ny] + 1) {
        ds[nx + 1][ny] = ds[nx][ny] + 1;
        ds2[nx + 1][ny] = ds2[nx][ny] + 1;
        p[nx + 1][ny] = {nx, ny};
        q.push({nx + 1, ny});
      }
    }
    if(ny < g[0].size() - 1 && g[nx][ny + 1] != '#') {
      if(ds[nx][ny + 1] > ds[nx][ny] + 1 && ds2[nx][ny + 1] > ds2[nx][ny] + 1) {
        ds[nx][ny + 1] = ds[nx][ny] + 1;
        ds2[nx][ny + 1] = ds2[nx][ny] + 1;
        p[nx][ny + 1] = {nx, ny};
        q.push({nx, ny + 1});
      }
    }
  }
}

int main() {
  /*
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  */
  int n, m;
  cin >> n >> m;
  vector< string > g(n);
  vector< pair< int, int > > monsters;
  int sx, sy;
  fn(i, n) {
    cin >> g[i];
    fn(j, m) {
      if(g[i][j] == 'M') monsters.push_back({i, j});
      else if(g[i][j] == 'A') {
        sx = i; sy = j;
      }
    }
  }

  vector< vector< int > > d(n, vector< int >(m, 10000000));

  BFS(g, d, monsters);

  vector< vector< int > > d2(n, vector< int >(m, 10000000));
  vector< vector< pair< int, int > > > p(n, vector< pair< int, int > >(m));
  BFS(g, d, d2, sx, sy, p);

  int fx, fy;
  fx = fy = -1;
  fn(i, n) {
    if(d2[i][0] != 10000000) {
      fx = i;
      fy = 0;
      break;
    }
    if(d2[i][m - 1] != 10000000) {
      fx = i;
      fy = m - 1;
      break;
    }
  }
  fn(i, m) {
    if(d2[0][i] != 10000000) {
      fx = 0;
      fy = i;
      break;
    }
    if(d2[n - 1][i] != 10000000) {
      fx = n - 1;
      fy = i;
      break;
    }
  }

  if(fx == -1) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << d2[fx][fy] << "\n";
  string ans = "";
  for(int i = fx, j = fy;
      i != sx || j != sy;) {
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
