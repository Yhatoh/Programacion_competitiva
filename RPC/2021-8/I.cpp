#include<bits/stdc++.h>
using namespace std;
 

vector< long long > facts(2010, -1);
vector< bool > isPrime(2010, false);

// Generate all prime numbers less than n.
void SieveOfEratosthenes(long long n){
    // Initialize all entries of boolean array
    // as true. A value in isPrime[i] will finally
    // be false if i is Not a prime, else true
    // bool isPrime[n+1];
    isPrime[0] = isPrime[1] = false;
    for (long long i=2; i<=n; i++)
        isPrime[i] = true;
 
    for (long long p=2; p*p<=n; p++){
        // If isPrime[p] is not changed, then it is
        // a prime
        if (isPrime[p] == true){
            // Update all multiples of p
            for (long long i=p*p; i<=n; i += p)
                isPrime[i] = false;
        }
    }
}
 
long long factorial(long long n, long long c){
    //n = 6
    //c = 2
    //6 5 4 3 2 1
    // 2 1
    long long value = 1;
    for(long long i = n; i > c; i--){
        value = (value * i) % (1000000007);
    }
    return value;
}
// Prlong longs a prime pair with given sum
long long findPrimePair(long long n){
 
    // Traversing all numbers to find first
    // pair
    if(facts[n] == -1){
        long long total = 0;
        for (long long i=0; i<n; i++){
            if (isPrime[i] && isPrime[n-i]){
                long long maxi = max(i, n - i);
                long long mini = min(i, n - i);
                total = (total +  factorial(n, maxi) / factorial(mini, 1)) % (1000000007);
            }
        }

        facts[n] = total;
    }

    return facts[n];
}

int main(){
    SieveOfEratosthenes(2000);
    int Q;
    cin >> Q;
    while(Q--){
        int X, Y;
        cin >> X >> Y;
        long long result = 0;
        for(long long i = X; i <= Y; i++){
            result = (result + findPrimePair(i)) % (1000000007);
        }
        cout << result << "\n";
    }
}