#include <bits/stdc++.h>
using namespace std;
 
typedef pair< int, int > pii;
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);

  int n;
  cin >> n;
  vector< int > h(1000002, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(h[x + 1]) h[x + 1]--;
    h[x]++;
  }

  int ans = 0;
  for(int i = 0; i < 1000002; i++) ans += h[i];

  cout << ans << "\n";
  return 0;
}
