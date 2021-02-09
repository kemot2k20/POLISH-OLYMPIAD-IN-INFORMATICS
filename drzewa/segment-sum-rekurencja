#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+5;

ll t[2*N];
int n, q;

void build(int v = 1) {
	if (v < n) {
		build(v<<1);
		build(v<<1|1);
	}
	t[v] = t[v<<1] + t[v<<1|1];
}

void modify(int v, int x) {
	t[v += n] = x;
	while (v > 1) {
		t[v>>1] = t[v] + t[v^1];
		v >>= 1;
	} 
}

int query(int l, int r, int v = 1, int tl = 0, int tr = N) {
	if (l > r) return 0;
	if (l <= tl && r >= tr) return t[v];
	int mid = (tl + tr)/2;
	return query(l, r, v<<1, tl, mid) + query(l, r, v<<1|1, mid+1, tr);
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i ++) cin >> t[i+n];
	build();
	while (q--) {
		int kom;
		cin >> kom;
		if (kom == 1) {
			int ind, x;
			cin >> ind >> x;
			modify(ind, x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
	return 0;
}
