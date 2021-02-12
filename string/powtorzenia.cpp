#include <bits/stdc++.h>
#define INF 1e9
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
const int N = 2005;
const int X = 199;
const int mod = 1234567891;

unordered_map<int, bool> jest[5];
string a[5];
int hasz[N][5];
int potx[N][5];

void count_hash(string& s, int ind, int n) {
	potx[0][ind] = 1;
	for (int i = 1; i <= sajz(s); i ++) potx[i][ind] = (1LL * X * potx[i - 1][ind]) % mod;
	hasz[n][ind] = 0;
	for (int i = sajz(s) - 1; i >= 0; i --) hasz[i][ind] = ((s[i] - 'a' + 1) + 1LL * X * hasz[i + 1][ind]) % mod;
}

int get_hash(int l, int r, int ind) {
	return (hasz[l][ind] - (1LL * potx[r - l + 1][ind] * hasz[r + 1][ind]) % mod + mod) % mod;
}

void czysc(int n) {
	for (int i = 0; i < n; i ++) {
		jest[i].clear();
	}
}

bool check(int mid, int n) {
	czysc(n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < sajz(a[i]) - mid; j ++) {
			int id = get_hash(j, j + mid, i);
			jest[i][id] = true;
		}
	}
	for (auto it : jest[0]) {
		bool czy = true;
		for (int i = 1; i < n; i ++) {
			if (!jest[i][it.f]) {
				czy = false;
				break;
			}
		}
		if (czy) return true;
	}
	return false;
}

int solve(int n) {
	int L = 0, R = sajz(a[0]) - 1, res = -1;
	while (L <= R) {
		int M = (L + R) / 2;
		if (check(M, n)) {
			res = M;
			L = M + 1;
		}
		else {
			R = M - 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	if (n == 1) {
		cout << sajz(a[0]) << '\n';
		return 0;
	}
	for (int i = 0; i < n; i ++) {
		count_hash(a[i], i, n);
	}
	cout << solve(n) + 1 << '\n';
	return 0;
}
