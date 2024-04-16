const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100101; 
 
ll base1[MX], base2[MX];
int base;
 
const ll p1 = MOD;
const ll p2 = MOD+2;
 
// If you don't need to query arbitrary ranges,
// only maintain val1 and val2 to save space.
// get() = val1 * p2 + val2
struct hsh {
    ll val1, val2;
    vl val1s, val2s;
    vl nums;
    hsh() {
        val1 = 0;
        val2 = 0;
        val1s.pb(0);
        val2s.pb(0);
    }
 
    void push_back(ll v) {
        v++;
        val1 *= base; val1 += v; val1 %= p1;
        val2 *= base; val2 += v; val2 %= p2;
 
        val1s.pb(val1);
        val2s.pb(val2);
        nums.pb(v);
    }
 
    ll get(int L, int R) {
        ll A = (val1s[R+1] - (val1s[L] * base1[R-L+1]) % p1 + p1) % p1;
        ll B = (val2s[R+1] - (val2s[L] * base2[R-L+1]) % p2 + p2) % p2;
        return A*p2+B;
    }
};
 
void prepHash() {
    base = uid(MOD/5, MOD/2);
 
    base1[0] = 1; base2[0] = 1;
    FOR(i, 1, MX) {
        base1[i] = (base1[i-1] * base) % p1;
        base2[i] = (base2[i-1] * base) % p2;
    }
}
void solve() {
    int N; cin >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    vi sA = A; sort(all(sA));
    hsh hS;
    F0R(i, N) hS.pb(sA[i]);
    hsh hR;
    F0Rd(i, N) hR.pb(sA[i]);
    vi B;
    F0R(i, 2) F0R(j, N) B.pb(A[j]);
    int ans = MOD;
    ll X = hS.get(0, N-1), Y = hR.get(0, N-1);
    hsh hB;
    trav(a, B) hB.pb(a);
    F0R(i, N) {
        ll cur = hB.get(N-i, 2*N-i-1);
        if (cur == X) ckmin(ans, i);
        if (cur == Y) ckmin(ans, i+1);
    }
    reverse(all(B));
    hsh hB2; trav(a, B) hB2.pb(a);
    F0R(i, N) {
        ll cur = hB2.get(N-i, 2*N-i-1);
        if (cur == X) ckmin(ans, i+1);
        if (cur == Y) ckmin(ans, i+2);
    }
    if (ans == MOD) {
        cout << -1 << nl; return;
    }
    cout << ans << nl;
 
}
