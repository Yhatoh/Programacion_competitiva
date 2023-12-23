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

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
    os << "[";
    for(uint64_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if(i != vec.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

int main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
#endif
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vpii a(n);
        vpii b(n);
        vpii c(n);
        fn(i, n) {
            cin >> a[i].first;
            a[i].second = i;
        }
        fn(i, n) {
            cin >> b[i].first;
            b[i].second = i;
        }
        fn(i, n) {
            cin >> c[i].first;
            c[i].second = i;
        }
        sortv(a);
        sortv(b);
        sortv(c);
        int ans = 0;
        frle(i, n - 3, n - 1) {
            flre(j, n - 3, n - 1) {
                flre(k, n - 3, n - 1) {
                   if(a[i].second == b[j].second || a[i].second == c[k].second
                      || b[j].second == c[k].second ) continue;
                   ans = max(a[i].first + b[j].first + c[k].first, ans);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
