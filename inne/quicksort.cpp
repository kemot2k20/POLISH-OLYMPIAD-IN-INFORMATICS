#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];

int quick(int l, int r) {
	int ind = (l+r)/2;
	int pivot = a[ind];
	int x = l-1;
	for (int i = l; i <= r-1; i ++) {
		if (a[i] < pivot) swap(a[i], a[++x]);
	}
	swap(a[ind], a[x+1]);
	return x+1;
}
void quickSort(int l, int r) {
	while (l < r) {
		int pos = quick(l, r);
		quickSort(l, pos - 1);
		quickSort(pos + 1, r);
	}
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	quickSort(0, n-1);
	for (int i = 0; i < n; i ++) cout << a[i] << ' ';
	return 0;
}
