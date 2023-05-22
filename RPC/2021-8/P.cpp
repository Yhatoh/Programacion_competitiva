#include<bits/stdc++.h>
using namespace std;

void changeBird(vector< vector< int > > &grid, int i, int j, int* count){
	if(grid[i][j] == 1){
		(*count)++;
		grid[i][j] = 0;
	}
}

int main(){
	int f, c, p;
	cin >> f >> c >> p;

	vector< vector< int > > grid(f);

	for (int i = 0; i < f; ++i){
		for (int j = 0; j < c; ++j){
			int num;
			cin >> num;
			grid[i].push_back(num);
		}
	}

	int total = 0;
	for (int i = 0; i < p; ++i){
		int a, b;
		//a -> filas
		//b -> columnas
		cin >> a >> b;
		a--;
		b--;

		//arriba izquierda
		if(a > 0 && b > 0){
			changeBird(grid, a - 1, b - 1, &total);
		}

		//arriba
		if(a > 0){
			changeBird(grid, a - 1, b, &total);
		}

		//arriba derecha
		if(a > 0 && b < c - 1){
			changeBird(grid, a - 1, b + 1, &total);
		}

		//media izquierda
		if(b > 0){
			changeBird(grid, a, b - 1, &total);
		}

		//media derecha
		if(b < c - 1){
			changeBird(grid, a, b + 1, &total);
		}

		//abajo izquierda
		if(a < f - 1 && b > 0){
			changeBird(grid, a + 1, b - 1, &total);
		}

		//abajo
		if(a < f - 1){
			changeBird(grid, a + 1, b, &total);
		}

		//abajo derecha
		if(a < f - 1 && b < c - 1){
			changeBird(grid, a + 1, b + 1, &total);
		}

		changeBird(grid, a, b, &total);
	}

	cout << total << "\n";
}
