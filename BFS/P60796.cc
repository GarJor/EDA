#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Vi;
typedef vector<char> Vc;
typedef vector<Vc> Graf;
typedef pair<int, int> pos;

Vi X = {-1, 0, 1, 0};
Vi Y = {0, 1, 0, -1};
Graf g;

bool esValid(int x, int y){
   return x >= 0 and x < g.size() and y >= 0 and y < g[0].size() and g[x][y] != 'X';
}

int bfs_busca(int i, int j){
  vector<Vi > dist(g.size(), Vi(g[0].size(),-1));
  queue<pos > Q;
  pos u = make_pair(i,j);
  dist[i][j] = 0;
  Q.push(u);
  while(!Q.empty()){
    u = Q.front(); Q.pop();
    if(g[u.first][u.second] == 't') return dist[u.first][u.second];
    for(int d = 0; d < 4; ++d){
      pos aux;
      aux.first = u.first + X[d];
      aux.second = u.second + Y[d];
      if(esValid(aux.first,aux.second) and dist[aux.first][aux.second] == -1) {
        Q.push(aux);
        dist[aux.first][aux.second] = dist[u.first][u.second] + 1;
      }
    }

  }
  return -1;
}





int main() {
  int row, col;
  cin >> row >> col;
  g = Graf(row, Vc(col));
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j) cin >> g[i][j];
  }
  cin >> row >> col;
  int res = bfs_busca(row-1, col-1);
  if(res != -1) cout << "distancia minima: " << res << endl;
  else cout << "no es pot arribar a cap tresor" << endl;

}
