
#include <bits/stdc++.h>
using namespace std;

int main(){
    long l, n, r = 1, s = 0;
    cin >> l >> n;

    while(l % n != 0){
        n -= l % n;
        r++;
    }
    cout << r << '\n';
    return 0;   
}
