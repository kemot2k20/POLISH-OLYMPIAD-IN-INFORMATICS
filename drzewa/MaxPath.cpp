#include <bits/stdc++.h>
using namespace std;
const int MX = 5e5 + 5;

vector <pair <int, int> > graf[MX];
int odw[MX], ans[MX][2], n;

void DFS(int v) {
	odw[v]=1;
	for(int i=0; i<graf[v].size(); i++) {
		int u = graf[v][i].first;
		int koszt = graf[v][i].second;
		if(odw[u]==0) {
			odw[u]=1;
			DFS(u);
			if(ans[v][0] == 0) ans[v][0] = koszt + max(ans[u][0], ans[u][1]);
			else if(ans[v][1] == 0) ans[v][1] = koszt + max(ans[u][0], ans[u][1]);
			else{
				if(ans[v][0] > ans[v][1]) ans[v][1] = max(ans[v][1], koszt + max(ans[u][0], ans[u][1]));
				else ans[v][0] = max(ans[v][0], koszt + max(ans[u][0], ans[u][1]));
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1; i<n; i++) {
		int a,b,c; cin>>a>>b>>c;
		graf[a].push_back(make_pair(b, c));
		graf[b].push_back(make_pair(a, c));
	}
	DFS(1); int x = 0;
	for(int i = 1; i <= n; i ++) x = max(x, ans[i][0] + ans[i][1]);
	cout << x << '\n';
}
