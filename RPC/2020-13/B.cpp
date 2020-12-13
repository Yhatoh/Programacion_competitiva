#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        long long res = a % b;
        if(res == 0) cout << "0\n";
        else cout << b - res << "\n";
    }
    return 0;
}