/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define F(i,L,R) for (int i = L; i < R; i++)

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector< int > a(n);
    F(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());
    int am_even = 0;
    int am_odd = 0;
    bool f_ebefore = false;
    bool f_obefore = false;
    F(i, 0, n) {
      if(a[i] % 2 == 0 || (a[i] % 2 == 1 && f_obefore)) {
        am_even++;
      }
      if(a[i] % 2 == 1 || (a[i] % 2 == 0 && f_obefore)) {
        am_odd++;
      }
      if(a[i] % 2 == 0) f_ebefore = true;
      else if(a[i] % 2 == 1) f_obefore = true;
    }

    if(am_even == n || am_odd == n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
