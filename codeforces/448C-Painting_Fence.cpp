#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001;
vector< long long > fence;

long long painting(int l, int r){
	if(l > r) return 0;
	int i, min, minI;
	long long strokes, div1, div2;

	min = INF;
	for(i = l; i < r + 1; i++){
		if(min > fence[i]){
			minI = i;
			min = fence[i];
		}
	}

	strokes = min;
	for(i = l; i < r + 1; i++) fence[i] -= strokes;

	div1 = painting(l, minI - 1);
	div2 = painting(minI + 1, r);

	if(div1 + div2 + strokes < r - l + 1) return div1 + div2 + strokes;
	else return r - l + 1;
}

int main(){
	int n, i, j;
	cin >> n;
	
	for(i = 1; i <= n; i++){
		cin >> j;
		fence.push_back(j);
	}

	cout << painting(0, n - 1) << "\n";
	return 0;
}