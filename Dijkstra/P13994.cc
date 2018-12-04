#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <stack>

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

void dijkstra(int from, int to){
  int n = llista.size();
  vector<int> d(n,INFINITY);
  vector<int> cami(n,-1);
  vector<bool> vist(n,false);
  d[from] = 0;
  priority_queue<ArcP, Vap, greater<ArcP> > Q;
  Q.push(ArcP(0,from));
  while(!Q.empty() and Q.top().second != to){ //segona condicio necessaria per que la cua no estigui buida per despres fer el frint, tot i k es podria crear un bool auxiliar x exemple....
    int u = Q.top().second; Q.pop();
    if(!vist[u]) {
      vist[u] = true;
      for(int i = 0; i < llista[u].size(); ++i){
        int v = llista[u][i].second;
        int c = llista[u][i].first;
        if(d[u] + c < d[v]){
          d[v] = d[u] + c;

          cami[v] = u;

          Q.push(ArcP(d[v],v));
        }
      }
    }
  }
  if (Q.empty()){
        cout << "no path from " << from << " to " << to << endl;
        return; //surt
    }

    stack<int> resultat;

    while (cami[to] != -1){ //si forma part del path enpila
        resultat.push(to);
        to = cami[to];
    }

    cout << from; //inicialitza el print amb el valor dinici del paz( que no ha quedat a la cua ja k cami[from] == -1)

    while (not resultat.empty()){
        cout << ' ' << resultat.top();
        resultat.pop();
    }

    cout << endl;



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
