#include<bits/stdc++.h>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int maxi = 0;
vi listNodeMax;
int actual;
vi listNode;

vi visited;
vi funds;
vvi graph;

void dfs(int nodoActual){
	listNode.push_back(nodoActual);
    visited[nodoActual] = 1;
    actual += funds[nodoActual];
    //adjlist[nodoActual].size() cuantos vecinos tiene el nodo actual
    for(int i = 0; i < (int) graph[nodoActual].size(); i++){
        int vecino = graph[nodoActual][i];
        if(visited[vecino] == 0){
            dfs(vecino);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	

	int n, p, i;
	cin >> n;

	funds.assign(n + 1, 0);
	visited.assign(n + 1, 0);
	graph.assign(n + 1, vi());
	for(i = 0; i < n; i++){
		cin >> funds[i];
	}

	cin >> p;

	for(i = 0; i < p; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
        if(visited[i] == 0){
        	actual = 0;
        	listNode.clear();
            dfs(i);
            if(actual > maxi){
            	maxi = actual;
            	listNodeMax.assign(listNode.size(), 0);
            	copy(listNode.begin(), listNode.end(), listNodeMax.begin());
            } else if(actual == maxi && listNodeMax.size() > listNode.size()){
            	maxi = actual;
            	listNodeMax.assign(listNode.size(), 0);
            	copy(listNode.begin(), listNode.end(), listNodeMax.begin());
            }
        }
    }

    sort(listNodeMax.begin(), listNodeMax.end());
    for(i = 0; i < (int) listNodeMax.size() - 1; i++){
    	cout << listNodeMax[i] + 1 << " ";
    }
    cout << listNodeMax[i] + 1;
	return 0;
}