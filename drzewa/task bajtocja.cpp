#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;

vector <pair <int, pair<int,int> > > V[100005];
short uf[7005];
bool good[300005];

int find(short x) {
	if (uf[x] == x) return x;
	uf[x] = find(uf[x]);
	return uf[x];
}

void Union(short a, short b) {
	short sa = find(a); int sb = find(b);
	uf[sb] = sa;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)	;
	short n; cin >> n;
	int maks = 0, m; cin >> m;
	for (short i = 1; i <= n; i ++) uf[i] = i;
	for (int i = 1; i <= m; i ++) {
		short a, b; cin >> a >> b;
		int c; cin >> c;
		V[c].pb({i, {a, b}});
		maks = max(maks, c);
	}

	for (int i = 1; i <= maks; i ++) {
		for (auto it : V[i]) {
			if (find(it.s.s) != find(it.s.f)) good[it.f] = true; 
		}
		
		for (auto it : V[i]) {
			if (find(it.s.f) != find(it.s.s)) Union(it.s.f, it.s.s);
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		cout << (good[i] ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
