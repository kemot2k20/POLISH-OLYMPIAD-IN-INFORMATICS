#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+5;
const int MXM = 5e5+5;
bool odw[MXN];
bool vis[MXN];
int parent[MXN];
int pre[MXN];
int post[MXN];
int low[MXN];
vector <int> G[MXM];
int t = 1, ans = 0;

void DFS(int v){
	odw[v] = true; 
	pre[v] = t++; low[v] = pre[v];
	
	for(int i = 0; i < G[v].size(); i ++){
		int u = G[v][i];
		if(!odw[u]){
			parent[u] = v;
			DFS(u);
			low[v] = min(low[u], low[v]);
		}
		else if(u != parent[v]) low[v] = min(low[v], pre[u]);
	}
	post[v] = t++;
}
void odp(int v){
	odw[v] = false; 
	
	for(int i = 0; i < G[v].size(); i ++){
		int u = G[v][i];
		if(odw[u]){
 			odp(u);
			if(low[u] > pre[parent[u]] && !vis[u]) ans ++, vis[parent[u]] = true; 
			if(vis[u]) vis[parent[u]] = true;
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i = 0; i < m; i ++){
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	parent[1] = 1;
	DFS(1);
	odp(1);
	if(ans < 4) cout << ans << '\n';
	else cout << ans/2 + ans%2 << '\n';
}
