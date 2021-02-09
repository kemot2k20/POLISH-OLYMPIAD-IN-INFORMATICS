#include <iostream>
#include <vector>
#include <queue>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
typedef queue<pii> qpii;
 
int xo[4] = {1, -1, 0, 0};
int yo[4] = {0, 0, 1, -1};
int n, m;
 
bool good(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
 
void test_case() {
	int k, a, b, c, d; cin >> n >> m >> k >> a >> b >> c >> d;
	
	vector<string> grid(n+1);
	vector<vector<int> > odl(n+1, vector<int>(m+1, 1e9));
	vector<vector<bool> > odw(n+1, vector<bool>(m+1));
	for (int i = 1; i <= n; i ++) cin >> grid[i];
	qpii Q;
	Q.push({a, b});
	odl[a][b] = 0;
	odw[a][b] = true;
	
	while (!Q.empty()) {
		pii cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i ++) {
			for (int j = 1; j <= k; j ++) {
				int X = cur.f + xo[i] * j;
				int Y = cur.s + yo[i] * j;
				if (good(X, Y)) {
					if (grid[X][Y-1] == '@' || odl[X][Y] < odl[cur.f][cur.s] + 1) break;
					if (!odw[X][Y]) {
						odl[X][Y] = odl[cur.f][cur.s] + 1;
						odw[X][Y] = true;
						Q.push({X, Y});
					}
				}
			}
		}
	}
	cout << (odl[c][d] == 1e9 ? -1 : odl[c][d]) << '\n';
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	test_case();
	return 0;
}
