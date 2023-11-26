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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector< int > costs(n, 0);
    int i = 0; int j = n - 1;
    while(i < j) {
      int cost1 = (s[i] > s[j] ? s[i] - s[j] : s[j] - s[i]);
      int cost2 = 'z' - s[i] + 1 + s[j] - 'a';
      int cost3 = 'z' - s[j] + 1 + s[i] - 'a';
      costs[i++] = min(cost1, min(cost2, cost3));
      costs[j--] = min(cost1, min(cost2, cost3));
    }

    int l, r;
    if(p <= n / 2) {
      l = 0; r = n / 2 - 1;
    } else {
      l = n / 2;
      r = n - 1;
    }
    p--;
    int pos_left = p;
    int left_cost = 0;
    frle(i, l, p - 1) {
      if(costs[i] != 0) pos_left = i;
    }
    frle(i, pos_left, p - 1) {
      left_cost += costs[i];
    }
    int right_cost = 0;
    int pos_right = p;
    flre(i, p + 1, r) {
      if(costs[i] != 0) pos_right = i;
    }
    flre(i, p + 1, pos_right) {
      right_cost += costs[i];
    }
    if(p - pos_left < pos_right - p) {
      cout << costs[p] + p - pos_left + pos_right - pos_left + right_cost + left_cost << "\n";
    } else {
      cout << costs[p] + pos_right - p + pos_right - pos_left + right_cost + left_cost << "\n"; 
    }
  }
  return 0;
}
