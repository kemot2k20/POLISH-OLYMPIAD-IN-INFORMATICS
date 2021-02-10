int n; // number of nodes
vector<int> adj[N]; // adjacency list of graph
bool visited[N];
int tin[N], low[N];
vector<pii> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.pb({v, to});
        }
    }
}

void find_bridges() {
    timer = 0;
    fill(tin, tin + n + 1, -1);
    fill(low, low + n + 1, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
