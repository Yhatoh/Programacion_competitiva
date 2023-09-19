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
 
  int x, n;
  cin >> x >> n;
  set< int > lights;
  lights.insert(0);
  lights.insert(x);
  multiset< int > diff;
  diff.insert(x);

  fn(i, n) {
    int l;
    cin >> l;
    auto itr = lights.upper_bound(l);
    auto itr2 = itr;
    --itr2;
    int xd = *itr - *itr2;
    diff.erase(diff.find(*itr - *itr2));
    diff.insert(*itr - l);
    diff.insert(l - *itr2);
    cout << *(--diff.end()) << " ";
    lights.insert(l);
  }
  cout << "\n";
  return 0;
}
