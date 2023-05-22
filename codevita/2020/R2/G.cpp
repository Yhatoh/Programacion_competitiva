#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< pair< ll, ll > > vd;


void recursive(vd &prices, ll k, ll a, ll acum, ll maxResult){
    ll maxElementIndex = prices.size() - 1; 
    ll maxCostElement = prices[maxElementIndex].second;

    ll i;
    for(i = 0; i < k; i++){
        if(a > acum && a >= acum + maxCostElement){
            acum += maxCostElement;
            maxResult += (((maxCostElement * prices[maxElementIndex].first)) / 100.0);
        } else {
            cout << (ll) round(round((double) maxResult / 100.0)) / 100;
            return;
        }
    }

    prices.pop_back();
    recursive(prices, k, a, acum, maxResult);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    long long A, K, N, i;
    cin >> N >> K >> A;
    vd prices(N);

    for(i = 0; i < N; i++){
        double a;
        cin >> a;
        prices[i].second = a * 100;
    }
    for(i = 0; i < N; i++){
        double a;
        cin >> a;
        prices[i].first = a * 100;
    }
    A *= 100;
    sort(prices.begin(), prices.end());
    ll maxResult = 0;
    recursive(prices, K, A, 0, maxResult);
	return 0;
}