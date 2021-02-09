#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int jest[MX];
int trie[9][MX];
string slowa[250005];
int nr = 0, ile = 0;
int let[27] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
int indeks[MX];

void add(string s, int k){
    int v = 0;
    for(int i = 0; i < s.size(); i ++){
    	int x;
    	if(s[i] == ' ') x = 0;
    	else x = let[s[i]-'a'+1]-1;

        if(jest[trie[x][v]] == 0){
            trie[x][v] = ++nr;
            jest[nr] ++;
            indeks[nr] = k;
        }
        else jest[trie[x][v]] ++;
        	
        v = trie[x][v];
    }
}

string search(string kod){
	ile = 0;
	int v = 0;
	int l = 0;
    for(int i = 0; i < kod.size(); i ++){
    	int x = kod[i] - '0'-1;
    	if(jest[trie[x][v]] > 0) ile = jest[trie[x][v]];
		else{
			ile = 0;
			break;
		}
		v = trie[x][v];
		if(i < kod.size()-1) l = v; 
	}
	if(ile == 0) return "NIE";
	if(ile == 1) return slowa[indeks[trie[kod[kod.size()-1]-'0'-1][l]]];
	return "duzo";
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i = 0; i < n; i ++) { cin >> slowa[i]; add(slowa[i], i);}
    while(m--){
    	string kod; cin>>kod;
    	string ans = search(kod);
    	if(ans == "duzo") cout << ile << '\n';
    	else cout << ans << '\n';
	}
}
