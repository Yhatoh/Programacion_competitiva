/*
  Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
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

signed main() {
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
#endif
    int t = 1;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        vi b(n);
        vi pre(n + 1);
        feach(i, a) cin >> i;
        feach(i, b) cin >> i;
        pre[0] = 0;
        flr(i, 1, n + 1) pre[i] = pre[i - 1] + a[i - 1];
        vi maxs(n);
        int act_max = b[0];
        fn(i, n) {
            act_max = max(act_max, b[i]);
            maxs[i] = act_max;
        }
        int ans = 0;
        fn(i, n) {
            if(k > (i + 1))
                ans = max(pre[i + 1] + (k - (i + 1)) * maxs[i], ans);
        }
        cout << ans << "\n";
    }
    return 0;
}
