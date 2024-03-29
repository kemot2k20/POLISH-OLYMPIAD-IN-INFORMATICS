// wersja O(nlog^2)

vi suffix_array(string &s) {
    s += '$';
    int n = s.size();

    vi g(n), ind(n);
    for (int i = 0; i < n; i ++) ind[i] = i;

    auto cmp = [&](int a, int b) { return s[a] < s[b]; };
    sort(all(ind), cmp);

    for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (s[ind[i]] != s[ind[i-1]]);

    int sz = 1, K = 0;
    while (sz < n) {sz *= 2, K ++;};

    for (int k = 1; k <= K; k ++) {
        vector<pii> val(n);
        for (int i = 0; i < n; i ++) val[ind[i]] = {g[ind[i]], g[(ind[i] + (1 << (k - 1))) % n]};

        auto cmp2 = [&](int a, int b) { return val[a] < val[b]; };
        sort(all(ind), cmp2);

        g[ind[0]] = 0;
        for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (val[ind[i]] != val[ind[i-1]]);
    }

    return ind;
}   


// count_sort z shiftem w lewo (szybsze nlog)

void count_sort(vi& ind, vi& g) {
    int n = ind.size();
    vi cnt(n);
    for (auto x : g) cnt[x]++;
    vi pos(n);
    for (int i = 1; i < n; i ++) pos[i] = pos[i-1] + cnt[i-1];
    vi new_ind(n);
    for (auto x : ind) {
        new_ind[pos[g[x]]] = x;
        pos[g[x]] ++;
    }
    ind = new_ind;
}

vi suffix_array(string &s) {
    s += '$';
    int n = s.size();

    vi g(n), ind(n);
    for (int i = 0; i < n; i ++) ind[i] = i;

    auto cmp = [&](int a, int b) { return s[a] < s[b]; };
    sort(all(ind), cmp);

    for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (s[ind[i]] != s[ind[i-1]]);

    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i ++) ind[i] = (ind[i] - (1 << k) + n) % n;
        count_sort(ind, g);

        vi new_g(n);
        new_g[ind[0]] = 0;
        for (int i = 1; i < n; i ++) {
            pii cur = {g[ind[i]], g[(ind[i] + (1 << k)) % n]};
            pii prev = {g[ind[i-1]], g[(ind[i-1] + (1 << k)) % n]};
            new_g[ind[i]] = new_g[ind[i-1]] + (cur != prev);
        }
        g = new_g;
        k ++;
    }

    return ind;
}   


// radix_sort (wolniejsze nlog)

void radix_sort(vector<pair<pii, int>> &v) {
    int n = v.size();
    for (int rep = 0; rep < 2; rep ++) {
        vi cnt(n);
        for (auto x : v) {
            if (rep == 0) cnt[x.first.second] ++;
            else cnt[x.first.first] ++;
        }
        vi pos(n);
        for (int i = 1; i < n; i ++) pos[i] = pos[i-1] + cnt[i-1];
        vector<pair<pii, int>> new_v(n);
        for (auto x : v) {
            if (rep == 0) {
                new_v[pos[x.first.second]] = x;
                pos[x.first.second] ++;
            } else {
                new_v[pos[x.first.first]] = x;
                pos[x.first.first] ++;
            }
        }

        v = new_v;
    }
}

vi suffix_array(string &s) {
    s += '$';
    int n = s.size();

    vi g(n), ind(n);
    for (int i = 0; i < n; i ++) ind[i] = i;

    auto cmp = [&](int a, int b) { return s[a] < s[b]; };
    sort(all(ind), cmp);

    for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (s[ind[i]] != s[ind[i-1]]);

    int sz = 1, K = 0;
    while (sz < n) {sz *= 2, K ++;};

    for (int k = 1; k <= K; k ++) {
        vector<pair<pii, int>> v(n);
        for (int i = 0; i < n; i ++) v[i] = {{g[i], g[(i + (1 << (k - 1))) % n]}, i};
        radix_sort(v);
        for (int i = 0; i < n; i ++) ind[i] = v[i].second;

        g[ind[0]] = 0;
        for (int i = 1; i < n; i ++) g[ind[i]] = g[ind[i-1]] + (v[i].first != v[i-1].first);
    }

    return ind;
}   
