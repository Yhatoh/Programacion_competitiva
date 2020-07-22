#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int routes, stops, stop, i, j, start, end, temp, suma, maxSum;
	cin >> routes;
	j = 0;
	while(routes > j){
		cin >> stops;
		suma = maxSum = 0;
		start = 0xffff;
		temp = 1;

		for(i = 2; i <= stops; i++){
			cin >> stop;
			suma += stop;
			if(suma < 0){
				temp = i;
				suma = 0;
			}
			if(suma > maxSum || (suma == maxSum && (i - temp > end - start))){
				start = temp;
				end = i;
			}
			maxSum = max(maxSum, suma);
		}
		j++;
		if(maxSum > 0) cout << "The nicest part of route " << j << " is between stops " << start << " and " << end << "\n";
		else cout << "Route " << j << " has no nice parts\n";
	}
	return 0;
}