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

//#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef multiset<int> msi;
typedef long double ld;
//typedef cc_hash_table<int, int, hash<int>> ht;

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}	
};

// the "hyperplane split", use comparators for all dimensions
bool cmpx(const point& a, const point& b) {return a.x < b.x;}
bool cmpy(const point& a, const point& b) {return a.y < b.y;}

long double dist(const point& a, const point& b) {
	int X = abs(a.x - b.x);
	int Y = abs(a.y - b.y);
	ll d = 1LL * X * X + 1LL * Y * Y;
	return sqrt(d);
}

point middle(const point& a, const point& b) {
	return point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
}

const int N = 5e5 + 5;

point P[N];

struct kdtree {
	point *tree;
	int n;
	// constructor
	kdtree(point p[], int n): tree(new point[n]), n(n) {
		copy(p, p + n, tree);
		build(0, n, false);
	}
	// destructor
	~kdtree() {delete[] tree;}
	// k-nearest neighbor query, O(k log(k) log(n)) on average
	vector<point> query(double x, double y, int k = 1) {
		perform_query(x, y, k, 0, n, false); // recurse
		vector<point> points;
		while (!pq.empty()) { // collect points
			points.push_back(*pq.top().second);
			pq.pop();
		}
		reverse(points.begin(), points.end());
		return points;
	}
private:
	// build is O(n log n) using divide and conquer
	void build(int L, int R, bool dvx) {
		if (L >= R) return;
		int M = (L + R) / 2;
		// get median in O(n), split x-coordinate if dvx is true
		nth_element(tree+L, tree+M, tree+R, dvx?cmpx:cmpy);
		build(L, M, !dvx); build(M+1, R, !dvx);
	}

	// priority queue for KNN, keep the K nearest
	priority_queue<pair<double, point*> > pq;
	void perform_query(double x, double y, int k, int L, int R, bool dvx) {
		if (L >= R) return;
		int M = (L + R) / 2;
		double dx = x - tree[M].x;
		double dy = y - tree[M].y;
		double delta = dvx ? dx : dy;
		double dist = dx * dx + dy * dy;
		// if point is nearer to the kth farthest, put point in queue
		if (pq.size() < k || dist < pq.top().first) {
			pq.push(make_pair(dist, &tree[M]));
			if (pq.size() > k) pq.pop(); // keep k elements only
		}
		int nearL = L, nearR = M, farL = M + 1, farR = R;
		if (delta > 0) { // right is nearer
			swap(nearL, farL);
			swap(nearR, farR);
		}
                // query the nearer child
		perform_query(x, y, k, nearL, nearR, !dvx);

		if (pq.size() < k || delta * delta < pq.top().first)
                        // query the farther child if there might be candidates
			perform_query(x, y, k, farL, farR, !dvx);
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;

		P[i] = point(x, y);
	}

	kdtree T(P, n);

	long double wyn = INFl;

	vector<point> ans;

	for (int i = 0; i < n; i ++) {
		vector<point> nei = T.query(P[i].x, P[i].y, 2);
		point best = nei[1];

		long double res = dist(P[i], best);

		if (res > wyn) continue;

		point mid = middle(P[i], best);

		nei = T.query(mid.x, mid.y, 3);

		point best_mid;
		for (auto p : nei) {
			if ((p.x != best.x || p.y != best.y) && (p.x != P[i].x || p.y != P[i].y)) {
				best_mid = p;
				break;
			}
		}

		res += dist(best_mid, P[i]);
		res += dist(best_mid, best);

		if (res < wyn) {
			wyn = res;
			ans = {P[i], best_mid, best};
		}
	}

	debug(wyn);

	for (int i = 0; i < 3; i ++) {
		cout << int(ans[i].x) << ' ' << int(ans[i].y) << '\n';
	}
    
    return 0;
}
