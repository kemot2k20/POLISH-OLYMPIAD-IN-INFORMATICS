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
const int N = 1e6 + 5;

vector<int> add(string& a, string& b) {
	if (sajz(a) < sajz(b)) swap(a, b);
 	int dl = max(sajz(a), sajz(b));
	vector<int> A(dl, 0), B(dl, 0), C;
	for (int i = sajz(a) - 1; i >= 0; i --) A[i] = (int) a[i] - '0';
	for (int i = dl - 1, j = sajz(b) - 1; j >= 0; i --, j --) B[i] = (int) b[j] - '0';
	int reszta = 0;
	for (int i = dl - 1; i >= 0; i --) {
		if (A[i] + B[i] + reszta < 10) {
			C.pb(A[i] + B[i] + reszta);
			reszta = 0;
		}
		else {
			C.pb((A[i] + B[i] + reszta) % 10);
			reszta = 1;
		}
	}
	reverse(all(C));
	return C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> c = add(a, b);
	for (int i = 0; i < sajz(c); i ++) cout << c[i];
	cout << '\n';
	return 0;
}
