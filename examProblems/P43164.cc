#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

vector<int> X = {0,0,1,-1};
vector<int> Y = {1,-1,0,0};
VVC g;
set<int> res;

bool eslegal(int i, int j){
  return i < g.size() and i >= 0 and j < g[0].size() and j >= 0 and g[i][j] != 'X';
}

void dfs(int i, int j, VVB& vist, vector<vector<int> >& dist){
  if(!vist[i][j]){
    vist[i][j] = true;
    if(g[i][j] == 't') cout << dist[i][j];
    for(int k = 0; k < 4; ++k){
      int ii = i + X[k];
      int jj = j + Y[k];
      if(eslegal(ii, jj)){
        dist[ii][jj] = dist[i][j] + 1;
        dfs(ii, jj, vist, dist);
      }
    }
  }
}

int main(){
  int row, col;
  while(cin >> row >> col){
    g = VVC(row,VC(col));
    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j) cin >> g[i][j];
    }

    int i, j;
    VVB vist(row, VB(col,false));
    vector<vector<int> > dist(row,vector<int>(col, -1));
    cin >> i >> j;
    --i;--j;
    cerr << "AQUI" << endl;
    dist[i][j] = 0;
    cerr << "AQUI2" << endl;
    dfs(i, j, vist, dist);
    // auto it = res.end();
    // --it;
    //cout << *(it) << endl;
  }
}
