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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i] << " ";
  }
  os << "\n";
  return os;
}

void dfs(vector< string > &maze, vvi &visited, int i, int j, int &amount, int &freec, int k) {
  visited[i][j] = 1;
  freec++;
  if(amount == freec + k) return;
  if(i - 1 >= 0 && visited[i - 1][j] == 0 && maze[i - 1][j] != '#') {
    dfs(maze, visited, i - 1, j, amount, freec, k);
  }
  if(amount == freec + k) return;
  if(j - 1 >= 0 && visited[i][j - 1] == 0 && maze[i][j - 1] != '#') {
    dfs(maze, visited, i, j - 1, amount, freec, k);
  }
  if(amount == freec + k) return;
  if(i + 1 < maze.size() && visited[i + 1][j] == 0 && maze[i + 1][j] != '#') {
    dfs(maze, visited, i + 1, j, amount, freec, k);
  }
  if(amount == freec + k) return;
  if(j + 1 < maze[0].size() && visited[i][j + 1] == 0 && maze[i][j + 1] != '#') {
    dfs(maze, visited, i, j + 1, amount, freec, k);
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector< string > maze(n);
    int cant_cels = 0;
    int free_i;
    int free_j;
    fn(i, n) {
      cin >> maze[i];
      fn(j, m) {
        if(maze[i][j] == '.') {
          cant_cels++;
          free_i = i;
          free_j = j;
        }
      }
    }

    vvi visited(n, vi(m, 0));
    int freec = 0;
    dfs(maze, visited, free_i, free_j, cant_cels, freec, k);

    fn(i, n) {
      fn(j, m) {
        if(maze[i][j] != '#' && visited[i][j] == 0) {
          cout << "X";
        } else {
          cout << maze[i][j];
        }
      }
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
