#include <bits/stdc++.h>
using namespace std;

#define DBG(var) cout << #var << " = " << var << "\n";
#define fn(i,n) for(int i = 0; i < n; i++)
#define flr(i,l,r) for(int i = l; i < r; i++)
#define flre(i,l,r) for(int i = l; i <= r; i++)
#define frl(i,l,r) for(int i = r; i > l; i--)
#define frle(i,l,r) for(int i = r; i >= l; i--)
#define sortv(vec) sort(vec.begin(), vec.end())

typedef vector< int > vi; typedef vector< vi > vvi;
typedef pair< int, int > pii; typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef long long ll; typedef vector< ll > vll;
typedef vector< vll > vvll; typedef pair< ll, ll > pll;
typedef vector< pll > vpll; typedef vector< vpll > vvpll;

void bfs(int n, int m, int x, int y, vvi &vis, vvi &islands, int h) {
  queue< pii > q;
  q.push({x, y});
  vis[x][y] = 1;
  while(!q.empty()) {
    pii act = q.front();
    q.pop();
    int ax, ay;
    ax = act.first;
    ay = act.second;
    if(ax > 0 && islands[ax - 1][ay] <= h && vis[ax - 1][ay] == 0) {
      vis[ax - 1][ay] = 1;
      q.push({ax - 1, ay});
    }
    if(ay > 0 && islands[ax][ay - 1] <= h && vis[ax][ay - 1] == 0) {
      vis[ax][ay - 1] = 1;
      q.push({ax, ay - 1});
    }
    if(ax < m - 1 && islands[ax + 1][ay] <= h && vis[ax + 1][ay] == 0) {
      vis[ax + 1][ay] = 1;
      q.push({ax + 1, ay});
    }
    if(ay < n - 1 && islands[ax][ay + 1] <= h && vis[ax][ay + 1] == 0) {
      vis[ax][ay + 1] = 1;
      q.push({ax, ay + 1});
    }
  }
}

void bfs2(int n, int m, int x, int y, vvi &vis, vvi &islands, int h) {
  queue< pii > q;
  q.push({x, y});
  vis[x][y] = 1;
  while(!q.empty()) {
    pii act = q.front();
    q.pop();
    int ax, ay;
    ax = act.first;
    ay = act.second;
    if(ax > 0 && islands[ax - 1][ay] == h && vis[ax - 1][ay] == 0) {
      vis[ax - 1][ay] = 1;
      q.push({ax - 1, ay});
    }
    if(ay > 0 && islands[ax][ay - 1] == h && vis[ax][ay - 1] == 0) {
      vis[ax][ay - 1] = 1;
      q.push({ax, ay - 1});
    }
    if(ax < m - 1 && islands[ax + 1][ay] == h && vis[ax + 1][ay] == 0) {
      vis[ax + 1][ay] = 1;
      q.push({ax + 1, ay});
    }
    if(ay < n - 1 && islands[ax][ay + 1] == h && vis[ax][ay + 1] == 0) {
      vis[ax][ay + 1] = 1;
      q.push({ax, ay + 1});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(4);
  int t = 1;
  while(t--) {
    int m, n;
    cin >> m >> n;
    vvi islands(m, vi(n, 0));
    vvi vis(m, vi(n, 0));
    fn(i, m) fn(j, n) cin >> islands[i][j];
    int x, y;
    cin >> x >> y;
    int h;
    cin >> h;
    if(islands[x][y] != 0) {
      cout << "NONE";
      break;
    }
    
    bfs(n, m, x, y, vis, islands, h);
    
    vvi vis2(m, vi(n, 0));
    int ans = 0;
    fn(i, m) {
      fn(j, n) {
        if(vis[i][j] == 1 && vis2[i][j] == 0 && islands[i][j] != 0) {
          bfs2(n, m, i, j, vis2, islands, islands[i][j]);
          ans++;
        }
      }
    }
    if(ans)
      cout << ans; 
    else cout << "NONE";
  }
  return 0;
}
