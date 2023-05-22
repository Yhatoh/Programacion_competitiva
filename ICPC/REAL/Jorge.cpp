#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(2);

    int a,b,c,d,e,f,g,h,q,l; 
    cin >> a;
    b = -1;
    d = 0;
    vector<int> v(a,0);
    vector< pair<int,int>> p;
    for (int i = 0; i < a; i++)
    {
        cin >> c;
        d = d + c;
        if(c > v[b]) b=i;
        v[i] = c;
    }
    e = d/a;
    c = 0;
    l = 0;
    f = v[b] - e;
    if (f >0)
    {
        h = 1;
        g = b;
        while(1){
            cout << "c; " << c << endl;
            g++;
            if(g == a){
                g = 0;
            }
            if (g == b) break;
            if(e >= v[g])
            {
                if (p.size() < 1)c = c + h * (e-v[g]);
                else{
                    if(p[-1].first > e-v[g]){
                        c = c+ p[-1].second*e-v[g];
                        p[-1].first = p[-1].first - (e-v[g]);
                    }
                    else if (p[-1].first == e-v[g]){
                        c = c+ p[-1].second*e-v[g];
                        p.pop_back();
                    }
                    else{
                        q  = e-v[g];
                        while(q > 0){
                            cout << "q :" <<q << " en h: " << h << endl;
                            if(p[-1].first <= q){
                                q = q - p[-1].first;
                                c = c+ p[-1].second*p[-1].first;
                                p.pop_back();
                            }
                            else{
                                p[-1].first = p[-1].first - q;
                                c = c+ p[-1].second*q;
                                q = 0;
                            }
                            if(p.size() == 0)break;
                        }
                        if(q > 0){
                            c = c+ h*q;
                        }
                    }
                }
            }

            else if(e < v[g]){
                cout <<" resta " << v[g] << " - " << e<< endl;
                p.push_back(make_pair(v[g]-e,h));
            }
            h++;
        }
        l = c;
        c = 0;
        h = 1;
        g = b;
        while(1){
            cout << "c; " << c << endl;
            g--;
            if(g == 0){
                g = a-1;
            }
            if (g == b) break;
            if(e >= v[g])
            {
                if (p.size() < 1)c = c + h * (e-v[g]);
                else{
                    if(p[-1].first > e-v[g]){
                        c = c+ p[-1].second*e-v[g];
                        p[-1].first = p[-1].first - (e-v[g]);
                    }
                    else if (p[-1].first == e-v[g]){
                        c = c+ p[-1].second*e-v[g];
                        p.pop_back();
                    }
                    else{
                        q  = e-v[g];
                        while(q > 0){
                            cout << "q :" <<q << " en h: " << h << endl;
                            if(p[-1].first <= q){
                                q = q - p[-1].first;
                                c = c+ p[-1].second*p[-1].first;
                                p.pop_back();
                            }
                            else{
                                p[-1].first = p[-1].first - q;
                                c = c+ p[-1].second*q;
                                q = 0;
                            }
                            if(p.size() == 0)break;
                        }
                        if(q > 0){
                            c = c+ h*q;
                        }
                    }
                }
            }

            else if(e < v[g]){
                cout <<" resta " << v[g] << " - " << e<< endl;
                p.push_back(make_pair(v[g]-e,h));
            }
            h++;
        }
    }
    if(c < l){
        cout << c << endl;
    }
    else if(c >= l){
        cout << l << endl;
    }


    return 0;
}