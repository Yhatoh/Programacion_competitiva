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
  while(t--) {
    string num;
    cin >> num;
    int a, b;
    cin >> a >> b;

    vector< int > digit(num.size(), 0);
    fn(i, num.size()) digit[i] = num[i] - '0';
    vector< int > prefix(num.size(), 0);
    vector< int > suffix(num.size(), 0);

    prefix[0] = digit[0] % a;
    suffix[suffix.size() - 1] = digit[digit.size() - 1] % b;
    flr(i, 1, prefix.size()) {
      prefix[i] = (prefix[i - 1] * 10 + digit[i]) % a;
    }
    long long pow_10 = 10;
    frle(i, 0, suffix.size() - 2) {
      suffix[i] = (suffix[i + 1] + (digit[i] * pow_10) % b) % b;
      pow_10 = (pow_10 * 10) % b;
    }

    fn(i, num.size() - 1) {
      if(prefix[i] == 0 && suffix[i + 1] == 0 && digit[i + 1] != 0) {
        cout << "YES\n";
        fn(j, i + 1) cout << digit[j];
        cout << "\n";
        flr(j, i + 1, num.size()) cout << digit[j];
        cout << "\n";
        return 0;
      }
    }
    cout << "NO\n";
  }
  return 0;
}
