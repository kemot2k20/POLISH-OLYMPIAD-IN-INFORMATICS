// https://codeforces.com/contest/1902/problem/E

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define ll long long
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 5;
const int p1 = 1e9 + 7;
const int p2 = 1e9 + 9;

unordered_map<long long, int> cnt;

int base1[N], base2[N];
int base;

struct hsh {
    ll val1, val2;
    hsh() {
        val1 = 0;
        val2 = 0;
    }
 
    void push_back(ll v) {
        v++;
        val1 *= base; val1 += v; val1 %= p1;
        val2 *= base; val2 += v; val2 %= p2;
    }
 
    ll get() {
        return val1*p2+val2;
    }
};
 
void prepHash() {
    base = uid(p1/5, p2/2);
 
    base1[0] = 1; base2[0] = 1;
    for (int i = 1; i < N; i ++) {
        base1[i] = (base1[i-1] * base) % p1;
        base2[i] = (base2[i-1] * base) % p2;
    }
}

void dodaj(string& s) {
    int n = s.size();
    hsh h;
    for (int i = 0; i < n; i ++) {
        h.pb(s[i]);
        cnt[h.get()] ++;
    }
}

long long bad(string& s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    hsh h;
    long long res = 0;
    for (int i = 0; i < n; i ++) {
        h.pb(s[i]);
        res += cnt[h.get()];
    }
    return res * 2;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    prepHash();
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
