#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int n, q, i, type, xOt, ans, j, x;
	cin >> n >> q;
	vector< int > marks(q + 1, 0);
	vector< queue< int > > e(n + 1);
	queue< pair< int, int > > Q;
	ans = i = 0;
	while(q--){
		cin >> type >> xOt;
		if(type == 1){
			ans++;
			i++;
			Q.push(pair< int, int >(i, xOt));
			e[xOt].push(i);
		}
		else if(type == 2){
			ans = ans - (!e[xOt].empty() ? e[xOt].size() : 0);
			while(!e[xOt].empty()){
				marks[e[xOt].front()] = 1;
				e[xOt].pop();
			}
		}
		else{
			while(!Q.empty() && Q.front().first <= xOt){
				j = Q.front().first;
				x = Q.front().second;
				Q.pop();
				if (marks[j] == 0){
					marks[j] = 1;
					e[x].pop();
					ans = ans - 1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}