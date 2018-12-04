#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int, int>  ArcP;
typedef vector<ArcP> Vap;

int const INFINITY = numeric_limits<int>::max();

vector<Vap> llista;


void llegir(){
  int u;
  ArcP arc;
  cin >> u >> arc.second >> arc.first;
  llista[u].push_back(arc);

}

int dijkstra(int from, int to){
  int n = llista.size();
  vector<int> d(n,INFINITY);
//  vector<int> p(n,-1); //poder no ho necessito, crec k es el path
  vector<bool> vist(n,false);
  d[from] = 0;
  priority_queue<ArcP, Vap, greater<ArcP> > Q;
  Q.push(ArcP(0,from));
  while(!Q.empty()){
    int u = Q.top().second; Q.pop();
    if(!vist[u]) {
      vist[u] = true;
      if(u == to) return d[u];
      for(int i = 0; i < llista[u].size(); ++i){
        int v = llista[u][i].second;
        int c = llista[u][i].first;
        if(d[u] + c < d[v]){
          d[v] = d[u] + c;
          //p[v] =  u; efectivament
          Q.push(ArcP(d[v],v));
        }
      }
    }
  }
  return -1;
}


int main() {
  int v;
  while(cin >> v) {
    llista = vector<Vap>(v);
    int a;
    cin >> a;
    while(a > 0){
      llegir();
      --a;
    }

    cin >> v >> a;
    int ret = dijkstra(v,a);
    if(ret != -1) cout << ret << endl;
    else cout << "no path from " << v << " to " << a << endl;
  }



}
