#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;

	vector< pair< int, int > > activitie;
	for(int i = 0; i < n; i++){
		pair< int, int > dab;
		cin >> dab.first >> dab.second;
		activitie.push_back(dab);
	}

	sort(activitie.begin(), activitie.end());

	int wait = -1;
	int min_conflic = 100000;
	int min_time = 100000;
	for(int i = 0; i < 480; i++){
		int pointer = 0;
		int time = 0;
		int count = 0;
		for(int j = 0; j < n; j++){
			int begin = activitie[j].first;
			int end = activitie[j].second;
			if(begin <= i && begin + end <= i) continue;
			int newTime = ceil((begin - i) / x) * x;
			if(newTime == 0) newTime = x;
			if(newTime == begin) count++;
			else if(newTime <= begin + end) count++;

			int waiting = floor(end / x);

			if(newTime + waiting * x >  begin + end) count += waiting - 1;
			else if(newTime + waiting * x ==  begin + end) count += waiting;
		}

		//cout << count << "\n";
		if(min_conflic > count){
			min_conflic = count;
			min_time = i;
		}
	}

	cout << min_time << " " << min_conflic << "\n";
	return 0;
}