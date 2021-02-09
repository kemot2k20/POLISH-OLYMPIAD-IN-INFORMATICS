#include <iostream>
#include <queue>
using namespace std;
const int MX = 1e3 + 5;

char plansza[MX][MX];
int odw[MX][MX];
int odl[MX][MX];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int> > kolejka;

bool czy_sensowne(int x, int y, int n, int m) {
	if(x<0 || x>=n) return 0;
	if(y<0 || y>=m) return 0;
	if(odw[x][y] == 0 && plansza[x][y] != '#') return 1;
	return 0;
}

void bfs(int sx, int sy, int n, int m) {
	odw[sx][sy]=1;
	odl[sx][sy]=0;
	kolejka.push(make_pair(sx,sy));
	while(!kolejka.empty()) {
		pair<int, int> w=kolejka.front();
		kolejka.pop();
		int x=w.first;
		int y=w.second;
		for(int i=0; i<4; i++) {
			int new_x=x+dx[i];
			int new_y=y+dy[i];
			if(czy_sensowne(new_x, new_y, n, m)) {
				kolejka.push(make_pair(new_x, new_y));
				odw[new_x][new_y]=1;
				odl[new_x][new_y]=odl[x][y]+1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int w, k, x, y, a, b; cin >> w >> k;
	for(int i=0 ;i<w; i++) {
		for(int j=0; j<k; j++) {
			cin>>plansza[i][j];
			if(plansza[i][j]=='M') {
				x=i;
				y=j;
			}
			if(plansza[i][j]=='S') {
                a=i;
                b=j;
            }
		}
	}
    bfs(a,b,w,k);

    if(odw[x][y] == 1) cout << odl[x][y];
    else cout<<"NIE\n";

    return 0;
}
