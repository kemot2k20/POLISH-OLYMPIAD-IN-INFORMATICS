#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int main() {
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> dp(n+1, -INF), a(n);
	dp[0] = INF;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		int x = 0;
		for (int j = 0; j < 6; j ++) {
			if (j == 2) continue;
			x *= 10;
			x += (s[j]-'0');
		}
		a[i] = x;
	}
	for (int i = 0; i < n; i ++) {
		int L = 0, R = n, j = -1;
		while (L <= R) {
			int mid = (L+R)/2;
			if (dp[mid] < a[i]) {
				j = mid;
				R = mid - 1;
			}
			else {
				L = mid + 1;
			}
		}
		//cout << i << " : " << j << '\n';
		if (dp[j-1] > a[i] && a[i] > dp[j]) {
			dp[j] = a[i];
		}	
	}
	//for (int i = 0; i < n; i ++) cout << dp[i] << ' ';
	//cout << '\n';
	int ans = 1;
	for (int i = 1; i <= n; i ++) {
		if (dp[i] != -INF) ans = i;
	}
	cout << 100 * ans << '\n';
}
