#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl

template< typename T >
ostream& operator<<(ostream& os, const vector< T > &vec) {
	os << "[";
	for(uint64_t i = 0; i < vec.size(); i++) {
		os << vec[i];
		if(i != vec.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const map< T, T2 > &m) {
	os << "{";
	for(auto p : m) {
		os << "(" << p.first << "," << p.second << ")";
		os << " ";
	}
	os << "}";
	return os;
}

template< typename T, typename T2 >
ostream& operator<<(ostream& os, const pair< T, T2 > &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

struct Query {
	int l, r, k, i, b;
	
	Query() {}
	Query(int l_, int r_, int k_, int i_, int b_) : l(l_), r(r_), k(k_), i(i_), b(b_) {}
	
	bool operator<(Query o) const {
		return make_pair(l / b, r) < make_pair(o.l / b, o.r);
	}

	int cond() { return (r - l + 1) / k; }
}; 

struct SqrtDecomp {
	int n; int b;
	vector< int > a;
	vector< int > occ;
	vector< int > blocks;
	
	int block(int i) { return i / b; }
	
	SqrtDecomp(vector< int > &v, int b_ = -1) {
		n = v.size();
		b = (b_ == -1 ? ceil(sqrt(n)) : b_);
		a.assign(n, 0);
		occ.assign(n, 0);
		blocks.assign(b, 0);
		for(int i = 0; i < n; i++) a[i] = v[i];
	}

	void add(int x) {
		occ[x]++;
		blocks[block(x)]++;
	}

	void remove(int x) {
		occ[x]--;
		blocks[block(x)]--;
	}

	int answer(Query q) {
		for(int i = 0; i < b; i++) {
			if(blocks[i] <= q.cond()) {
				continue;
			}
			for(int k = 0; k < b; k++) {
				if(occ[k + i * b] > q.cond()) {
					return k + i * b;
				}
			}
		}
		return -1;
	}
};

template< class T > // T -> elems
struct MoAlgorithm {
	int b;
	vector< T > ans;
	MoAlgorithm(vector< T > &v, vector< Query > &queries) {
		SqrtDecomp sq(v);
		ans.assign(queries.size(), -1);
		sort(queries.begin(), queries.end());

		int l = 0;
		int r = 0;
		sq.add(v[r]);
		for(Query q : queries) {
			while(l > q.l) {
				l--;
				sq.add(v[l]);
			}
			while (r < q.r) {
				r++;
				sq.add(v[r]);
			}
			while (l < q.l) {
				sq.remove(v[l]);
				l++;
			}
			while (r > q.r) {
				sq.remove(v[r]);
				r--;
			}
			ans[q.i] = sq.answer(q);
		}
	}
};
	
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.setf(ios::fixed);
	int n, q;
	cin >> n >> q;
	vector< int > v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector< Query > queries(q);
	for(int i = 0; i < q; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--; r--;
		queries[i] = Query(l, r, k, i, ceil(sqrt(n)));
	}

	MoAlgorithm< int > Mo(v, queries);
	for(int an : Mo.ans) {
		cout << an << "\n";
	}
	return 0;
}
