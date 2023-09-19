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
    map< string, int > nametonum;
    map< int, string > numtoname;
    string command;
    while(cin >> command) {
      if(command == "def") {
        string var;
        int num;
        cin >> var >> num;
        if(nametonum.find(var) != nametonum.end()) numtoname.erase(nametonum[var]);
        nametonum[var] = num;
        numtoname[num] = var;
      } else if(command == "calc") {
        string op;
        string var;
        cin >> var;

        int sum = 0;
        bool flag = false;
        if(nametonum.find(var) != nametonum.end()) {
          sum += nametonum[var];
        } else {
          flag = true;
        }

        string res = "";

        res += var;
 
        op = "$";
        while(op != "=") {
          cin >> op;
          res += " ";
          res += op;

          if(op == "=") break;

          cin >> var;
          if(nametonum.find(var) != nametonum.end()) {
            if(op == "+")
              sum += nametonum[var];
            else
              sum -= nametonum[var];
          } else {
            flag = true;
          }
          res += " ";
          res += var;
        }

        if(!flag && numtoname.find(sum) != numtoname.end()) {
          res += " ";
          res += numtoname[sum];
        } else {
          flag = true;
        }

        if(flag) {
          res += " unknown";
        }

        cout << res << "\n";
      } else if(command == "clear") {
        nametonum.clear();
        numtoname.clear();
      }
    }
  }
  return 0;
}
