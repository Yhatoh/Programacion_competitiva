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
  os << "[";
  for(uint64_t i = 0; i < vec.size(); i++) {
    os << vec[i];
    if(i != vec.size() - 1)
      os << ", ";
  }
  os << "]\n";
  return os;
}

#define MAX_LIFT 30

pair< int, ll > jump(int a, int b, vvll &to, vvll &costs) {
  ll res = 0;
  frle(i, 0, MAX_LIFT - 1) {
    if(to[i][a] > b) continue;
    res += costs[i][a];
    a = to[i][a];
  }
  return {a, res};
}

int main() {
#ifndef debug
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
#endif
  int t = 1;
  while(t--) {
    int n, q;
    cin >> n >> q;
    vll nums(n);
    vll prefix(n + 1, 0);
    fn(i, n) {
      cin >> nums[i];
      prefix[i + 1] = prefix[i] + nums[i];
    }
    vvll to(MAX_LIFT, vll(n + 1, 0));
    stack< pll > mono;
    fn(i, n) {
      if(mono.empty()) {
        mono.push({nums[i], i});
      } else if(mono.top().first < nums[i]) {
        while(!mono.empty() && mono.top().first < nums[i]) {
          to[0][mono.top().second] = i;
          mono.pop();
        }
        mono.push({nums[i], i});
      } else {
        mono.push({nums[i], i});
      }
    }
    while(!mono.empty()) {
      to[0][mono.top().second] = n;
      mono.pop();
    }

    fn(i, MAX_LIFT) {
      to[i][n] = n;
    }

    flr(i, 1, MAX_LIFT) {
      flr(j, 0, n) {
        to[i][j] = to[i - 1][to[i - 1][j]];
      }
    }

    vvll cost(MAX_LIFT, vll(n + 1, 0));
    fn(i, n) {
      cost[0][i] = nums[i] * (to[0][i] - i) - (prefix[to[0][i]] - prefix[i]);
    }

    flr(i, 1, MAX_LIFT) {
      flr(j, 0, n) {
        cost[i][j] = cost[i - 1][j] + cost[i - 1][to[i - 1][j]];
      }
    }

    while(q--) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      pair< int, ll > res = jump(a, b, to, cost);
      cout << res.second + (b - res.first) * nums[res.first] - (prefix[b + 1] - prefix[res.first + 1]) << "\n";;
    }
  }
  return 0;
}
