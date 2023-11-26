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

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
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
  cin >> t;
  while(t--) {
    int n, x;
    cin >> n >> x;
    vpii nums_a(n);
    vi nums_a2(n);
    fn(i, n) {
      int a;
      cin >> a;
      nums_a2[i] = a;
      nums_a[i].first = a;
      nums_a[i].second = i;
    }
    vpii nums_b(n);
    fn(i, n) {
      int b;
      cin >> b;
      nums_b[i].first = b;
      nums_b[i].second = i;
    }
    sortv(nums_a);
    sortv(nums_b);

    vi answer(n, 0);
    fn(i, x) {
      answer[nums_a[n - i - 1].second] = nums_b[x - i - 1].first;
    }
    flr(i, x, n) {
      answer[nums_a[n - i - 1].second] = nums_b[n - (i - x) - 1].first;
    }

    bool check = true;
    int objective = 0;
    fn(i, n) {
      if(answer[i] < nums_a2[i]) objective++;
    }
    if(objective != x) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      fn(i, n) {
        cout << answer[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
