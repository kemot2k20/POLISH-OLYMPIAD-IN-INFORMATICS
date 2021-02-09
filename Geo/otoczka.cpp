#include <bits/stdc++.h>							   
using namespace std;

typedef long long LL;							   
const int INF = 1e9 + 7;
const double eps = 1e-9;

struct punkt{
	double x, y;
	punkt(){}
	punkt(double X, double Y){
		x = X;
		y = Y;
	}
};

struct wektor{
	double x, y;
	wektor(){}
	wektor(int X, int Y){
		x = X;
		y = Y;
	}
	wektor(punkt a, punkt b){
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

double dystans(punkt a, punkt b){
	return 1LL * abs(a.x - b.x) * abs(a.x - b.x) + 1LL * abs(a.y - b.y) * abs(a.y - b.y);
}

double iloczyn_wektorowy(wektor a, wektor b){
	return a.x * b.y - a.y * b.x;
}

int orientacja(punkt a, punkt b, punkt c){
	LL t = iloczyn_wektorowy(wektor(a, b), wektor(a, c));
	if(fabs(t) < eps) return 0;
	if(t < 0) return -1;
	return 1;
}

punkt punkt_globalny(0, 0);

bool cmp_otoczka(punkt a, punkt b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
vector<punkt> punkty;

vector<punkt> otoczka(vector<punkt> P){	
	sort(P.begin(), P.end(), cmp_otoczka);
	
	vector<punkt> G; //gorna czesc
	for(int i = 0; i < P.size(); i++){
		while(G.size() >= 2 && orientacja(G[G.size() - 2], G[G.size() - 1], P[i]) != -1) G.pop_back();
		G.push_back(P[i]);
	}

	vector<punkt> D; //dolna czesc
	for(int i = P.size()-1; i >= 0; i--){
		while(D.size() >= 2 && orientacja(D[D.size() - 2], D[D.size() - 1], P[i]) != -1) D.pop_back();
		D.push_back(P[i]);
	}

	vector<punkt> R = G; 
	for(int i = 1; i < D.size(); i++){
		R.push_back(D[i]);
	}
	return R;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);    
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		punkty.push_back(punkt(x, y));
	}
	
	vector<punkt> wynik = otoczka(punkty);
}
