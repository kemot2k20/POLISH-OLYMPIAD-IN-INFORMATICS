#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const ll INFl = 1e18;
const int N = 505;

vector<int> G[N];
int l[N], r[N];
bool vis[N];
int n, m;

bool dfs(int u) {
    if(vis[u]) return false;
    vis[u] = true;

    for(int v : G[u]) {
		if(r[v] == -1) {
			l[u] = v;
			r[v] = u;
			return true;
		}
    }

    for(int v : G[u]) {
		if(dfs(r[v])) {
			l[u] = v;
			r[v] = u;
			return true;
		}
    }
    return false;
}

int matching() {
    fill(l, l + n, -1);
    fill(r, r + m, -1);
    int ok = true;
    while(ok--) {
        fill(vis, vis + n, false);
        for(int i = 0; i < n; i++) {
            if(l[i] == -1)  ok |= dfs(i);
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        res += (l[i] != -1);
    }
    return res;
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	int maks_matching = matching();
	cout << maks_matching << '\n';
	return 0;
}
