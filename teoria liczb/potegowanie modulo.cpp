ll fast_pow(ll a, ll b, ll c) {
	if (b == 0) return 1;
	if (b&1) {
		ll x = fast_pow(a, b / 2, c);
		return ((x * x) % c * a) % c;
	}
	else {
		ll x = fast_pow(a, b / 2, c);
		return (x * x) % c;
	}
}
