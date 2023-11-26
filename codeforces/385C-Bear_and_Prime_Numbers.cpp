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

#define MAX 10000000
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vll nums(n);
    fn(i, n) cin >> nums[i];

    vll count(MAX + 1, 0);
    fn(i, n)
      count[nums[i]]++;

    vector<bool> is_prime(MAX + 1, true);
    vll f(MAX + 1, 0);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= MAX; i++) {
      if (is_prime[i]) {
        for (ll j = i; j <= MAX; j += i) {
          f[i] += count[j];
          is_prime[j] = false;
        }
      }
    }
    vll prefix(MAX + 1, 0);
    flr(i, 1, MAX + 1)
      prefix[i] = prefix[i - 1] + f[i];

    int q;
    cin >> q;
    while(q--) {
      int l, r;
      cin >> l >> r;
      r = min(r, MAX);
      if(l > MAX) cout << 0 << "\n";
      else cout << prefix[r] - prefix[l - 1] << "\n";
    }
  }
  return 0;
}
