#include<bits/stdc++.h>

using namespace std;

void print(vector<vector <int>>v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
}

void print2(vector<int>v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        
    }
     cout << endl;    
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);

    int n,k,a,b,c,d,f;
    char x;
    vector <vector <int>> v;
    cin >> n >> k;
    vector< int > vivos(100004, 0);
    for (int i = 0; i < n; i++){
        cin >> x;
        if(x == 'C'){
            vector <int> m(k,0);
            cin >> c;
            for (int j = 0; j < c; j++)
            {
                cin >> d;
                m[d-1] ++;
            }
            v.push_back(m);
            
        }
        else if (x == 'D'){
            cin >> c;
            vivos[c-1] = 1;
            //v[c-1].clear();
        }

        else{
            vector <int> m(k,0);
            cin >> c;
            for (int j = 0; j < c; j++)
            {
                cin >> d;
                m[d-1] ++;
            }
            b = 0;
            for (int j = 0; j < v.size(); j++)
            {
                f = 1;
                if(vivos[j] == 0){
                    
                    for (int z = 0; z < k; z++)
                    {
                        
                        if(v[j][z] < m[z]){
                            f = 0;
                            break;
                        }
                    }
                    if(f){
                        b +=1;
                    }
                }
            }
            cout << b << endl;
        }
    }
    
    return 0;
}