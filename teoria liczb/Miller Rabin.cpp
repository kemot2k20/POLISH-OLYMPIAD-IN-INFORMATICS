#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll test[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};

ll safe(ll a, ll b, ll c){
	ll x = 0;
	a %= c;
	while(b){
		if(b&1) x = (x+a)%c;	
		a = (2*a)%c;
		b >>= 1;	
	}
	return x;
}
ll fast_pow(ll a, ll b, ll c) {
  	ll x = 1;
  	a %= c;
  	while(b){
  		if(b&1) x = safe(x, a, c);
  		a = safe(a,a,c);
  		b >>= 1;
	}
	return x;
}
bool miillerTest(ll n, ll a, ll d, ll s) { 
    ll x = fast_pow(a, d, n); 
    if(x == 1 || x == n-1) return true; 
    for(ll i = 1; i < s; i ++){
    	x = safe(x,x,n);
    	if(x == n-1) return true;
	}
    return false; 
}   
bool isPrime(ll n, int k) {
    if(n <= 1 || n == 4) return false; 
    if(n <= 3) return true; 
    ll d = n - 1, s = 0; 
    while((d&1)==0) d >>= 1, s++;
    for(int i = 0; i < k; i++)
        if(!miillerTest(n, test[i], d, s)) return false; 

    return true; 
} 
 
int main(){ 
  	ios::sync_with_stdio(false); cin.tie(0);
  	int k = 20; ll n; cin >> n;
	
	for(int i = 0; i < k; i ++)
		if(n == test[i]){
			cout << "TAK\n";
			return 0;
		}
		
    if(isPrime(n, k)) 
        cout << "TAK\n"; 
    else
    	cout << "NIE\n";
} 
