#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< ll > save;

ll sumOfMaxs (vector< ll > &array, ll n, ll begin, ll end){
	if(begin == end){
		return array[begin];
	} 

	ll mid, max, sum, ans, pos;
	
	mid = (begin + end) / 2;
	max = sum = ans = 0;
	
	ans += sumOfMaxs(array, n, begin, mid);
	ans += sumOfMaxs(array, n, mid + 1, end);

	//buscar los minimos de arreglos
	//que se componen entre la mitdad de la izqueierda 
	//y la mitad de derecha
	for(ll k = mid + 1; k <= end; k++){
		if(max < array[k]){
			max = array[k];
		}
		save[k] = max;
		sum += max;
	}

	max = 0;
	pos = mid + 1;

	for(ll k = mid; k >= begin; k--){
		if(max < array[k]){
			max = array[k];
		}
		while(pos <= end && save[pos] <= max){
			sum -= save[pos];
			pos++;
		}
		ans += sum + (pos - mid - 1) * max;
	}

	return ans;
}

ll sumOfMins (vector< ll > &array, ll n, ll begin, ll end){
	if(begin == end){
		return array[begin];
	} 

	ll mid, min, sum, ans, pos;
	
	mid = (begin + end) / 2;
	min = 1000000007;
	sum = ans = 0;
	
	ans += sumOfMins(array, n, begin, mid);
	ans += sumOfMins(array, n, mid + 1, end);

	//buscar los minimos de arreglos
	//que se componen entre la mitdad de la izqueierda 
	//y la mitad de derecha
	for(ll k = mid + 1; k <= end; k++){
		if(min > array[k]){
			min = array[k];
		}
		save[k] = min;
		sum += min;
	}

	min = 1000000007;
	pos = mid + 1;

	for(ll k = mid; k >= begin; k--){
		if(min > array[k]){
			min = array[k];
		}
		while(pos <= end && save[pos] >= min){
			sum -= save[pos];
			pos++;
		}
		ans += sum + (pos - mid - 1) * min;
	}

	return ans;
}

int main(){
	ll n;

	cin >> n;
	vector< ll > array(n);
	for(ll i = 0; i < n; i++){
		cin >> array[i];
		save.push_back(0);
	}

	save.push_back(0);
	save.push_back(0);

	cout << sumOfMaxs(array, n,  0, n - 1) - sumOfMins(array, n, 0, n - 1) << "\n";
	
	return 0;
}