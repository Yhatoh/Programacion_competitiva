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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n;
    cin >> n;
    vector< int > vec(n);
    fn(i, n)
      cin >> vec[i];
    int prev = vec[0];
    int first = -1;
    int second = -1;
    int flag = 0;
    flr(i, 1, n) {
      if(!flag && vec[i] < prev) {
        first = i - 1;
        flag = 1;
      } else if(flag && vec[i] > prev) {
        second = i - 1;
        break;
      }
      prev = vec[i];
    }
    if(first == -1 && second == -1) {
      cout << "yes\n";
      cout << "1 1\n";
      return 0;
    }

    if(first != -1 && second == -1) {
      second = n - 1;
    }

    int flag2 = 1;
    flr(i, second + 1, n - 1) {
      if(vec[i] > vec[i + 1]) {
        flag2 = 0;
        break;
      }
    }
    
    if(second < n - 1 && vec[first] > vec[second + 1]) {
      flag2 = 0;
    }
    if(first > 0 && vec[second] < vec[first - 1]) {
      flag2 = 0;
    }
    if(flag2) {
      cout << "yes\n";
      cout << first + 1 << " " << second + 1 << "\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}
