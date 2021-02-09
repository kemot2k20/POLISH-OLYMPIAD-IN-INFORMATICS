#include <bits/stdc++.h>
using namespace std;
const int MX = 8e6 + 5;

int sqrtN = 2828;
int first[MX];

int main() {
 	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
 	int t; cin>>t;
 	for(int i=2; i <= MAX_N; i++) {	
	 	if(i % 2 == 0) first[i] = 2;
 		else first[i] = i;
    }
    int a;
    for(int i=3; i <= sqrtN; i+=2) {
    	a=i*i;
    	if(first[i] == i) {
    		while(a <= MAX_N) {
    			if(first[a] == a)
    				first[a] = i;
    			a += i;
			}
	    }
	}
	int n, b;
 	while(t--) {
 		cin >> n;
 		b = n;
 		if(n == 1) cout << 1;
		else {
 			while(n > 1) {
 				while(n % first[b]==0) {
 					n /= first[b];
 					cout << first[b] << ' ';
	    		}
	    		b = n;
	    	}
	    }
	    cout << '\n';
	}
}
