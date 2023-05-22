#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, i, j, k;

    cin >> n;
    string word;
    cin >> word;

    vector< pair< string, pair< int, int > > > results;
    vector< string > otherResult;
    for(i = 0; i < (int) word.length(); i++){
        string substring = "";
        for(j = i; j < (int) word.length(); j++){
            if(substring.find(word[j]) != string::npos)
                break;
            substring.append(1, word[j]);
        }
        int booli = 1;
        if(j < (int) word.length() && word[j] == substring[0] && results.size() > 0){
            booli = 0;
        }
        if(booli){
            for(k = 0; k < (int) results.size(); k++){
                if(results[k].first.find(substring) != string::npos){
                    if(results[k].second.first <= i && j - 1 <= results[k].second.second){
                        booli = 0;
                        break;
                    }
                }
            }
        }
        if(booli){
            results.push_back(pair< string, pair< int, int > >(substring, pair< int, int >(i, j - 1)));
            otherResult.push_back(substring);
        }
    }

    sort(otherResult.begin(), otherResult.end());
    for(i = 0; i < (int) otherResult.size() - 1; i++){
        cout << otherResult[i] << " ";
    }
    cout << otherResult[i];
	return 0;
}