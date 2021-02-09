#include <bits/stdc++.h>
#define f first
#define s second
#define ff first.first
#define fs first.second
using namespace std;
typedef pair<int,int> pii;
const int MX = 1e5 + 5;

unordered_map <int, int> M;
pair <pii, int> q[MX];
int ans[MX];
int ciag[MX];
int kubelki; // trick z podzialem na kubelki

bool comp(pair <pii, int> a, pair <pii, int> b){
    int c = a.ff/kubelki;
    int d = b.ff/kubelki;
    if(c < d) return true;
    if(c == d) return a.fs > b.fs;
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n; kubelki = 300;
    for(int i = 1; i <= n; i ++) cin>>ciag[i];
    int Q; cin>>Q;

    for(int i = 1; i <= Q; i ++){
        int a,b; cin>>a>>b;
        q[i].f = make_pair(a, b);
        q[i].s = i;
    }
    
    sort(q+1, q + Q+1, comp);
    int lewa = q[1].ff; int prawa = q[1].fs; int ile = 0;
    for(int i = lewa; i <= prawa; i ++){
        M[ciag[i]] ++;
        if(M[ciag[i]] == 1) ile ++;
    }
    ans[q[1].s] = M.size();
    
    for(int i = 2; i <= Q; i ++){
        int x = q[i].ff; int y = q[i].fs;
        while (lewa < x){
            M[ciag[lewa]] --;
            if(M[ciag[lewa]] == 0) ile --;
            lewa ++;
        }
        while (lewa > x){
            lewa --, M[ciag[lewa]] ++;
            if(M[ciag[lewa]] == 1) ile ++;
        }
        while (prawa > y){
            M[ciag[prawa]] --;
            if(M[ciag[prawa]] == 0) ile --;
            prawa --; 
        }
        while (prawa < y){
            prawa ++; M[ciag[prawa]] ++;
            if(M[ciag[prawa]] == 1) ile ++;
        }
        ans[q[i].s] = ile;
        lewa = x; prawa = y;
    }
    for(int i = 1; i <= Q; i ++) cout << ans[i] << '\n';
}
