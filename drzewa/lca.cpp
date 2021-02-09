#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MX = 1e6 + 5;
const int LOG = 21;

vector <int> G[MX];
int jump[MX][LOG];
int parent[MX];
int post[MX];
int pre[MX];
bool odw[MX];
int t = 1;

void DFS(int v) {
	odw[v] = true;
	pre[v] = t++;
	jump[v][0] = parent[v];
	for (int i = 1; i < LOG; i ++) {
		int x = jump[v][i-1];
		jump[v][i] = jump[x][i-1];
	}
	for (auto u : G[v]) {
		if (!odw[u]) {
			parent[u] = v;
			DFS(u);
		}
	}
	post[v] = t++;
}

bool czy_przodek(int a, int b) {
	return pre[a] <= pre[b] && post[a] >= post[b];
}

int query_lca(int u, int v) {
	int cnt = LOG-1;
	if (czy_przodek(u, v)) return u;
	if (czy_przodek(v, u)) return v;
	for (int i = cnt; i >= 0; i --) {
		if (!czy_przodek(u, jump[v][i])) {
			v = jump[v][i];
		}
	}
	return parent[v];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i ++) {
		int a, b; cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	parent[1] = 1;
	DFS(1);
}
