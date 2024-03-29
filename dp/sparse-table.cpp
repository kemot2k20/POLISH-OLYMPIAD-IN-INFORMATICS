const int N = 4e5 + 5;
const int K = 19;

int st[N][K+1], lg[N];

void calc_st(vi& a) {
    int n = a.size();
    lg[1] = 0;
    for (int i = 2; i <= n; i ++) lg[i] = 1 + lg[i/2];
    for (int i = 0; i < n; i ++) st[i][0] = a[i];
    for (int k = 1; k <= K; k ++)
        for (int i = 0; i + (1<<(k-1)) < n; i ++) 
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
}

int query(int l, int r) {
    int i = lg[r - l + 1];
    return min(st[l][i], st[r - (1 << i) + 1][i]);
}
