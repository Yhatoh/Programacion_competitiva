#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4); 
	long long t, n, sqrtN, x, y;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1) cout << "0 0\n";
        else{
            sqrtN = sqrt(n - 1);
            if(sqrtN % 2 == 0) x = sqrtN - n + 1 + sqrtN * sqrtN;
            else x = - sqrtN + n - 1 - sqrtN * sqrtN;

            y = 0 - sqrtN / 2;
            if(sqrtN % 2 != 0){
                if(n - 1 - sqrtN * sqrtN <= (2 * sqrtN + 1) / 2) 
                    y += n - 1 - sqrtN * sqrtN;
                else 
                    y += (2 * sqrtN + 1) / 2 - (n - 1 - sqrtN * sqrtN - (2 * sqrtN + 1) / 2);
            }
            cout << x << " " << y << "\n";
        }
    }
    return 0; 
} 
