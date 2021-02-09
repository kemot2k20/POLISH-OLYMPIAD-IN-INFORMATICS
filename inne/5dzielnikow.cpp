// czy liczba ma dokładnie 5 dzielników ? 
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int q; cin>>q;
	while(q--){
		long long x; cin>>x;
		int f = 2, l = 32000;
		bool czy = false;
		
		while(f < l){
			long long mid = (f+l)/2;
			if(mid*mid*mid > 1e18/mid) l = mid;
			if(mid*mid*mid*mid > x) l = mid;
			else if(mid*mid*mid*mid < x) f = mid+1;
			else {
				int div = 2, y = mid;
				while(y>1 && div <= sqrt(y)){
					while(y%div==0) { y/=div; break;}
					div++;
				}
				if(y == mid){
					czy = true;
					cout << "TAK\n";
					break;
				}
				else l = mid;
			}
		}
		if(!czy) cout << "NIE\n";
	}
}
