/*
Deseo ante todo expresar a mis conciudadanos que los últimos treinta años de mi vida los consagré exclusivamente al altruismo y al efecto hice mi primer testamento en 1894, legando a la sociedad de Valparaíso una Universidad, pero en el transcurso del tiempo, la experiencia me demostró que aquello era un error y que era de importancia capital levantar al proletario de mi patria, concibiendo un plan, por el cual contribuyo, primeramente con mi óbolo a la infancia, enseguida a la Escuela Primaria, de ella a la Escuela de Artes y Oficios y por último al Colegio de Ingenieros, poniendo al alcance del desvalido meritorio llegar al más alto grado del saber humano.
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define debug(x) cerr << #x << ": " << x << endl

typedef long long ll;

struct RollingHashing {
  ll p, m, ns;
  vector< ll > pows, hash;

  RollingHashing(string s, ll p_=53, ll m_=1e9 + 123) {
    // if WA then other p and other m
    // if still WA then double hashing
    // if still WA maybe is not the answer RH
    p = p_; m = m_;	
    ns = s.size();
    pows.resize(ns + 2);
    pows[0] = 1;
    for(int i = 1; i < ns + 2; i++) 
      pows[i] = (pows[i - 1] * p) % m;
  
    hash.resize(ns + 1);
    hash[0] = 0;
    for(int i = 1; i <= ns; i++) {
      ll char_to_num = s[i - 1] - 'a' + 1;  
      ll prev_hash = hash[i - 1];
      hash[i] = ((char_to_num * pows[i - 1]) % m + prev_hash) % m; 
    }
  }
  
  ll compute_hashing(ll i, ll j) {
    return (((hash[j] - hash[i - 1] + m) % m) * pows[ns - i] % m);
  }
};


int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  //int t = 1;
  //cin >> t;
  //while(t--) {
  int n;
  cin >> n;
  vector< vector< string > > table(n, vector< string >(n));
  vector< ll > lens(n);
  ll total_len = 0;
  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> table[i][j];
      if(i != j) {
        lens[i] += table[i][j].length();
      }
    }
    total_len += lens[i];
  }
  
  total_len /= 2 * n - 2;
  if(n > 2) {
    rep(i, 0, n) {
      lens[i] = (lens[i] - total_len) / (n - 2);
    }

    bool flag1 = true;
    rep(i, 0, n) {
      if(lens[i] < 1) {
        flag1 = false;
        break;
      }
      rep(j, 0, n) {
        if(i != j) {
          if(table[i][j].length() != lens[i] + lens[j]) {
            flag1 = false;
            break;
          }
        }
      }
      if(!flag1) break;
    }
    
    if(!flag1) {
      cout << "NONE\n";
    } else {
      vector< string > names(n);
      names[0] = table[0][1].substr(0, lens[0]);
      rep(i, 1, n) {
        names[i] = table[0][i].substr(lens[0]);
      }

      bool flag2 = true;
      rep(i, 0, n) {
        rep(j, 0, n) {
          if(i != j && names[i] + names[j] != table[i][j]) {
            flag2 = false;
            break;
          }
        }
        if(!flag2) break;
      }

      if(!flag2) {
        cout << "NONE\n";
      } else {
        cout << "UNIQUE\n";
        rep(i, 0, n) {
          cout << names[i] << "\n";
        }
      }
    }
  } else {
    if(table[0][1].length() != table[1][0].length()) {
      cout << "NONE\n";
    } else {
      RollingHashing h1(table[0][1]);
      RollingHashing h2(table[1][0]);

      bool flag3 = true;
      int pos_div = -1;
      int size = table[0][1].length();
      rep(i, 1, size) {
        /*
        debug(i);
        debug(h1.compute_hashing(1, i));
        debug(h2.compute_hashing(size - i + 1, size));
        debug(h1.compute_hashing(i + 1, size));
        debug(h2.compute_hashing(1, size - i));
        */
        if(h1.compute_hashing(1, i) == h2.compute_hashing(size - i + 1, size)) {
          if(h1.compute_hashing(i + 1, size) == h2.compute_hashing(1, size - i)) {
            if(pos_div != -1) {
              flag3 = false;
              break;
            }
            pos_div = i;
          }
        }
      }
      if(pos_div == -1) {
        cout << "NONE\n";
      } else if(!flag3) {
        cout << "MANY\n";
      } else {
        cout << "UNIQUE\n";
        cout << table[0][1].substr(0, pos_div) << "\n";
        cout << table[0][1].substr(pos_div) << "\n";
      }
    }
  }
  //}
  return 0;
}
