#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int P = 1e6;

int pi[P], pl[P], m;
void sieve() {
    m = 0; for(int i = 2; i < P; i++)  pi[i] = 1;
    for(int i = 2; i < P; i++) {
        if(pi[i])   pl[m++] = i;
        for(int j = 0; j < m && pl[j] * i < P; j++) {
            pi[pl[j] * i] = 0;
            if(i % pl[j] == 0)  break;
        }
    }
    for(int i = 2; i < P; i++)  pi[i] += pi[i - 1];
}

map<ll, ll> cache;
ll phi(ll x, ll a) {
  if (a == 1 || !x) return (x + 1) / 2;
  ll &r = cache[(x << 10) + a]; if (r) return r;
  return r = phi(x, a - 1) - phi(x / pl[a - 1], a - 1);
}
ll get_pi(ll n) {
  if (n < P) return pi[n];
  ll a = get_pi(pow(n, .25));
  ll b = get_pi(sqrt(n));
  ll c = get_pi(pow(n, 1./3));
  ll r = phi(n, a) + (b + a - 2) * (b - a + 1) / 2;
  for (int i = a + 1; i <= b; ++i) {
    ll w = n / pl[i - 1];
    r -= get_pi(w);
    if (i <= c) {
      int upp = get_pi(sqrt(w));
      for (int j = i; j <= upp; ++j) r += j - 1 - get_pi(w / pl[j - 1]);
    }
  }
  return r;
}

int main() {
    sieve();
    ll n; cin >> n;
    cout << get_pi(n) << '\n';
}
