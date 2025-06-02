/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
 
#include <bits/stdc++.h>
using namespace std;
 
template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// Overloading the << operator for vectors of pairs
template <typename T >
std::ostream& operator<<(std::ostream& os, const std::vector< T >& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef long long ll;

ll queens(vector< string > &v, vector< pair< int, int > > &placed, int i) {
  if(i == 8) {
    return 1;
  }

  ll ret = 0;
  fn(j, 8) {
    if(v[i][j] == '*') continue;
    if(placed.size() > 0) {
      bool flag = true;
      fn(k, placed.size()) {
        int x, y;
        x = placed[k].first;
        y = placed[k].second;
        if(x == i) flag = false;
        if(y == j) flag = false;
        if(abs(x - i) == abs(y - j)) flag = false;
      }
      if(!flag) continue;
      placed.push_back({i, j});
      ret += queens(v, placed, i + 1);
      placed.pop_back();

    } else {
      placed.push_back({i, j});
      ret += queens(v, placed, i + 1);
      placed.pop_back();
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  vector< string > v(8);
  fn(i, 8) cin >> v[i];

  vector< pair< int, int > > p;
  cout << queens(v, p, 0)  << "\n";
  return 0;
}
