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

// O(N * M^2)

const int N = 105;

vi G[N];
int capacity[N][N];
int p[N];

int bfs(int s, int t, int n) {
	for (int i = 0; i < n; i ++) p[i] = -1;
	p[0] = -2;

	queue<pii> q;
	q.push({0, 1e9});

	while (!q.empty()) {
		int v = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (auto u : G[v]) {
			if (p[u] == -1 && capacity[v][u]) {
				flow = min(flow, capacity[v][u]);
				p[u] = v;
				if (u == t) return flow;
				q.push({u, flow});
			}
		}
	}

	return 0;
}

int max_flow(int s, int t, int n) {
	int new_flow, flow = 0;
	while (new_flow = bfs(s, t, n)) {
		flow += new_flow;
		int cur = t;
		
		while (cur != s) {
			int prev = p[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i ++) {
		int v, u, c;
		cin >> v >> u >> c;
		v --, u --;

		G[u].pb(v);
		G[v].pb(u);
		capacity[v][u] = c;
		capacity[u][v] = 0;
	}

	cout << max_flow(0, n - 1, n) << '\n';

	return 0;
}
