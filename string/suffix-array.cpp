vi suffix_array(string &s) {
    s += '$';
    int n = s.size();
 
    vi g(n), ind(n);
    for (int i = 0; i < n; i ++) ind[i] = i;
 
    auto cmp = [&](int a, int b) { return s[a] < s[b]; };
    sort(all(ind), cmp);
 
    for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (s[ind[i]] != s[ind[i-1]]);
 
    int sz = 1, K = 0;
    while (sz <= n) {sz *= 2, K ++;};
 
    for (int k = 1; k <= K; k ++) {
        vector<pii> val(n);
        for (int i = 0; i < n; i ++) val[ind[i]] = {g[ind[i]], g[(ind[i] + (1 << (k - 1))) % n]};
 
        auto cmp2 = [&](int a, int b) { return val[a] < val[b]; };
        sort(all(ind), cmp2);
 
        vi ng(n);
        for (int i = 1; i < n; i ++) ng[ind[i]] = ng[ind[i-1]] + (val[ind[i]] != val[ind[i-1]]);
        g = ng;
    }
 
    return ind;
}   
