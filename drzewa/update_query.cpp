#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define INF 1e9
#define INFl 1e18
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
#define yes puts("YES")
#define no puts("NO")
#define erase_duplicates(x) {sort(all(x));(x).resize(distance((x).begin(), unique(all(x))));}
using namespace std;
//using namespace __gnu_pbds;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef multiset<int> msi;
typedef long double ld;
//typedef cc_hash_table<int, int, hash<int>> ht;

const int N = (1 << 18);
const int K = 19;

int timer = 0;
int d[N], t[2*N];
int in[N], out[N];
int jump[N][K];
vector<pii> G[N];

void dfs(int v, int par) {
	in[v] = timer ++;
	jump[v][0] = par;

	for (int i = 1; i < K; i ++) jump[v][i] = jump[jump[v][i-1]][i-1];
	for (auto edge : G[v]) {
		int u = edge.first, w = edge.second;
		if (u != par) {
			d[u] = d[v] + w;
			dfs(u, v);
		}
	}

	out[v] = timer;
}

bool anc(int v, int u) {
	return in[v] <= in[u] && out[v] >= out[u];
}

int query_lca(int v, int u) {
	if (anc(v, u)) return v;
	if (anc(u, v)) return u;

	for (int i = K-1; i >= 0; i --) {
		if (!anc(jump[v][i], u)) v = jump[v][i];
	}

	return jump[v][0];
}

void modify(int l, int r, int x) {
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] += x;
		if (r&1) t[--r] += x;
	}
}

int query(int v) {
	int sum = 0;
	v += N;

	while (v) {
		sum += t[v];
		v /= 2;
	}

	return sum;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<pii, int>> kr;
	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;

		G[v].pb({u, w});
		G[u].pb({v, w});
		kr.pb({{u, v}, w});
	}

	dfs(0, 0);

	for (int i = 0; i < n; i ++) {
		modify(in[i], in[i]+1, d[i]);
	}

	int q;
	cin >> q;

	while (q--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, w;
			cin >> i >> w;
			i --;

			int v = kr[i].first.first, u = kr[i].first.second, cur_w = kr[i].second;
			if (!anc(v, u)) swap(v, u);

			modify(in[u], out[u], w - cur_w);
			kr[i].second = w;
		} else {
			int v, u;
			cin >> v >> u;
			v --, u --;

			int lca = query_lca(v, u);
			int path_v = query(in[v]), path_u = query(in[u]), path_lca = query(in[lca]);

			cout << path_v + path_u - 2LL * path_lca << '\n';
		}
	}
	
	return 0;
}
