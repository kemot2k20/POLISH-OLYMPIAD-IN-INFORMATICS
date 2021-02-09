#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}
typedef long long ll;
const int INF = 1e9;
const ll INFl = 1e18;
typedef pair<int,int> pii;
typedef vector<int> vi;

deque<pii> Q;

void add(int x) {
	int cnt = 0;
	while (!Q.empty() && Q.back().f >= x) {
		cnt += Q.back().s + 1;
		Q.pop_back();
	}
	Q.push_back({x, cnt});
}

void remove() {
	if (Q.front().s == 0) Q.pop_front();
	else Q.front().s --;
}

int get_min() {
	return Q.front().f;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int q; cin >> q;
		if (q == 1) {
			int x; cin >> x;
			add(x);
		}
		if (q == 2) {
			remove();
		}
		if (q == 3) {
			cout << get_min() << '\n';
		}
	}
	
	return 0;
}
