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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]\n";
  return os;
}

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
    int n;
    cin >> n;
    vvll chess(n, vll(n, 0));
    fn(i, n)
      fn(j, n)
        cin >> chess[i][j];

    vvll prefix_diags(n, vll(n, 0));
    vvll prefix_diags2(n, vll(n, 0));
    fn(i, n) {
      fn(j, n) {
        if(i - 1 >= 0 && j - 1 >= 0) {
          prefix_diags[i][j] = chess[i][j] + prefix_diags[i - 1][j - 1];
        } else {
          prefix_diags[i][j] = chess[i][j];
        }
      }
    }

    frle(i, 0, n - 1) {
      frle(j, 0, n - 1) {
        if(i + 1 < n && j + 1 < n) {
          prefix_diags[i][j] = prefix_diags[i + 1][j + 1];
        }
      }
    }

    frle(i, 0, n - 1) {
      fn(j, n) {
        if(i + 1 < n && j - 1 >= 0) {
          prefix_diags2[i][j] = chess[i][j] + prefix_diags2[i + 1][j - 1];
        } else {
          prefix_diags2[i][j] = chess[i][j];
        }
      }
    }

    fn(i, n) {
      frle(j, 0, n - 1) {
        if(i - 1 >= 0 && j + 1 < n) {
          prefix_diags2[i][j] = prefix_diags2[i - 1][j + 1];
        }
      }
    }

    ll b1 = -1;
    ll x1 = -1;
    ll y1 = -1;
    ll b2 = -1;
    ll x2 = -1;
    ll y2 = -1;

    fn(i, n) {
      fn(j, n) {
        if((i + j) % 2) {
          if(prefix_diags[i][j] + prefix_diags2[i][j] - chess[i][j] > b1) {
            b1 = prefix_diags[i][j] + prefix_diags2[i][j] - chess[i][j];
            x1 = i;
            y1 = j;
          }
        } else {
          if(prefix_diags[i][j] + prefix_diags2[i][j] - chess[i][j] > b2) {
            b2 = prefix_diags[i][j] + prefix_diags2[i][j] - chess[i][j];
            x2 = i;
            y2 = j;
          }
        }
      }
    }

    cout << b1 + b2 << "\n";
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
  }
  return 0;
}
