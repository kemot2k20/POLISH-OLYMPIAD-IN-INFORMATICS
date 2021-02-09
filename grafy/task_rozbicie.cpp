#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int MX = 1e5 + 5;

int n, m;
int uf[MX];
bool zle[MX * 2];
bool vis[MX];
vector <pii> path;
vector <int> G[MX];
vector <int> bad;
vector <int> ans;

int find(int x) {
	if (uf[x] == x) return x;
	uf[x] = find(uf[x]);
	return uf[x];
}

void Union(int a, int b) {
	int sa = find(a);
	int sb = find(b);
	if (sa < sb) uf[sb] = sa;
	else uf[sa] = sb;
}

void query(int x) {
	vis[x] = true;
	for (auto it : G[x])
		if (!vis[it]) query(it);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) uf[i] = i;
	for (int i = 1; i <= m; i ++) {
		int a, b; cin >> a >> b;
		path.pb({a,b});
	}
	
	int k; cin >> k;
	for (int i = 1; i <= k; i ++) {
		int x; cin >> x;
		bad.pb(x);
		zle[x] = true;
	}
	
	for (int i = 1; i <= m; i ++) {
		if (!zle[i]) {
			int a = path[i-1].f;
			int b = path[i-1].s;
			G[a].pb(b);
			G[b].pb(a);
		}
	}
	
	int spojne = 0;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			spojne ++;
			query(i);
		}
	}
	
	for (int i = 0; i < path.size(); i ++) {
		if (!zle[i+1]) Union(path[i].f, path[i].s);
	}
	
	ans.pb(spojne);
	for (int i = bad.size()-1; i > 0; i --) {
		if (find(path[bad[i]-1].f) != find(path[bad[i]-1].s)) {
			spojne --;
			Union(path[bad[i]-1].f, path[bad[i]-1].s);
		}
		ans.pb(spojne); 
	}
	for (int i = ans.size()-1; i >= 0; i --) cout << ans[i] << ' ';
	
	return 0;
}
