#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];

void check(int x, int n) {
	int left = 2*x+1, right = 2*x+2;
	int change = x;
	if (right < n && a[right] < a[change]) change = right;
	if (left < n && a[left] < a[change]) change = left;
	if (change != x) swap(a[change], a[x]), check(change, n);
}

void heapsort(int n) {
	for (int i = n/2-1; i >= 0; i --) check(i, n);
	for (int i = n-1; i >= 0; i --) {
		cout << a[0] << ' ';
		swap(a[0], a[i]);
		check(0, i);
	}
}

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	heapsort(n);
	return 0;
}
