#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, i, ans, counter, pos;
    cin >> n;
    vector< long long > nums(n);
    for(i = 0; i < n; i++){
    	cin >> nums[i];
    }
    set< long long > vis;
    vector< long long > datos(n, 0);
    counter = 0;

    for(i = n - 1; i > 0; i--){
    	if(vis.find(nums[i]) != vis.end()){
    		datos[i - 1] = counter;
    	} else {
    		counter++;
    		datos[i - 1] = counter;
    	}
    	vis.insert(nums[i]);
    }

    vis.clear();
    ans = 0;
    for(i = 0; i < n - 1; i++){
    	if(vis.find(nums[i]) == vis.end()){
    		ans += datos[i];
    		vis.insert(nums[i]);
    	}
    }

    cout << ans << "\n";
    return 0;
}