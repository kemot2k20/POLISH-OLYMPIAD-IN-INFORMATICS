// https://codeforces.com/contest/1902/problem/E

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int ALP = 27;

vector<int> cnt({0});
vector<vector<int>> t({vector<int>(ALP, -1)});

void dodaj(string& s) {
    int n = s.size(), v = 0;
    for (int i = 0; i < n; i ++) {
        int x = s[i]-'a';
        if (t[v][x] == -1) {
            t[v][x] = t.size();
            t.push_back({vector<int>(ALP, -1)});
            cnt.push_back(0);
        }
        cnt[t[v][x]] ++;
        v = t[v][x];
    }
}

long long bad(string& s) {
    reverse(s.begin(), s.end());
    int n = s.size(), v = 0;
    long long res = 0;
    for (int i = 0; i < n; i ++) {
        int x = s[i]-'a';
        if (t[v][x] == -1) break;
        res += cnt[t[v][x]];
        v = t[v][x];
    }
    return res * 2;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int n;
    cin >> n;

    vector<string> s(n);
    int sum_len = 0;
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
        dodaj(s[i]);
        sum_len += s[i].size();
    }
    long long ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += 1LL * n * s[i].size() + sum_len;
        ans -= bad(s[i]);
    }

    cout << ans << '\n';
}
