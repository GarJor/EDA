#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> P;
typedef vector< vector<char> > Graf;

vector<int> X = {-1, 1, 0, 0};
vector<int> Y = {0, 0, -1, 1};
Graf g;

void llegir_graf(int row,int col){
    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < col; ++j) cin >> g[i][j];
    }
  }

void dfs_pinting(int i,int j, char c) {
    stack<P> S;
    S.push(P(i, j));
    while(!S.empty()){
      i = S.top().first;
      j = S.top().second; S.pop();

      for(int d = 0; d < 4; ++d){
        int x = i + X[d];
        int y = j + Y[d];
        if(g[x][y] == '.') {
          g[x][y] = c;
          S.push(P(x,y));
        }
      }
    }
  }

void pinta(int row, int col){
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j){
      if(g[i][j] != '#' and g[i][j] != '.') dfs_pinting(i, j, g[i][j]);
    }
  }
}

void imprimir_graf(int row,int col){
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) cout << g[i][j];
    cout << endl;
  }
    cout << endl;
}

int main() {

  int row, col;
  while(cin >> row >> col) {
    g = Graf(row, vector<char>(col));
    llegir_graf(row, col);
    pinta(row, col);
    imprimir_graf(row, col);
  }

}
