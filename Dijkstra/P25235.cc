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
  vector<int> steps(n,-1);
  vector<bool> vist(n,false);
  d[from] = 0;
  steps[from] = 0;
  priority_queue<ArcP, Vap, greater<ArcP> > Q;
  Q.push(ArcP(0,from));
  while(!Q.empty()){ //segona condicio necessaria per que la cua no estigui buida per despres fer el frint, tot i k es podria crear un bool auxiliar x exemple....
    int u = Q.top().second; Q.pop();

      for(int i = 0; i < llista[u].size(); ++i){
        int v = llista[u][i].second;
        int c = llista[u][i].first;
        if(d[v] == -1 or d[u] + c < d[v] or (d[u] + c == d[v] and steps[u] + 1 < steps[v])){
          d[v] = d[u] + c;
          steps[v] = steps[u] + 1;

          Q.push(ArcP(d[v],v));
        }
      }
  }
  if (d[to] == -1){
        cout << "no path from " << from << " to " << to << endl;
    }
  else {
    cout << "cost " << d[to] << ", " << steps[to] << " step(s)" << endl;
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
