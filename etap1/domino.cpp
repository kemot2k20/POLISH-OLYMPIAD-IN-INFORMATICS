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
ll INFl = 1e18;

vector<ll> fib;

void policz_fib() {
	ll a = 0, b = 1, c = 1;
	fib.pb(1);
	while (a+b <= INFl) {
		c = a + b;
		fib.pb(c);
		a = b;
		b = c;
	}
	//cout << sajz(fib) << '\n';
	//for (int i = 0; i < 20; i ++) {
		//cout << fib[i] << '\n';
	//}
	//cout << fib[sajz(fib)-1] << '\n';
}

void solve(ll m) {
	if (m == 1) {
		cout << 1 << '\n';
		return;
	}
	int n = sajz(fib);
	int sum = 0, ile = 0;
	bool check = true;
	while (m > 1 && check) {
		check = false;
		for (int i = n-1; i > 1; i --) {
			if (m % fib[i] == 0) {
				m /= fib[i];
				sum += i; 
				ile ++;
				check = true;
				break;
			}
		}
	}
	if (check == false) {
		cout << "NIE\n";
		return;
	}
	cout << sum + ile - 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	ll m;
	cin >> m;
	policz_fib();
	solve(m);
	return 0;
}
