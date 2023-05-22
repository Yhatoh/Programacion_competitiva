#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << endl

string s;
int n;

int get_node(int curr, int mod, int num) {
	return curr * n * 10 + mod * 10 + num;
}

int get_curr(int node) {
	return node / (n * 10);
}

int get_mod(int node) {
	return (node % (n * 10)) / 10;
}

int get_num(int node) {
	return node % 10;
}

void print(int node) {
	debug(node);
	debug(get_curr(node));
	debug(get_mod(node));
	debug(get_num(node));
	cerr << "-------------\n";
}

vector< vector< int > > G(1e7 + 2);
vector< int > path;
bool flag = false;

void DFS(int u, string ans) {
	if(flag) return;
	int curr = get_curr(u);
	//debug(ans);
	//print(u);
	if(curr + 1 == (int) s.size()) {
		int mod = get_mod(u);
		int num = get_num(u);
		if((mod * 10 + num) % n == 0) {
			flag = true;
			return;
		}
		return;
	}

	visited[u] = true;
	for(int v : G[u]) {
		if(!visited[v]) {
			path.push_back(v);
			/*if(n <= 10) ans  += ('0' + get_num(v));
			else {
				// nextmodulo = prevmodulo * 10 + x
				int nextmodulo = get_mod(v);
				int prevmodulo = 
			}*/
			DFS(v, ans);
			if(flag) return
			//ans.pop_back();
			path.pop_back()
		}
	}
}

int main() {
	cin >> s >> n;
			
	s.insert(0, "/");

// (modprev * 10 + numprev) % n
	int size_s = s.size();
	int initial_node = get_node(0, 0, 0);
	if(s[1] == '?') {
		for(int i = 1; i < 10; i++) {
			int next_node = get_node(1, 0, i);
			G[initial_node].push_back(next_node);
		}
	} else {
		int next_node = get_node(1, 0, s[1] - '0');
		G[initial_node].push_back(next_node);
	}

	for(int curr = 1; curr < size_s; curr++) {
		for(int mod = 0; mod < n; mod++) {

			if(s[curr] == '?') {
				if(mod > 10) {
					for(int i = (curr == 1); i < 10; i++) {
						int next_node = get_node(curr + 1, (mod * 10 + i) % n, 0);
						G[curr_node].push_back(next_node);
					}
				} else {
					for(int i = (curr == 1); i < 10; i++) {
						int curr_node = get_node(curr, mod, i);
						if(curr < size_s && s[curr + 1] == '?') {
							for(int j = 0; j < 10; j++) {
								int next_node = get_node(curr + 1, (mod * 10 + i) % n, j);
								G[curr_node].push_back(next_node);
							}
						} else if(curr < size_s) {
							int next_node = get_node(curr + 1, (mod * 10 + i) % n, s[curr + 1] - '0');
							G[curr_node].push_back(next_node);
						} else {
							int next_node = get_node(curr + 1, (mod * 10 + i) % n, 0);
							G[curr_node].push_back(next_node);
						}
					}
				}

			} else {
				if(mod > 10) {
					for(int i = (curr == 1); i < 10; i++) {
						int next_node = get_node(curr + 1, (mod * 10 + i) % n, 0);
						G[curr_node].push_back(next_node);
					}
				} else {
					int curr_node = get_node(curr, mod, s[curr] - '0');
					int num = s[curr] - '0';
					if(curr < size_s && s[curr + 1] == '?') {
						for(int j = 0; j < 10; j++) {
							int next_node = get_node(curr + 1, (mod * 10 + num) % n, j);
							G[curr_node].push_back(next_node);
						}
					} else if(curr < size_s) {
						int next_node = get_node(curr + 1, (mod * 10 + num) % n, s[curr + 1] - '0');
						G[curr_node].push_back(next_node);
					} else {
						int next_node = get_node(curr + 1, (mod * 10 + num) % n, 0);
						G[curr_node].push_back(next_node);
					}
				}
			}
		}
	}

	DFS(initial_node, "");
	cout << "*\n";
	return 0;
}