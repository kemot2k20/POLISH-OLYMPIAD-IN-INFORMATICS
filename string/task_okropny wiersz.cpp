#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5e5 + 5;
const int X = 199;
const int mod = 1234567891;

int n;
string s;
int hasz[N];
int potx[N];

void count_hash() {
	potx[0] = 1;
	for (int i = 1; i <= n; i ++) potx[i] = (1LL * X * potx[i - 1]);
	hasz[n] = 0;
	for (int i = n - 1; i >= 0; i --) hasz[i] = ((s[i] - 'a' + 1) + 1LL * X * hasz[i + 1]);
}

int get_hash(int l, int r) {
	return (hasz[l] - (1LL * potx[r - l + 1] * hasz[r + 1]));
}

void test_case() {
	int l, r;
	cin >> l >> r;
	l--, r --;
	int dl = r - l + 1;
	vector<int> divs;
	for (int i = 1; i * i <= dl; i ++) {
		if (dl % i == 0) {
			divs.pb(i);
			if (i * i != dl) divs.pb(dl / i);
		}
	}
	int ans = 1e9;
	for (int x : divs) {
		if (get_hash(l, r - x) == get_hash(l + x, r)) ans = min(ans, x);
	}
	cout << ans << '\n';
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	cin >> n >> s;
	count_hash();
	int t;
	cin >> t;
	while (t --) {
		test_case();
	}
	return 0;
}
