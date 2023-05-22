#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define bit(x,i) (x&(1<<i))

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector< int > nums(m + 1);
    fn(i, m + 1) {
      cin >> nums[i];
    }

    int ans = 0;
    frle(i, 0, m - 1) {
      int differ = 0;
      fn(j, 20) {
        if(bit(nums[m], j) ^ bit(nums[i], j)) {
          differ++;
        }
      }
      if(differ <= k) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
