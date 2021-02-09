#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int MX = 300000 + 5;

vector <pair <int, pii> > V;
vector <pair <int, pii> > G;
int uf[MX];

int find(int x) {
	if (uf[x] == x) return x;
	uf[x] = find(uf[x]);
	return uf[x];
}

void Union(int a, int b) {
	int sa = find(a); int sb = find(b);
	uf[sb] = sa;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) uf[i] = i;
	for (int i = 1; i <= m; i ++) {
		int a, b, c; cin >> a >> b >> c;
		V.pb({c, {a, b}});
	}
	sort(V.begin(), V.end());
	
	for (auto it : V) {
		if (find(it.s.f) != find(it.s.s)) Union(it.s.f, it.s.s), cout << it.s.f << ' ' << it.s.s << '\n';
	}

	return 0;
}
