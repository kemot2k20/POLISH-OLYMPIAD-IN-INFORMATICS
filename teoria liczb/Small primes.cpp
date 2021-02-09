vector<int> Primes(int n) {
	vector<bool> P(n + 1, true);
	for (int i = 2; i * i <= n; i ++)
		if (P[i])
			for (int j = i * i; j <= n; j += i)
				P[j] = false;
	
	vector<int> wyn;
	for (int i = 2; i <= n; i ++) if (P[i]) wyn.push_back(i);
	return wyn;
}
