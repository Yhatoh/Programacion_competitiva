#include <bits/stdc++.h>
using namespace std;

int maxi(int a, int b) {
  if(a > b) return a;
  return b;
}

int main() {
  //ios_base::sync_with_stdio(false); 
  //cin.tie(NULL);
  //cout.setf(ios::fixed);
  //cout.precision(4);
  int n, x, i, xi;
  cin >> n >> x;
  int H[n + 1];
  int S[n + 1];

  for (i = 1; i <= n; i++) {
    cin >> H[i];
  }

  for (i = 1; i <= n; i++) {
    cin >> S[i];
  }

  int M[n + 1][x + 1];
  for (i = 0; i <= n; i++) {
    M[i][0] = 0;
  }

  for (xi = 1; xi <= x; xi++) {
    M[0][xi] = 0;
  }
  for (i = 1; i <= n; i++) {
    for (xi = 1; xi <= x; xi++) {
      int without_book = M[i-1][xi];
      if (xi - H[i] < 0) {
        M[i][xi] = without_book;
      } else {
        int with_book = S[i] + M[i-1][xi-H[i]];
        M[i][xi] = max(with_book, without_book);
      }
    }
  }

  cout << M[n][x] << endl;                
  return 0;
}
