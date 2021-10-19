#include <bits/stdc++.h>
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
ll mod = 1e9 + 7;

bool poprawny_ciag(int n, vector<int>&a) {
	if (n == 3 && a[0] != a[n-1]) return false;
	vector<int>ind(n+5, -1);
	for (int i = 0; i < n; i ++) {
		if (ind[a[i]] == -1) {
			ind[a[i]] = i;
		}
		else {
			if (abs(ind[a[i]] - i) != 2) {
				return false;
			}
			ind[a[i]] = -2137;
		}
	}
	return true;
}

bool pewniki(int n, vector<int>&a, vector<int>&pewny, vector<bool>&jest) {
	for (int i = 1; i < n - 1; i ++) {
		if (jest[a[i]]) {
			continue;
		}
		if (a[i] == a[i+2]) {
			if (pewny[i+1] != 0) return false;  
			pewny[i+1] = a[i];
			jest[a[i]] = true;
			continue;
		}
		if (pewny[i-1] != 0) {
			if (pewny[i+1] != 0) return false;  
			pewny[i+1] = a[i];
			jest[a[i]] = true;
			continue;
		} 
		if (pewny[i+1] != 0) {
			if (pewny[i-1] != 0) return false;  
			pewny[i-1] = a[i];
			jest[a[i]] = true;
			continue;
		}
	}
	for (int i = n-2; i > 0; i --) {
		if (jest[a[i]]) {
			continue;
		}
		if (a[i] == a[i+2]) {
			if (pewny[i+1] != 0) return false;  
			pewny[i+1] = a[i];
			jest[a[i]] = true;
			continue;
		}
		if (pewny[i-1] != 0) {
			if (pewny[i+1] != 0) return false;  
			pewny[i+1] = a[i];
			jest[a[i]] = true;
			continue;
		} 
		if (pewny[i+1] != 0) {
			if (pewny[i-1] != 0) return false;  
			pewny[i-1] = a[i];
			jest[a[i]] = true;
			continue;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int>a(n+5);
	for (int i = 0; i < n; i ++) cin >> a[i];
	vector<int>pewny(n+5);
	vector<bool>jest(n+5);
	pewny[1] = a[0];
	pewny[n-2] = a[n-1];
	jest[a[0]] = true;
	jest[a[n-1]] = true;
	if (poprawny_ciag(n, a) == false || pewniki(n, a, pewny, jest) == false) {
		cout << 0 << '\n';
		return;
	}
	//cout << "pewny : \n";
	//for (int i = 0; i < n; i ++) cout << pewny[i] << ' ';
	//cout << '\n';
	vector<bool> bylo(n+5);
	int pozostale = n;
	for (int i = 0; i < n; i ++) {
		if (!bylo[a[i]]) {
			bylo[a[i]] = true;
			pozostale --;
		}
	}
	//cout << "pozostale :  " << pozostale << '\n';
	vector<int> dlnp, dlp;
	int dl = 0;
	for (int i = 0; i < n; i += 2) {
		if (pewny[i] == 0) {
			dl ++;
		} 
		else {
			if (dl > 0) dlp.pb(dl);
			dl = 0;
		}
	}
	if (dl > 0) dlp.pb(dl);
	dl = 0;
	for (int i = 1; i < n; i += 2) {
		if (pewny[i] == 0) {
			dl ++;
		} 
		else {
			if (dl > 0) dlnp.pb(dl);
			dl = 0;
		}
	}
	if (dl > 0) dlnp.pb(dl);
	ll ans = 1;
	for (int i = 0; i < sajz(dlp); i ++) {
		//cout << "parzyste :  " << dlp[i] << ' ';
		ll mnoz = 1LL * dlp[i] * max(1, pozostale--);
		ans = (ans * mnoz) % mod;
	}
	//cout << '\n';
	for (int i = 0; i < sajz(dlnp); i ++) {
		//cout << "nieparzyste :  " << dlnp[i] << ' ';
		ll mnoz = 1LL * dlnp[i] * max(1, pozostale--);
		ans = (ans * mnoz) % mod;
	}
	//cout << '\n';
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}
