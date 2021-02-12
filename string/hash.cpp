const int N = 2005;
const int X = 199;
const int mod = 1234567891;

int hasz[N];
int potx[N];

void count_hash(string& s, int n) {
	potx[0] = 1;
	for (int i = 1; i <= n; i ++) potx[i] = (1LL * X * potx[i - 1]) % mod;
	hasz[n] = 0;
	for (int i = n - 1; i >= 0; i --) hasz[i] = ((s[i] - 'a' + 1) + 1LL * X * hasz[i + 1]) % mod;
}

int get_hash(int l, int r) {
	return (hasz[l] - (1LL * potx[r - l + 1] * hasz[r + 1]) % mod + mod) % mod;
}
