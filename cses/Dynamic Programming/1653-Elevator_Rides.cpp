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

  ll n, x;
  cin >> n >> x;
  vector< ll > weights(n);
  fn(i, n) cin >> weights[i];

  vector< ll > min_rides(1 << n);
  vector< ll > min_last_weight(1 << n);

  min_rides[0] = 1;
  min_last_weight[0] = 0;
  for(int s = 1; s < (1 << n); s++) {
    min_rides[s] = n + 1;
    min_last_weight[s] = 0;
    for(int p = 0; p < n; p++) {
      ll p_in_s = s & (1 << p);
      if(p_in_s) {
        ll s_no_p = s ^ (1 << p);
        ll min_rides_s_no_p = min_rides[s_no_p];
        ll min_last_weight_s_no_p = min_last_weight[s_no_p];
        if(min_last_weight_s_no_p + weights[p] <= x) {
          // aun se puede
          if(min_rides[s] == min_rides_s_no_p) {
            min_rides[s] = min_rides_s_no_p;
            min_last_weight[s] = min(min_last_weight_s_no_p + weights[p], min_last_weight[s]);
          } else if(min_rides[s] > min_rides_s_no_p) {
            min_rides[s] = min_rides_s_no_p;
            min_last_weight[s] = min_last_weight_s_no_p + weights[p];
          }
        } else {
          if(min_rides[s] == min_rides_s_no_p + 1) {
            min_rides[s] = min_rides_s_no_p + 1;
            min_last_weight[s] = min(weights[p], min_last_weight[s]);
          } else if(min_rides[s] > min_rides_s_no_p + 1) {
            min_rides[s] = min_rides_s_no_p + 1;
            min_last_weight[s] = weights[p];
          }
        }
      }
    }
  }

  cout << min_rides[(1 << n) - 1] << "\n";
  return 0;
}
