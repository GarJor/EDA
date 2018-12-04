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
  queue<pair<int,int> > Q;
	vector<vector<int> > dist(g.size(), vector<int>(g[0].size(), -1));
  pos u = make_pair(i,j);
  int max = -1;
  dist[i][j] = 0;
  Q.push(u);
  while(!Q.empty()){
    u = Q.front();Q.pop();
    if(g[u.first][u.second] == 't')  max = dist[u.first][u.second];
    g[u.first][u.second] = 'X';

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
  return max;
}





int main() {
  int row, col;
  cin >> row >> col;
  g = Graf(row, Vc(col));
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j) cin >> g[i][j];
  }
  cin >> row >> col;
  int ret;
  ret = bfs_busca(row-1, col-1);


  if(ret != -1) cout << "distancia maxima: " << ret << endl;
  else cout << "no es pot arribar a cap tresor" << endl;

}
