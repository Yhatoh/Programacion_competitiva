#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	int t, n, m, x, y, i, j, cant1x2, cantPoint, hayPuntoAntes;
	char tile;

	cin >> t;
	while(t--){
		cin >> n >> m >> x >> y;

		
		cantPoint = 0;
		cant1x2 = 0;

		for(i = 0; i < n; i++){
			hayPuntoAntes = 0;
			for(j = 0; j < m; j++){
				cin >> tile;
				if(tile == '.' && hayPuntoAntes == 0){
					hayPuntoAntes = 1;
					cantPoint++;
				}
				else if(tile == '.' && hayPuntoAntes == 1){
					cant1x2++;
					hayPuntoAntes = 0;
					cantPoint++;
				}
				else if(tile == '*') hayPuntoAntes = 0;
			}
		}
		if(cantPoint * x <= (cantPoint - 2 * cant1x2) * x + cant1x2 * y) 
			cout << cantPoint * x << "\n";
		else 
			cout << (cantPoint - 2 * cant1x2) * x + cant1x2 * y << "\n";	
	}
	return 0;
}