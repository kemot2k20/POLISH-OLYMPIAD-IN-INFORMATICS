#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e6 + 5;
const int X = 199;
const int mod = 1e9 + 7;

int hasz[N];
int potx[N];

void count_hash(string &s, int n) {
	potx[0] = 1;
	for (int i = 1; i <= n; i ++) potx[i] = (1LL * potx[i - 1] * X);
	hasz[n] = 0;
	for (int i = n - 1; i >= 0; i --) {
		hasz[i] = (1LL * (s[i] - 'a' + 1) + 1LL * X * hasz[i + 1]);
	}
}

int get_hash(int l, int r) {
	return (1LL * hasz[l] - (1LL * potx[r - l + 1] * hasz[r + 1]));
}

int max_pre(int a, int b, int c, int d) {
	int dl1 = b - a + 1;
	int dl2 = d - c + 1;
	int L = 1, R = min(dl1, dl2), pre = 0;
	while (L <= R) {
		int M = (L + R) >> 1;
		if (get_hash(a, a + M - 1) == get_hash(c, c + M - 1)) {
			L = M + 1;
			pre = M;
		}
		else {
			R = M - 1;
		}
	}
	return pre;
}

void test_case(string &s) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a --, b --, c --, d --;
	if (get_hash(a, b) == get_hash(c, d)) {
		cout << "ROWNY\n";
		return;
	}
	int pref = max_pre(a, b, c, d);
	int dl1 = b - a + 1;
	int dl2 = d - c + 1;
	if (pref == min(dl1, dl2)) {
		if (dl1 < dl2) cout << "MNIEJSZY\n";
		else cout << "WIEKSZY\n";
		return;
	}
	if (s[a + pref] - 'a' < s[c + pref] - 'a') cout << "MNIEJSZY\n";
	else cout << "WIEKSZY\n";
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	count_hash(s, n);
	int t;
	cin >> t;
	while (t--) {
		test_case(s);
	}
	return 0;
}
