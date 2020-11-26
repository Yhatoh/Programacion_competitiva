#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, h, i, c, posCrane, boxCrane;
	cin >> n >> h;
	vector< long long > boxes(n);

	for(i = 0; i < n; i++)
		cin >> boxes[i];

	cin >> c;

	posCrane = 0;
	boxCrane = 0;

	while(c != 0){
		if(c == 1 && posCrane > 0){
			posCrane--;
		} else if(c == 2 && posCrane < n - 1) {
			posCrane++;
		} else if(c == 3 && boxes[posCrane] > 0 && boxCrane == 0) {
			boxCrane++;
			boxes[posCrane]--;
		} else if(c == 4 && boxCrane > 0 && boxes[posCrane] < h) {	
			boxCrane--;
			boxes[posCrane]++;
		}
		/*
		cout << "comand " << c << " pos " << posCrane << "\n";
		for(i = 0; i < n - 1; i++)
			cout << boxes[i] << " ";

		cout << boxes[i] << "\n";
		*/
		cin >> c;
	}

	for(i = 0; i < n - 1; i++)
		cout << boxes[i] << " ";

	cout << boxes[i] << "\n";


	return 0;
}