#include <bits/stdc++.h>																							   
																									   
using namespace std; 																								   
		
const double eps = 1e-9;																							   
const int INF = 1e9 + 5;
const long long INFL = 1e18;																					   
const double PI = 3.14;
const int mod = 1e9 + 7;																								   
typedef long long LL;																								   
																													   
typedef vector<int> vi;																								   
typedef list<int> li;																								   
typedef queue<int> qi; 																								   
typedef pair<int,int> ii;
typedef pair<LL, LL> ll; 																							   
typedef map<string,int> msi;
typedef set<int> sett;												   
typedef vector<ii> vii; 		   
typedef priority_queue< ii, vector<ii>, greater<ii> > pq;    																								   																				   
vector<ii>::iterator iter;																							   
																													   																				   										   
#define pb push_back																							   
#define pf push_front																							   
#define mp(x, y) make_pair(x, y)
#define size(x) (int)x.size()
#define endl '\n'

int _X[] = {0, 1, 1, 1, 0, -1, -1, -1};
int _Y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int _X2[] = {1, 0, -1, 0};
int _Y2[] = {0, 1, 0, -1};

//FILE I/O
void FILE_OI(){
	fstream plik;
	plik.open("plik.txt"); //create plik.txt!
	plik << "_put here your input_";
	plik.close();
}

//DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif      
                                                              
///////////////////////////////////////////////GLOBAL DEFINITIONS////////////////////////////////////////////////////////

long long int rand(long long int a, long long int b){
	return a + rand() % (b - a + 1);
}

struct generatorka{
	//NUMBERS
	void number_gen(){
		long long int n = rand(1, 10); //ile liczb
		cout << n << endl;
		set<long long int> used;
		for(long long int i = 0; i < n; i++){
			long long int x;
			do{
				x = rand(1, 100); //zakres liczby
			}while(used.count(x));
			cout << x << " ";
			used.insert(x);
		}
	}
	//PERMUTATIONS
	void perm_gen(){
		long long int n = rand(1, 10); //ile liczb
		vector<long long int> perm;
		for(long long int i = 1; i <= n; i++) perm.pb(i); //permutacja liczb od 1 do n
		random_shuffle(perm.begin(), perm.end());
		cout << n << endl;
		for(auto it : perm) cout << it << " ";
	}
	///STRINGS
	void string_gen(){
		long long int n = 2; //ile stringów
		const long long int len = 10; //dlugosc stringa
		while(n--){
			string tmp_s;
			static const char alphanum[] =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"; //alfabet

			tmp_s.reserve(len);
			for (long long int i = 0; i < len; ++i) 
				tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
			
			cout << tmp_s << endl;
		}
	}
	//MATRIX
	void matrix_gen(){
		//matrix [n*m]
		long long int n = 5;
		long long int m = 5;
		cout << n << " " << m << endl;
		for(long long int i = 1; i <= n; i++){
			for(long long int j = 1; j <= m; j++){
				cout << rand(1, 10) << " "; //zakres liczb
			}
			cout << endl;
		}
	}
	//TREES
	void random_tree(){
		long long int n = 10; //ilosc wierzchołków
		cout << n << endl;
		vector<pair<long long int, long long int> > edges;
		for(long long int i = 2; i <= n; i++){
			edges.emplace_back(rand(1, i-1), i);
		}
		vector<long long int> perm(n+1);
		for(long long int i = 1; i <= n; i++){
			perm[i] = i;
		}
		random_shuffle(perm.begin()+1, perm.end());
		random_shuffle(edges.begin(), edges.end());
		for(auto it : edges){
			if(rand() % 2) swap(it.first, it.second);
			cout << it.first << " " << it.second << endl;
		}
	}
	void star_tree(){
		long long int n = 10; //ilosc wierzchołków
		cout << n << endl;
		for(long long int i = 2; i <= n; i++){
			cout << 1 << " " << i << endl;
		}
	}
	void path_tree(){
		long long int n = 10; //ilosc wierzchołków
		cout << n << endl;
		for(long long int i = 2; i <= n; i++){
			cout << i - 1 << " " << i << endl;
		}
	}
	void binary_tree(){
		long long int n = 10; //ilosc wierzchołków
		cout << n << endl;
		for(long long int i = 2; i <= n; i++){
			cout << i / 2 << " " << i << endl;
		}
	}
	void caterpillar_tree(){
		long long int n = 10; //ilosc wierzchołków
		cout << n << endl;
		long long int m = n / 2;
		long long int licznik = n / 2;
		for(long long int i = 2; i <= m; i++){
			cout << i - 1 << " " << i << endl;
		}
		long long int idx = m;
		while(licznik){
			long long int x = rand(1, m);
			long long int ilosc = min(licznik, rand(1, 3));
			licznik = max(0LL, licznik - ilosc);
			for(long long int i = 1; i <= ilosc; i++){
				cout << x << " " << ++idx << endl;
			}
		}
	}
	//GRAPHS
	vector<pair<long long int, long long int> > rand_graph_tree(int n){
		vector<pair<long long int, long long int> > edges;
		for(long long int i = 1; i < n; i++) {
			edges.pb(mp(rand(0, i - 1), i));
		}
		return edges;
	}
	void graph_gen(){
		long long int n = 10; //ilosc wierzchołków
		long long int m = 10; //ilosc krawedzi;
		cout << n << " " << m << endl;
		
		vector<pair<long long int, long long int> > graph;
		set<pair<long long int, long long int> > edges;
		long long int licznik = 0;
		while(licznik < n && m > 0) {
			long long int current = rand(1, min(m + 1, n - licznik));
			vector<pair<long long int, long long int> > tree = rand_graph_tree(current);
			for(auto &it : tree){
				edges.insert(mp(it.first + licznik, it.second + licznik));
			}
			licznik += size(tree) + 1;
			m -= size(tree);
		}
		while(m > 0) {
			long long int u, v;
			do{
				u = rand(0, n - 2);
				v = rand(u + 1, n - 1);
			} while(edges.count(mp(u, v)));
			edges.insert(mp(u, v));
			m--;
		}
		for(auto it : edges){
			cout << it.first + 1 << " " << it.second + 1 << endl;
		}
	}
};

int main(int argc, char* argv[])																				 
{ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                  												       
	
	srand(atoi(argv[1]));
		
	return 0;
}
