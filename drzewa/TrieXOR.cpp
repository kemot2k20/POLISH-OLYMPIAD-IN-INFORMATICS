#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long long p2[60];
const int MX = 11000005;
const int MXN = 200005;
bool jest[MX];
int trie[2][MX];
ll in[MXN];
int nr = 0;
int maks = 0;

void add(ll n){
	 int v = 0;
   for(int i = maks; i >= 0; i --){
		 int x = (n>>i)&1;
		  if(!jest[trie[x][v]]){
			  trie[x][v] = ++nr;
			  jest[trie[x][v]] = true;
	   	}
		  v = trie[x][v];
   }
}

ll search(ll n){
	int v = 0, k = maks;
	ll ans = 0;
	
    for(int i = maks; i >= 0; i --){
		int bit = (n>>i)&1;
    	if(bit&1){
    		if(jest[trie[0][v]]) ans += p2[k], v = trie[0][v];
    		else v = trie[1][v];
		}	
		else{
    		if(jest[trie[1][v]]) ans += p2[k], v = trie[1][v];
    		else v = trie[0][v];
    	}
		k --;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; 
  cin>>n;
	ll ans = 0;
	for(int i = 0; i < n; i ++) cin>>in[i];
	
	sort(in, in + n);
	ll najw = in[n-1];
	while(najw) najw/=2, maks ++;
	
	for(int i = 0; i <= maks; i ++) p2[i] = pow(2, i);
	
    for(int i = 0; i < n; i ++){
    ll x = search(in[i]);
		if(ans < x) ans = x;
		add(in[i]);
	}
	cout << ans << '\n';
}
