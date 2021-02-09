#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<int> graph[50005];
vector<int> heavy[50005];
set<pair<int, int> > heavyEdges;
int singleChanges[50005];
int subTreeSize[50005];
int parent[50005];
pair<int, int> treeOverNode[50005];
bool vis[50005];

int preorder[50005];
int cpre = 0;

int postorder[50005];
int cpost = 0;

struct rTree{
	rTree(int _base) : base(_base){
		for(int i = 0; i < base * 2; i++) treeArray.push_back(0);	
	}
	
	int base;
	vector<int> treeArray;
	unordered_set<int> includedNodes;
	int highest;
	
	void modify(int c, int first, int last, int node = 1, int nodeFirst = 0, int nodeLast = -1){
		//if(nodeLast == -1) cout << "TREE REQUESTED MOD " << first << ' ' << last <<  " (ID: " << highest << ", " << includedNodes.size() << ")\n";
		if(nodeLast == -1) nodeLast = base - 1;
		if(last < nodeFirst || first > nodeLast) return;
		if(first <= nodeFirst && nodeLast <= last){
			treeArray[node] += c;
			return;
		}
		modify(c, first, last, node * 2, nodeFirst, nodeFirst + (nodeLast - nodeFirst) / 2);
		modify(c, first, last, node * 2 + 1, nodeFirst + (nodeLast - nodeFirst) / 2 + 1, nodeLast);
	}
	
	int get(int pos){
		pos += base;
		int result = 0;
		while(pos != 0){
			result += treeArray[pos];
			pos /= 2;
		}
		return result;
	}
};

vector<rTree> hldTrees;

void dfs(int w){
	preorder[w] = cpre++;
	subTreeSize[w] = 1;
	
	int heaviest = -1;
	int heaviestSts;
	
	vis[w] = true;
	for(int i : graph[w]) if(!vis[i] && i != parent[w]){
		parent[i] = w;
		dfs(i);
		subTreeSize[w] += subTreeSize[i];
		if(heaviest == -1 || subTreeSize[i] > heaviestSts){
			heaviest = i;
			heaviestSts = subTreeSize[i];
		}
	}
	if(heaviest != -1){
		heavy[heaviest].push_back(w);
		heavy[w].push_back(heaviest);
		heavyEdges.insert({w, heaviest});
		heavyEdges.insert({heaviest, w});
	}
	postorder[w] = cpost++;
}

int tSize;

int hldDfs(int w, unordered_set<int>* r, int nTree, int iteration = 0){
	vis[w] = true;
	tSize++;
	r->insert(w);
	treeOverNode[w] = {nTree, iteration};
	int hmax = -1;
	bool anyLeft = false;
	for(int i : heavy[w]){
		if(!vis[i]){
			anyLeft = true;
			hmax = max(hmax, hldDfs(i, r, nTree, iteration + 1));
		} 
	}
	if(!anyLeft) return w;
	else return hmax;
	
}

int jumps[50005][35];

void preCalcLca(){
	for(int i = 0; i < 35; i++) jumps[0][i] = -1;
	for(int j = 1; j < n; j++) jumps[j][0] = parent[j];
	for(int i = 1; i < 35; i++) for(int j = 1; j < n; j++){
		if(jumps[j][i - 1] == -1) jumps[j][i] = -1;
		else jumps[j][i] = jumps[jumps[j][i - 1]][i - 1];
	}
}

bool isAncestor(int x, int anc){
	if(x == -1 || anc == -1) return false;
	return preorder[anc] < preorder[x] && postorder[anc] > postorder[x];
}

int lca(int x, int y){
	if(isAncestor(x, y)) return y;
	if(isAncestor(y, x)) return x;
	int jumpPow = 30;
	while(true){
		if(!isAncestor(y, x) && isAncestor(y, parent[x])) break;
		if(jumps[x][jumpPow] == -1 || isAncestor(y, jumps[x][jumpPow])) jumpPow--;
		else x = jumps[x][jumpPow];
	}	
	return parent[x];
}

void change(int x, int nParent){
	//cout << "CHANGE REQUEST:\n";
	while(x != nParent){
		while(heavyEdges.find({x, parent[x]}) == heavyEdges.end() && x != nParent){
			singleChanges[x]++;
			x = parent[x];	
		} 
		if(x == nParent) break;
		//cout << "CSTATE: " << x << ' ' << nParent << "\n";
		if(heavyEdges.find({x, parent[x]}) != heavyEdges.end()){
			rTree* currentTree = &hldTrees[treeOverNode[x].first];
			if(currentTree->includedNodes.find(nParent) != currentTree->includedNodes.end()){
				currentTree->modify(1, treeOverNode[x].second, treeOverNode[nParent].second - 1);
				return;
			}
			else currentTree->modify(1, treeOverNode[x].second, currentTree->base - 1);
			x = parent[currentTree->highest];
		}
		else x = parent[x];
	}
	return;
}

int tint1, tint2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < 50005; i++) treeOverNode[i] =  {-1, -1};
	
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		cin >> tint1 >> tint2;
		tint1--;
		tint2--;
		graph[tint1].push_back(tint2);
		graph[tint2].push_back(tint1);
	}
	
	dfs(0);
	//cout << "DFS DONE\n";
	for(int i = 0; i < 50005; i++) vis[i] = false;
	//cout << "ORDERS:\n";
	//for(int i = 0; i < n; i++) cout << i << ' ' << preorder[i] << ' ' << postorder[i] << "\n";
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		if(heavy[i].size() != 1) continue;
		if(heavy[i][0] != parent[i]) continue;
		tSize = 0;
		unordered_set<int> tset;
		int chigh = hldDfs(i, &tset, hldTrees.size());
		int p = 1;
		while(p < tSize) p *= 2;
		hldTrees.emplace_back(p);
		hldTrees[hldTrees.size() - 1].includedNodes = tset;
		hldTrees[hldTrees.size() - 1].highest = chigh;
	}
	/*cout << "HLDT DONE\n";
	for(auto t : hldTrees){
		cout << "TREE: " << t.base << " = ";
		for(auto i : t.includedNodes) cout << i << ' ';
		cout << "\n";
	}*/
	//cout << "NODE->TREE:\n";
	//for(int i = 0 ; i < n; i++) cout << i << ' ' << treeOverNode[i].first << ' ' << treeOverNode[i].second << "\n";
	preCalcLca();
	//cout << "PRELCA DONE\n";
	for(int i = 0; i < k; i++){
		cin >> tint1 >> tint2;
		tint1--;
		tint2--;
		int u = lca(tint1, tint2);
		//cout << "QUERY: " << tint1 << ' ' << tint2 << ' ' << u << "\n";
		if(tint1 != u) change(tint1, u);
		if(tint2 != u) change(tint2, u);
		singleChanges[u]++;
	}
	
	int maxFlow = -1;
	for(int i = 0; i < n; i++){
		//cout << "CALCULATING FOR " << i << "\n";
		if(treeOverNode[i].first != -1) maxFlow = max(maxFlow, singleChanges[i] + hldTrees[treeOverNode[i].first].get(treeOverNode[i].second));
		else maxFlow = max(maxFlow, singleChanges[i]);
	}
	cout << maxFlow;
	return 0;
}
