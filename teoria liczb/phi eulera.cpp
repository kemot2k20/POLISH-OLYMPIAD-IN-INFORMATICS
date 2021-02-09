#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;

const int N = 1e7 + 5;

vector<bool> Primes(int n) {
	vector<bool> P(n + 1, true);
	P[0] = P[1] = false;
	for (int i = 2; i * i <= n; i ++)
		if (P[i])
			for (int j = i * i; j <= n; j += i)
				P[j] = false;
	return P;
}

int eulerPhi[N];

void phi(int n, vector<bool>& isPrime) {
	for (int i = 1; i <= n; i++) eulerPhi[i] = i;
	for (int i = 1; i <= n; i++) {
	    if (isPrime[i])
	        for (int j = i; j <= n; j += i)
	            eulerPhi[j] -= (eulerPhi[j] / i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<bool> isPrime = Primes(n);
	phi(n, isPrime);
	for (int i = 1; i <= n; i ++) cout << eulerPhi[i] << ' ';
	cout << '\n';
	return 0;
}
