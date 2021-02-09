#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;

vector<int> G[MX];
bool odw[MX];
int syns[MX];

void DFS(int v){
	odw[v] = true;
	syns[v] = 1;
	for(int i = 0; i < G[v].size(); i ++){
		int u = G[v][i];
		if(!odw[u]){
			DFS(u);
			syns[v] = syns[v] + syns[u];
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	for(int i=1; i<n; i++){
		int a,b; cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	DFS(1);
	int x;
	if(n%2==0) x = n/2;
	else x = n/2 + 1;
	
	for(int i = 1; i <= n; i ++){
		bool czy = false;
		if(syns[i] >= x){
			czy = true;
			for(int j = 0; j < G[i].size(); j ++)
				if(syns[G[i][j]] > x && syns[G[i][j]] < syns[i]){
					czy = false;
					break;
				}
		}
		if(czy) cout << i << ' ';
	}
}
