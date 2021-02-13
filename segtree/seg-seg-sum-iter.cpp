#include <bits/stdc++.h>
#define INF 1e9
#define INFl 1e18
#define all(x) x.begin(), x.end()
#define sajz(x) (int)x.size()
#define pb push_back
#define s second
#define f first
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
typedef long long LL;
//void build(int v, int tl, int tr) {
    //if (tl == tr) {
        //t[v] = a[tl];
    //} else {
        //int tm = (tl + tr) / 2;
        //build(v*2, tl, tm);
        //build(v*2+1, tm+1, tr);
        //t[v] = max(t[v*2], t[v*2+1]);
    //}
//}

LL p = 19;
const LL leaf = (1 << 19);
LL tree[2 * leaf];
LL lazy[2 * leaf];

///////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////

void apply(LL a, LL v, LL sajz){
	tree[a] += v * sajz;
	lazy[a] += v;
}

void build(LL a){
	LL sajz = 1;
	while(a){
		a /= 2;
		sajz *= 2;
		tree[a] = tree[a * 2] + tree[a * 2 + 1] + lazy[a] * sajz;
	}
}

void push(LL a){
	for(LL j = p; j > 0; j--){
		LL i = (a >> j);
		if(lazy[i]){
			LL sajz = (1 << (j - 1));
			apply(i * 2, lazy[i], sajz);
			apply(i * 2 + 1, lazy[i], sajz);
			lazy[i] = 0;
		}
	}
}

void insert(LL l, LL r, LL v){
	l += leaf;
	r += leaf;
	LL L = l;
	LL R = r;
	
	push(l);
	push(r);
	
	LL sajz = 1;
	apply(l, v, sajz);
	if(l != r) apply(r, v, sajz);
	while(l / 2 != r / 2){
		if(l % 2 == 0) apply(l + 1, v, sajz);
		if(r % 2 == 1) apply(r - 1, v, sajz);
		l /= 2;
		r /= 2;
		sajz *= 2;
	}
	build(L);
	build(R);
}

LL query(LL l, LL r){
	l += leaf;
	r += leaf;
	
	push(l);
	push(r);
	
	LL ans = tree[l];
	if(l != r) ans += tree[r];
	while(l / 2 != r / 2){
		if(l % 2 == 0) ans += tree[l + 1];
		if(r % 2 == 1) ans += tree[r - 1];
		l /= 2;
		r /= 2;
	}
	return ans;
}

int main()																					 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);              
	
	int n;
	cin >> n;
	LL q; cin >> q;
	while(q--){
		LL x;
		cin >> x;
		if(x == 1){
			LL a, b, v;
			cin >> a >> b >> v;
			insert(a, b, v);
		}
		else if(x == 2){
			LL a, b; cin >> a >> b;
			cout << query(a, b) << '\n';
		}
	}
	
	return 0;
}
