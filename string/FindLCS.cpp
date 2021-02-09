#include <bits/stdc++.h>
using namespace std;
const int MX = 5e3 + 5;

int tab[MX][MX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    
    int x = a.size();
    int y = b.size();
    int z = max(x, y);
    
    for(int i = 1; i <= z; i++) {
        for(int j = 1; j <= z; j++) {
           	if(a[j-1] == b[i-1])
           		tab[j][i] = tab[j-1][i-1] + 1;
           	else
           		tab[j][i] = max(tab[j][i-1], tab[j-1][i]);
       	}
   	}
	
	int o = y;
	int p = x;
	string ans = "";

	while(o > 0 && p > 0) {
		if(a[p-1] == b[o-1]) {
			ans.push_back(a[p-1]);
			o --; p --;
		}
		else {
			if(tab[p][o-1] > tab[p-1][o])
				o --;
			else
				p --;
		}
	}
	
	for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];
	return 0;
}
