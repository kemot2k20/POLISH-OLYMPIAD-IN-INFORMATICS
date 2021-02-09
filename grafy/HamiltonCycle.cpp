#include <bits/stdc++.h>

using namespace std;
int n, m;
int graph[2005][2005];
int path[2005];

void displayCycle(){
    cout << "TAK" << '\n';
   for(int i = 0; i < n; i++)
      cout << path[i]+1 << " ";
}

bool isValid(int v, int k) {
   if (graph [path[k-1]][v] == 0)   
      return false;

   for (int i = 0; i < k; i++)   
      if (path[i] == v)
         return false;
         
   return true;
}

bool cycleFound(int k) {
   if (k == n){
      if(graph[path[k-1]][ path[0] ] == 1)
         return true;
      else
         return false;
   }

   for (int v = 1; v < n; v++) {       
      if (isValid(v,k)) {               
         path[k] = v;
         if (cycleFound (k+1) == true)
            return true;
         path[k] = -1;         
      }
   }
   return false;
}

bool hamiltonianCycle() {
   for (int i = 0; i < n; i++)
      path[i] = -1;
      
   path[0] = 0; //first vertex as 0

   if (cycleFound(1) == false) {
      cout << "NIE" << '\n';
      return false;
   }

   displayCycle();
   return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    
    hamiltonianCycle();
}
