#include <iostream>
#include <queue>
#include <vector>



using namespace std;

typedef pair<int, int>  ArcP;
typedef vector<ArcP> Vap;



vector<Vap> llista;


void llegir(){
  int u;
  ArcP arc;
  cin >> u >> arc.second >> arc.first;
  llista[u].push_back(arc);

}

void dijkstra(int from, int to){
  int n = llista.size();
  vector<int> d(n,-1);
  vector<int> ways(n,0);
  vector<bool> vist(n,false);
  d[from] = 0;
  ways[from] = 1; //ja que lunic cami es quedarte on ets
  priority_queue<ArcP, Vap, greater<ArcP> > Q;
  Q.push(ArcP(0,from));
  while(!Q.empty()){ //segona condicio necessaria per que la cua no estigui buida per despres fer el frint, tot i k es podria crear un bool auxiliar x exemple....
    int u = Q.top().second; Q.pop();
    if(!vist[u]) {
      vist[u] = true;
      for(int i = 0; i < llista[u].size(); ++i){
        int v = llista[u][i].second;
        int c = llista[u][i].first;
        if(d[v] == -1 or d[u] + c < d[v]){
          d[v] = d[u] + c;
          ways[v] = ways[u];
          Q.push(ArcP(d[v],v));
        }
        else if(d[u] + c == d[v])
          ways[v] += ways[u];
      }
    }
  }
  if (d[to] == -1){
        cout << "no path from " << from << " to " << to << endl;
    }
  else {
    cout << "cost " << d[to] << ", " << ways[to] << " way(s)" << endl;
  }




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
    vector<int> cami;
    cin >> v >> a;
    dijkstra(v,a);


}

}
