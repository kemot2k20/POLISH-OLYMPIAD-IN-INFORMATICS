#include <bits/stdc++.h>
#define INF 1e9
#define INFl 1e18;
#define EMPTY 0
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int N = 1 << 19;

template < class T, T FQ(const T&, const T&), T FM(const T&, const T&) >
struct SegmentTree{
    
    int BASE;
    vector < T > tree, lazy;
    
    SegmentTree(int n): BASE(1 << (__lg(n) + 1)){
        tree.resize(BASE << 1);
        lazy.resize(BASE << 1);
    }
    
    void init(){
        for(int i = BASE - 1; i >= 0; i--){
            tree[i] = FQ(tree[i << 1], tree[i << 1|1]);
        }
    }
    
    void preset(const int& i, const T& val){
        tree[i + BASE] = val;
    }
    
    void propagation(const int& u, const int& lo, const int& hi){
        if(lazy[u] == EMPTY){
            return;
        }
        tree[u] = FM(tree[u], lazy[u]);
        if(lo != hi){
            lazy[u << 1] = FM(lazy[u << 1], lazy[u]);
            lazy[u << 1|1] = FM(lazy[u << 1|1], lazy[u]);
        }
        lazy[u] = EMPTY;
    }
    
	void modify(const int& l, const int& r, const T& val, const int& u, const int& lo, const int& hi){
		propagation(u, lo, hi);
		if(lo > r || hi < l){
			return;
		}
		if(lo >= l && hi <= r){
			lazy[u] = FM(lazy[u], val);
			propagation(u, lo, hi);
			return;
		}
		int mid = (lo + hi) >> 1;
		modify(l, r, val, u << 1, lo, mid);
		modify(l, r, val, u << 1|1, mid + 1, hi);
		tree[u] = FQ(tree[u << 1], tree[u << 1|1]);
	}
		
	void modify(const int& l, const int& r, const T& val){
		modify(l, r, val, 1, 0, BASE - 1);
	}
	
	void modify(const int& v, const T& val){
		modify(v, v, val, 1, 0, BASE - 1);
	}

	T query(const int& l, const int& r, const int& u, const int& lo, const int& hi){
		propagation(u, lo, hi);
		if(lo > r || hi < l){
			return -INFl;
		}
		if(lo >= l && hi <= r){
			return tree[u];
		}
		int mid = (lo + hi) >> 1;
		return FQ(query(l, r, u << 1, lo, mid), query(l, r, u << 1|1, mid + 1, hi));
	}
	
	T query(const ll& l, const ll& r){
		return query(l, r, 1, 0, BASE - 1);
	}
	
	T query(const ll& v){
		return query(v, v, 1, 0, BASE - 1);
	}
};

ll FQ(const ll& a, const ll& b){
    return max(a, b);
}

ll FM(const ll& a, const ll& b){
    return a + b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    SegmentTree <ll, FQ, FM> tree(N); 
    int n, q;
    cin >> n >> q;
    while (q--) {
		int com;
		cin >> com;
		if (com == 1) {
			int l, r, w;
			cin >> l >> r >> w;
			l --, r --;
			tree.modify(l, r, w);
		}
		else if (com == 2) {
			int l, r;
			cin >> l >> r;
			l --, r --;
			cout << tree.query(l, r) << '\n';
		}
	}
}
