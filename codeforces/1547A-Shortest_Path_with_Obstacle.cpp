#include<bits/stdc++.h>

using namespace std;

bool entremedio(int a, int b, int c) {
	if(c <= a && c >= b){
		return true;
	}

	if(c <= b && c >= a){
		return true;
	}

	return false;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(2);
	int t, xA, yA, xB, yB, xF, yF;
	cin >> t;
	while(t--){
		cin >> xA >> yA;
		cin >> xB >> yB;
		cin >> xF >> yF;

		int chebyX, chebyY;

		chebyX = abs(xB - xA);
		chebyY = abs(yB - yA);

		if(yA == yB && yF == yA && entremedio(xA, xB, xF)){
			cout << chebyX + chebyY + 2 << "\n";
		} else if(xA == xB && xA == xF && entremedio(yA, yB, yF)){
			cout << chebyX + chebyY + 2 << "\n";
		} else {
			cout << chebyX + chebyY << "\n";
		}
	}
	return 0;
}