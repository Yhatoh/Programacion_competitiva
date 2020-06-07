#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int* p1 = new int[2000000];
    int* p2 = new int[2000000];
    
    p1[0] = p1[1] = 0;
    for (int i = 2; i < 5000000; i++) p1[i] = 1;
    for (int i = 2; i <= 5000000 - 1; i++)
        for (int j = 2 * i; j < 5000000; j += i)
            p1[j] = 0;

    int n, k; cin >> n >> k;


    p2[0] = p2[1] = 0;
    for (int i = 2; i < 5000000; i++) p2[i] = 1;
    for (int i = 2; i <= n - 1; i++)
        for (int j = 2 * i; j < 5000000; j += i)
            p2[j] = 0;

    int a = 0, r = -1;
    for (int i=0; i<5000000; i++) {

        if (p2[i] && !p1[i])
            a++;

        if (a == k) {
            r = i;
            break;
        }
    }

    cout << r << endl;

    free(p1);
    free(p2);
    return 0;
}