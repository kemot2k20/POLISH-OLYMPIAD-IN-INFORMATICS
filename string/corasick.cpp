#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef queue<int> qi;

const int MX = 1005 * 1005; // suma dlugosci wzorcow
const int ALP = 26 + 1; // dlugosc alfabetu
const int FAIL = -1; // nie znalezione
const int MX_LENGTH = 1e6 + 5; // maksymalna dlugosc slowa

int n;
int f[MX];
int new_state;
int trie[MX][ALP];
vi output[MX];
string text;

void add_to_trie(string word, int index) {
    int wordsize = word.size(), state = 0, j;
    for (j = 0; j < wordsize; j++) {
        int c = word[j] - 'a';
        if (trie[state][c] == FAIL) break;
        state = trie[state][c];
    }

    for (; j < wordsize; j++) {
        int c = word[j] - 'a';
        new_state++;
        trie[state][c] = new_state;
        state = new_state;
    }

    output[state].push_back(index);
}

void read_patterns() {
	for (int i = 0; i < n; i++) {
        string word; cin >> word;
        add_to_trie(word, i);
    }
}

int count_occurrences() {
	int state = 0, ans = 0, textsize = text.size();
    for (int i = 0; i < textsize; i++) {
        int a = text[i] - 'a';
        while (trie[state][a] == FAIL) {
            state = f[state];
		}
        state = trie[state][a];
        int outsize = output[state].size();
        for (int k = 0; k < outsize; k ++) ans ++;
    }
    
    return ans;
}

void failure() {
	qi Q;
    for (int a = 0; a < ALP; a ++) {
        int s = trie[0][a];
        if (s != 0) {
            Q.push(s);
            f[s] = 0;
        }
    }

    while (!Q.empty()) {
        int r = Q.front();
        Q.pop();
        for (int a = 0; a < ALP; a ++) {
            int s = trie[r][a];
            if (s != FAIL) {
                Q.push(s);
                int state = f[r];
                while (trie[state][a] == FAIL) {
                    state = f[state];
				}
                f[s] = trie[state][a];
                int outsize = output[f[s]].size();
                for (int k = 0; k < outsize; k++)
                    output[s].push_back(output[f[s]][k]);
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	new_state = 0;
    memset(trie, -1, sizeof trie);
    memset(f, -1, sizeof f);
    
    read_patterns();
    cin >> text;
    
    for (int i = 0; i < ALP; i ++) {
        if (trie[0][i] == FAIL) trie[0][i] = 0;
    }
	
	failure();
	cout << count_occurrences() << '\n';
	
    return 0;
}
