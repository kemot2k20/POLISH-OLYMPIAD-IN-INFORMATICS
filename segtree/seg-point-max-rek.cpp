#include <bits/stdc++.h>
#define INF 1e9
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
int t[N];
int a[N];
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

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int maks(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(maks(v*2, tl, tm, l, min(r, tm)), maks(v*2+1, tm+1, tr, max(l, tm+1), r));
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
			int pos, x;
			cin >> pos >> x;
			pos --;
			update(1, 0, n-1, pos, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			l --, r --;
			cout << maks(1, 0, n-1, l, r) << '\n';
		}
	}
	return 0;
}
