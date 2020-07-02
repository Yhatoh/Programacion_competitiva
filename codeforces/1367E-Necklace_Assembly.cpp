#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    int t, n, k, i, j, cant, lenMax;
    char l;
    cin >> t;
    string s;
    while(t--){
        lenMax = -1;
        cin >> n >> k >> s;
        map< char, int > apariciones;
        for(i = 0; i < s.length(); i++) apariciones[s[i]]++;

        for(i = 1; i <= n; i++){
            if(k % i == 0){
                for(j = 1; j * i <= n; j++){
                    cant = 0;
                    for(l = 'a'; l <= 'z'; l++)
                        cant += apariciones[l] / j;

                    if(cant >= i && lenMax < i * j)
                        lenMax = i * j;
                    
                }
            }
        }
        cout << lenMax << "\n";
    }    
}