#include<bits/stdc++.h>
using namespace std;

struct persona {
    int p_, llego_;
    string name_;


    persona(int p, int llego, string name) : name_(name), p_(p), llego_(llego) {}

    bool operator<(const persona& p1) const {
        if(p_ != p1.p_) return p_ < p1.p_;
        return llego_ > p1.llego_;
    }
};

int main() {
    
    priority_queue< persona > v1;
    int n;
    string a;

    int iter = 0;
    while(cin >> a) {
        if (a == "V") {
            if (v1.size() == 0) {
                cout << endl;
                continue;
            }
            cout << v1.top().name_ << endl;
            v1.pop();
        } else {
            cin >> n;
            v1.push(persona(n, iter++, a));
        }
    }

    return 0;
}
