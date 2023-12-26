#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define INF 1000000000
#define INFl 1000000000000000000
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define se second
#define fi first
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

const int N = 2e5 + 5;
vi adj[N];
int d[N], dp[N];

void dfs1(int v, int par) {
	for (auto u : adj[v]) {
		if (u == par) continue;
		dfs1(u, v);
		dp[v] = max(dp[v], dp[u] + 1);
	}
}

void dfs2(int v, int par) {
	multiset<int> S;
	for (auto u : adj[v]) {
		S.insert(dp[u] + 1);
	}

	if (sajz(S)) {
		d[v] = *S.rbegin();
	}

	for (auto u : adj[v]) {
		if (u == par) continue;
		
		// reroot from v to u

		int me = dp[u] + 1;
		S.erase(S.find(me));

		int tmp_u = dp[u];
		int tmp_v = dp[v];

		int mx = 0;
		if (sajz(S)) mx = *S.rbegin();

		dp[u] = max(dp[u], mx + 1);
		dp[v] = mx;

		dfs2(u, v);

		dp[u] = tmp_u;
		dp[v] = tmp_v;

		S.insert(me);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		cin >> a >> b;
		a --, b --;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs1(0, -1);
	dfs2(0, -1);

	for (int i = 0; i < n; i ++) {
		cout << i << " : " << d[i] << '\n';
	}
}
