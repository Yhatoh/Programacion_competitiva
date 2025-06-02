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

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  ll t = 1;
  while(t--) {
    ll n;
    cin >> n;
    vector< pair< pair< ll, ll >, ll > > v(n);
    vector< ll > colors(n);
    fn(i, n) {
      cin >> v[i].first.first >> v[i].first.second;
      v[i].second = i;
    }

    sortv(v);

    priority_queue<pair< ll, ll >, vector< pair< ll, ll > >, greater< pair< ll, ll > > > pq;

    ll color = 1;
    pq.push({v[0].first.second, color});
    colors[v[0].second] = color++;
    flr(i, 1, n) {
      auto cust = v[i];
      auto top_pq = pq.top();
      if(top_pq.first >= cust.first.first) {
        colors[v[i].second] = color;
        pq.push({cust.first.second, color++});
      } else {
        colors[v[i].second] = pq.top().second;
        pq.pop();
        pq.push({cust.first.second, colors[v[i].second]});
      }
    }
    
    cout << --color << "\n";
    fn(i, n) {
      cout << colors[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
