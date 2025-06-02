#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef long long ll;

#define INF 1000000007

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

int LSB(int n) { return n & -n; }

template< class T >
struct FenwickTreeOP {
  vector< T > arr;
  vector< T > bit1;
  vector< T > bit2;
  int n;

  FenwickTreeOP(vector< T > &v) : n(v.size() - 1) {
    arr.assign(n + 2, 0);
    bit1.assign(n + 2, 0);
    bit2.assign(n + 2, 0);
    for(ll i = 1; i <= n; i++) {
      update(i, v[i]);
    }
  }

  ll query(int l, int r) {
    int idx_l = l;
    int idx_r = r;

    ll ret = 0;
    while(idx_l + LSB(idx_l) <= r) {
      ret += bit2[idx_l];
      idx_l = idx_l + LSB(idx_l);
    }
    ret += arr[idx_l];

    while(idx_r - LSB(idx_r) >= l) {
      ret += bit1[idx_r];
      idx_r = idx_r - LSB(idx_r);
    }

    return ret;
  }

  void update(int idx, ll delta) {
    arr[idx] += delta;

    int idx_bit1 = idx;
    ll v = delta;
    while(idx_bit1 <= n) {
      bit1[idx_bit1] += v;
      idx_bit1 += LSB(idx_bit1);
    }

    int idx_bit2 = idx;
    v = delta;
    while(idx_bit2 > 0) {
      bit2[idx_bit2] += v;
      idx_bit2 -= LSB(idx_bit2);
    }
  }
};

ll child(ll n) { return n & (n + 1); }
ll parent(ll n) { return n | (n + 1); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    ll n, q;
    cin >> n >> q;
    vector< ll > nums(n + 1);
    fn(i, n) cin >> nums[i + 1];

    FenwickTreeOP< ll > f(nums);

    while(q--) {
      ll op, a, b;
      cin >> op >> a >> b;
      if(op == 2) {
        cout << f.query(a, b) << "\n";
      } else {
        f.update(a, -f.query(a, a));
        f.update(a, b);
      }
    }
  }
  return 0;
}
