#include<bits/stdc++.h>

using namespace std;

typedef vector< vector< char > >  matrix;

void degree90(matrix &m1, matrix &m2){
	int n = m1.size();
	int i, j;
	for(i = 0; i < n / 2; i++){
		for(j = i; j < n - i - 1; j++){
			m2[i][j] = m1[j][n - 1 - i];
			m2[j][n - 1 - i] = m1[n - 1 - i][n - 1 - j];
			m2[n - 1 - i][n - 1 - j] = m1[n - 1 - j][i];
			m2[n - 1 - j][i] = m1[i][j];
		}
	}
}

int check(matrix &m){
	int maxSide, acum, i, j, k, l;
	maxSide = 0;
	acum = 0;
	int notS;
	for(l = 0; l < (int) m.size(); l++){
		for(i = 1; i <= (int) m.size() - l; i++){
			notS = 0;
			for(j = 0; j < i; j++){
				for(k = 0; k < i; k++){
					if(m[j][k + l] == 'C'){
						notS = 1;
						break;
					}
				}
				if(notS) break;
			}
			if(notS == 0 && maxSide < i){
				maxSide = i;
			}
		}
	}
	return maxSide;
}

int main(){
	
	int n, i, j;
	cin >> n;
	matrix bricks1(n);
	matrix bricks2(n);
	matrix bricks3(n);
	matrix bricks4(n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			bricks1[i].push_back('-');
			bricks2[i].push_back('-');
			bricks3[i].push_back('-');
			bricks4[i].push_back('-');
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			char brick;
			cin >> brick;
			bricks1[i][j] = brick;
		}
	}

	degree90(bricks1, bricks2);
	degree90(bricks2, bricks3);
	degree90(bricks3, bricks4);

	stack< char > s1;
	stack< char > s2;
	stack< char > s3;
	stack< char > s4;

	for(j = 0; j < n; j++){
		for(i = 0; i < n; i++){
			if(bricks1[i][j] == 'C')
				s1.push('C');
			if(bricks2[i][j] == 'C')
				s2.push('C');
			if(bricks3[i][j] == 'C')
				s3.push('C');
			if(bricks4[i][j] == 'C')
				s4.push('C');
			bricks1[i][j] = '-';
			bricks2[i][j] = '-';
			bricks3[i][j] = '-';
			bricks4[i][j] = '-';
		}
		i = n - 1;

		while(!s1.empty() || !s2.empty() || !s3.empty() || !s4.empty()){
			if(!s1.empty()){
				bricks1[i][j] = 'C';
				s1.pop();
			}
			if(!s2.empty()){
				bricks2[i][j] = 'C';
				s2.pop();
			}
			if(!s3.empty()){
				bricks3[i][j] = 'C';
				s3.pop();
			}
			if(!s4.empty()){
				bricks4[i][j] = 'C';
				s4.pop();
			}
			i--;
		}
	}

	int max = 0;

	int cand = check(bricks1);
	max = (max < cand ? cand : max );
	cand = check(bricks2);
	max = (max < cand ? cand : max );
	cand = check(bricks3);
	max = (max < cand ? cand : max );
	cand = check(bricks4);
	max = (max < cand ? cand : max );
	
	cout << max;
	return 0;
}