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
    vector< vector< int > > m(3, vector< int >(3, 0));
    fn(i, 3)
      fn(j, 3)
        cin >> m[i][j];

    m[0][0] = (m[2][0] + m[2][1] + m[1][0] + m[1][2] - m[0][1] - m[0][2]) / 2;
    m[1][1] = m[0][0] + m[0][1] + m[0][2] - m[1][0] - m[1][2];
    m[2][2] = m[0][0] + m[0][1] + m[0][2] - m[2][0] - m[2][1];
    fn(i, 3) {
      fn(j, 3)
        cout << m[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
