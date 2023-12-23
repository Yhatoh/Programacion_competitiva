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
#define feach(a, x) for (auto &a : x)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

bool can(vll &multi, int pos, int amount) {
    if(pos == -1) return false;

    if(multi[pos] >= amount) {
        multi[pos] -= amount;
        return true;
    }

    amount -= multi[pos];
    multi[pos] = 0;
    return can(multi, pos - 1, amount * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    int t = 1;
    cin >> t;
    vll multi(30, 0);
    while(t--) {
        int op;
        cin >> op;
        if(op == 1) {
            int pos;
            cin >> pos;
            multi[pos]++;
        } else {
            ll w;
            cin >> w;
            vll cop = multi;
            bool flag = true;
            fn(i, 32) {
                if(w & (1LL << i)) {
                    int maxip = min(i, 29);
                    ll amount = 1;
                    if(i == 31) amount *= 4;
                    else if(i == 30) amount *= 2;
                    if(!can(multi, maxip, amount)) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
            multi = cop;
        }
    }
    return 0;
}
