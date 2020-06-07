#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k1, k2;
	long long maxM, maxI;
	long long suma;
	cin >> n >> k1 >> k2;

	vector<long long> a(n);
	vector<long long> b(n);

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> pQueue;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	for(int i = 0; i < n; i++){
		pQueue.push(pair<long long, long long>((a[i] - b[i])*(a[i] - b[i]), i));
	}

	for(int i = 0; i < k1; i++){
		maxM = pQueue.top().first;
		maxI = pQueue.top().second;
		//cout << "K1\n";
		//cout << maxM << " " << maxI << "\n";
		//cout << a[maxI] << " " << b[maxI] << "\n";


		pQueue.pop();
		if(a[maxI] > b[maxI]) a[maxI]--;
		else a[maxI]++;
		pQueue.push(pair<long long, long long>((a[maxI] - b[maxI])*(a[maxI] - b[maxI]), maxI));
	}

	for(int i = 0; i < k2; i++){
		maxM = pQueue.top().first;
		maxI = pQueue.top().second;
		//cout << "K2\n";
		//cout << maxM << " " << maxI << "\n";
		//cout << a[maxI] << " " << b[maxI] << "\n";
		pQueue.pop();
		if(b[maxI] > a[maxI]) b[maxI]--;
		else b[maxI]++;
		pQueue.push(pair<long long, long long>((a[maxI] - b[maxI])*(a[maxI] - b[maxI]), maxI));
	}

	suma = 0;
	while(!pQueue.empty()){
		maxM = pQueue.top().first;
		suma += maxM;
		pQueue.pop();
	}
	cout << suma << "\n";
	return 0;
}