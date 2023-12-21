struct edge
{
    int y, c, w, f;
    edge() {};
    edge(int y, int c, int w, int f) : y(y), c(c), w(w), f(f) {};
};

vector<edge> e;
vector<int> g[N];

int rem(int x)
{
    return e[x].c - e[x].f;
}

void add_edge(int x, int y, int c, int w)
{
    g[x].push_back(e.size());
    e.push_back(edge(y, c, w, 0));
    g[y].push_back(e.size());
    e.push_back(edge(x, 0, -w, 0));
}

int n, m, s, t, v;

pair<int, long long> MCMF()
{
    int flow = 0;
    long long cost = 0;
    while(true)
    {
        vector<long long> d(v, (long long)(1e18));
        vector<int> p(v, -1);
        vector<int> pe(v, -1);
        queue<int> q;
        vector<bool> inq(v);
        q.push(s);
        inq[s] = true;
        d[s] = 0;
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            inq[k] = false;
            for(auto ei : g[k])
            {
                if(rem(ei) == 0) continue;
                int to = e[ei].y;
                int w = e[ei].w;
                if(d[to] > d[k] + w)
                {
                    d[to] = d[k] + w;
                    p[to] = k;
                    pe[to] = ei;
                    if(!inq[to])
                    {
                        inq[to] = true;
                        q.push(to);
                    }
                }
            }
        }
        if(p[t] == -1) break;
        flow++;
        cost += d[t];
        int cur = t;
        while(cur != s)
        {
            e[pe[cur]].f++;
            e[pe[cur] ^ 1].f--;
            cur = p[cur];
        }
    }
    return make_pair(flow, cost);
}
