#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 2e7 + 5;
const ll X = 169;
const ll P = 1e9 + 696969;

int main(){
	std::ios::sync_with_stdio(false); 
	cout.tie(0);
	cin.tie(0);
	int n;
	char z;
	scanf("%d\n", &n);
	scanf("%c", &z);
	int i = 1, j = N - 1;
	ll hash1 = 0, hash2 = 0, y = 1;
	while (z != '\n' && z != EOF) {
		ll litera = z - 'a';
		hash1 = (hash1 * X + litera) % P;
		hash2 = (y * litera + hash2) % P;
		y = (y * X) % P;
		i ++, j --;
		scanf("%c", &z);
	}
	if (hash1 == hash2) printf("TAK");
	else printf("NIE");
	return 0;
}
