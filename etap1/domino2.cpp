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
	//for (int i = 0; i < 30; i ++) {
	//cout << fib[i] << '\n';
	//}
	//cout << fib[sajz(fib)-1] << '\n';
}

int solve(ll m) {
	if (m == 1) {
		//cout << "L\n";
		return 1;
	}
	ll m1 = m;
	int n = sajz(fib);
	int sum = 0, ile = 0;
	bool check = true;
	while (m > 1 && check) {
		check = false;
		for (int i = n-1; i > 1; i --) {
			if (m % fib[i] == 0) {
				m /= fib[i];
				//cout << "X " << fib[i] << ' ' << m << ' ' << i << '\n';
				sum += i; 
				ile ++;
				check = true;
				break;
			}
		}
	}
	if (check == true) {
		//cout << "TRUE " << sum << ' ' << ile << '\n';
		return sum + ile - 1;
	}
	if (check == false) {
		check = true;
		for (int i = sajz(fib)-1; i > 1; i --) {
			ll co = 0;
			//if ((fib[i] % m == 0 || m % fib[i] == 0) && m1 % fib[i] == 0) {
				//cout << "Y "<<fib[i] << ' ' << m1 / fib[i] << ' ' << i << '\n';
				//return i + 1 + solve(m1 / fib[i]);
			//}
			ll GCD = gcd(m, fib[i]);
			if (m1 % GCD == 0) {
				co = max(co, GCD);
			}
			if (co > 1) {
				for (int j = sajz(fib)-1; j > 1; j --) {
					if (fib[j] % co == 0 && m1 % fib[j] == 0) {
						//cout << "Y "<< fib[j] << ' ' << m1 / fib[j] << ' ' << j << '\n';
						return j + 1 + solve(m1 / fib[j]);
					}
				}
			}
		}
		//cout << "FALSE\n";
		return -1000000000;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	policz_fib();
	int x = 0;
	for (int i = 1; i <= 50000000; i ++) {
		ll m = i;
		int ans = solve(m);
		if (ans < 0) {
			//cout << "NIE" << '\n';
			//break;
			//x ^= ans;
			x ^= 0;
		}
		else x ^= ans; //cout << ans << '\n';
	}
	cout << x << '\n';
	//ll m;
	//cin >> m;
	//int ans = solve(m);
	//if (ans < 0) cout << "NIE";
	//else cout << ans;
	return 0;
}
/*const vector < ll > divisors = {1, 2, 3, 5, 2, 13, 7, 17, 11, 89, 3, 233, 29, 61, 47, 1597, 19,
sort(begin(pos), end(pos), [&](int a, int b){
        if(divisors[a] != divisors[b])    return divisors[a] > divisors[b];
        return fib[a] > fib[b];
   });*/
