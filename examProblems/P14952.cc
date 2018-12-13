#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void toposort(VVI& list, int v){
  VI graus(v,0);
  for(int i = 0; i < v; ++i){
    for(int j = 0; j < list[i].size(); ++j) ++graus[list[i][j]];
  }
  priority_queue<int, vector<int>, greater<int> > Q;
  for(int i = 0; i < v; ++i){
    if(graus[i] == 0) Q.push(i);
  }
  if(!Q.empty()){
    int g = Q.top(); Q.pop();
    cout  << g;
    for(int i = 0; i < list[g].size(); ++i){
      --graus[list[g][i]];
      if(graus[list[g][i]] == 0) Q.push(list[g][i]);
    }
  while(!Q.empty()){
    int g = Q.top(); Q.pop();
    cout  << ' ' << g;
    for(int i = 0; i < list[g].size(); ++i){
      --graus[list[g][i]];
      if(graus[list[g][i]] == 0) Q.push(list[g][i]);
    }
  }
  }
  cout << endl;

}

int main() {
  int v, a;
  while(cin >> v >> a){
    VVI list(v);
    for(int i = 0; i < a; ++i){
      int u, w;
      cin >> u >> w;
      list[u].push_back(w);
    }
    toposort(list, v);
  }
}
