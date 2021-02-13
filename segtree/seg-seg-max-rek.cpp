#include <bits/stdc++.h>
#define INF 1e9
#define INFl 1e18
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;

const int N = (1 << 19);
ll t[N];
int a[N];
ll lazy[N];
int n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INFl;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	build(1, 0, n-1);
	int q;
	cin >> q;
	while (q--) {
		int com;
		cin >> com;
		if (com == 1) {
			int l, r;
			cin >> l >> r;
			l --, r --;
			cout << query(1, 0, n-1, l, r) << '\n';
		}
		else {
			int l, r, add;
			cin >> l >> r >> add;
			l --, r --;
			update(1, 0, n-1, l, r, add);
		}
	}
	return 0;
}
