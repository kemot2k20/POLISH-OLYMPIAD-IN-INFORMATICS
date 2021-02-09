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

void buildPi(string& p, vector<int>& pi) {
 	int k = -2;
    for(int i = 0; i < p.length(); i++) {
	    while(k >= -1 && p[k+1] != p[i])
	    k = (k == -1) ? -2 : pi[k];
	    pi[i] = ++k;
  	}
}

vector<int> search(string& s, string& pat) {
	string x = pat + '#' + s;
	vector<int> pi(sajz(x));
	buildPi(x, pi);
	for (int i = 0; i < sajz(x); i ++) pi[i] ++;
	vector<int> pos;
	for (int i = 0; i < sajz(x); i ++) {
		if (pi[i] == sajz(pat)) {
			pos.pb(i - 2 * sajz(pat));
		}
	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> pos = search(a, b);
	for (int i = 0; i < sajz(pos); i ++) cout << pos[i] << ' ';
	cout << '\n';
	return 0;
}
