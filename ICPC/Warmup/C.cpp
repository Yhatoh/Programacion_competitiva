#include<bits/stdc++.h>

using namespace std;


int main(){
	int n, x;
	cin >> n >> x;

	int counter = 0;
	int maxi = 0;
	int prev = -1;
	for(int i = 0; i < n; i++){
		int view;
		cin >> view;
		if(prev == -1){
			prev = view;
			counter++;
		} else {
			//cout << view << " " << prev << " " << counter << "\n";
			if(view - prev > x){
				if(counter > maxi){
					maxi = counter;
				}
				counter = 1;
			} else {
				counter++;
			}

			prev = view;
		}
	}

	if(counter > maxi) maxi = counter;
	cout << maxi << "\n";
	return 0;
}