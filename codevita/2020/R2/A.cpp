#include<bits/stdc++.h>
using namespace std;

int train(int n){
    if(n == 0) return 1;

    int total = 0;
    if(n % 2 == 0) total += train(n - 2);

    if(n % 3 == 0) total += train(n - 3);

    total += train(n - 1);
    return total;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);

	int t, n, i;
    cin >> t;
    vector< long long > cases(101, -1);
    while(t--){
        cin >> n;
        n++;
        cases[0] = 1;
        if(cases[n] == -1){
            for(i = 1; i <= n; i++){
                cases[i] = cases[i - 1];
                if(i >= 2) cases[i] += cases[i - 2];
                if(i >= 3) cases[i] += cases[i - 3];
            }
        }

        if(t != 0)
            cout << cases[n] << "\n";
        else
            cout << cases[n];
    }

	return 0;
}