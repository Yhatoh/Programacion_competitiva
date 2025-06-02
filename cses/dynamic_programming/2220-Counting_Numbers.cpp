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
  
  ll a, b;
  cin >> a >> b;

  vector< ll > pre(19);
  pre[0] = 1;
  flr(i, 1, 19) pre[i]  = pre[i - 1] * 9;

  a--;
  ll ans_a = 0;
  int prev = 0;
  if(a < 1) {
    ans_a = (a == 0 ? 1 : 0);
  } else {
    string sa = to_string(a);
    fn(i, sa.size())
      ans_a += pre[i];

    bool flag = true;
    fn(i, sa.size()) {
      int digit = sa[i] - '0';
      int diff = digit;
      if(prev < diff) diff--;
      if(diff != 0)
        ans_a += diff * pre[sa.size() - i - 1];
      if(prev == digit) {
        flag = false;
        break;
      }
      prev = digit;
    }
    if(flag) ans_a++;
  }

  ll ans_b = 0;
  if(b < 1) {
    ans_b = 1;
  } else {
    string sb = to_string(b);
    fn(i, sb.size())
      ans_b += pre[i];

    prev = 0;
    bool flag = true;
    fn(i, sb.size()) {
      int digit = sb[i] - '0';
      int diff = digit;
      if(prev < diff) diff--;
      if(diff != 0)
        ans_b += diff * pre[sb.size() - i - 1];
      if(prev == digit) {
        flag = false;
        break;
      }
      prev = digit;
    }
    if(flag) ans_b++;
  }
  
  cout << ans_b - ans_a << "\n";
  return 0;
}
