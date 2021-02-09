// ile najmniej nominalow do wydania X jesli nominaly sa ograniczone
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int max_val = 20005;
const int INF = 1e9;
int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), dp(max_val, INF), ile(max_val);
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		ile[a[i]] += x;
	}
	int X;
	cin >> X;
	dp[0] = 0;
	for (int i = 0; i < n; i ++) {
		vector<int> dp2 = dp;
		for (int j = a[i]; j <= X; j ++) {
			if (j / a[i] <= ile[a[i]]) dp2[j] = min(dp2[j], dp2[j - a[i]] + 1);
			else dp2[j] = min(dp[j], dp[j - a[i]] + 1);
		}
		dp = dp2;
	}
	cout << (dp[X] == INF ? -1 : dp[X]) << '\n';
	return 0;
}
