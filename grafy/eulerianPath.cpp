#include <bits/stdc++.h>
using namespace std;

const int MXN = 80005;
int in[MXN];
int odw[MXN];
int n, m;
vector <int> odp;
map <pair<int, int>, int> M;

void eulerian_path(int v){
	for(int i = 1; i <= n; i++)
        while(M[make_pair(v, i)]){
            M[make_pair(v, i)] --;
            M[make_pair(i, v)] --;
            eulerian_path(i);
        }
    odp.push_back(v);
    odw[v] = true;
}

bool czy_spojny(int start){
	for(int i = 1; i <= n; i ++)
		if(!odw[i]) return false;
		
	return true;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i ++){
		int a,b; cin>>a>>b;
		M[make_pair(a, b)] ++;
		M[make_pair(b, a)] ++;
		in[a] ++;
		in[b] ++;
	}
	
	int even = 0, odd = 0, izolowane = 0;
	int x = 0;
	int wierzcholek = 0;
	
	for(int i = 1; i <= n; i ++){
		if(in[i] > 0){
			if(wierzcholek == 0) wierzcholek = i;
			if(in[i]%2==0) even ++;
			else {
				odd ++;
				if(x == 0) x = i;
			}
		}
		else izolowane ++, odw[i] = true;
	}
	if(odd == 2 && even == n-izolowane-2){
		eulerian_path(x);
		if(czy_spojny(wierzcholek)){
		for(int i = odp.size()-1; i >= 0; i --) cout << odp[i] << ' '; 
		return 0;
		}
		else cout << -1 << '\n';
	}
	else if(even == n-izolowane && odd == 0){
		eulerian_path(1);
		if(czy_spojny(wierzcholek)){
		for(int i = odp.size()-1; i >= 0; i --) cout << odp[i] << ' '; 
		return 0;
		}
		else cout << -1 << '\n';
	}
	else cout << -1 << '\n';
}
