#include<bits/stdc++.h>

using namespace std;
typedef map< int, vector <int> > graph;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
    double a,b,c,d,e,f,g;
    cin >> a >> b;
    while(a != 0){
        if(a <= b){
            cout << 0 << "\n";
        }
        else{
            c = 1; 
            d = 0;
            f = 0;
            g = 0;
            while(c <= a){
                e = 0.3*sqrt(a/c-b);
                e = e*c;
                if(e > f){
                    if(abs(f-e) <= 1e-12) g++;
                    else{
                        f = e;
                        d = c;
                        g = 0;
                    }
                }
                else if(e == f){
                    g++;
                }
                c++;
            }
            if(g < 1) cout << (int) d << "\n";
            else cout << 0 << "\n";
        }
        cin >> a >> b;
    }
    return 0;
}