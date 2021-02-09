#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MX = 1e5 + 5;

bool vis[MX];
priority_queue<pair<int,int> ,vector< pair<int,int> >, greater<pair<int,int> > > Q;
vector <pair<int,int> > G[MX];
int minimal_path[MX];

void Dijkstra(int v){
    vis[v] = true;
    Q.push({0, v});

    while(!Q.empty()){
        pair <ll, int> x = Q.top(); Q.pop();
        int price = x.first;
        int w = x.second;
        for(int i = 0; i < (int) G[w].size(); i ++){
            int u = G[w][i].first;
            int droga = price + G[w][i].second;
            if (!vis[u] && minimal_path[u] > droga) {
                minimal_path[u] = droga;
                Q.push({minimal_path[u], u});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }
    
    Dijkstra(1);

    return 0;
}
