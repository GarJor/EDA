#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> P;

// void dfs(int i, int o, VI& erdos, VVI& g){
//   if(erdos[i] == -1 or erdos[o] + 1 < erdos[i]){
//     erdos[i] = erdos[o]+1;
//     for(int k = 0; k < g[i].size(); ++k){
//       if(g[i][k] != o) dfs(g[i][k], i, erdos, g);
//     }
//   }
// }
 void bfs(VI& erdos, vector< unordered_set<int> >& g){
   queue<int> Q;
   Q.push(0);
   erdos[0] = 0;
   while(!Q.empty()){
     int old = Q.front(); Q.pop();
     for(int k : g[old]){
       if(erdos[k] == -1){
         erdos[k] = erdos[old]+1;
         Q.push(k);
       }
     }

   }
 }

int main(){
  int v, t;
  while(cin >> v >> t){
    vector< unordered_set<int> >  graf(v);
    while (--t >= 0) {
      int s;
      cin >> s;
      vector<int> pub(s);
      for (int i = 0; i < s; ++i) cin >> pub[i];
      for(int i = 0; i < s; ++i){
        for(int j = i+1; j < s; ++j) {
          int u = pub[i];
          int v = pub[j];
          graf[u].insert(v);
          graf[v].insert(u);
        }
}
    VI erdos(v,-1);
    bfs(erdos, graf);
    for(int k = 0; k < v; ++k){
      cout << k << " : ";
      if(erdos[k] == -1) cout << "no" << endl;
      else cout << erdos[k] << endl;
    }
    cout << "----------" << endl;
  }

}
