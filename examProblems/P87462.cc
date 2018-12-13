#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> P;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;

vector<int> Xd = {0,0,1,-1};
vector<int> Yd = {1,-1,0,0};
vector<int> Lx = {0,0,1,-1,1,-1,1,-1};
vector<int> Ly = {1,-1,0,0,1,1,-1,-1};

VVC g;

bool eslegal(int i, int j){
  if(i < g.size()-1 and i > 0 and j < g[0].size()-1 and j > 0 and g[i][j] != 'X' and g[i][j] != 'F'){
    for(int d = 0; d < 8; ++d){
      if(g[i+Lx[d]][j+Ly[d]] == 'F') return false;
    }
    return true;
  }
  return false;
}

bool dfs(int i, int j){
  stack<P> S;

  for(int d = 0; d < 8; ++d){
    if(g[i+Lx[d]][j+Ly[d]] == 'F') return false;
  }
  S.push(P(i,j));
  while(!S.empty()){
    P a = S.top();S.pop();
    i = a.first;
    j = a.second;

    if(g[i][j] != 'X'){
      if(g[i][j] == 'B') return true;
      g[i][j] = 'X';
      for(int d = 0; d < 4; ++d){
        int ii = i + Xd[d];
        int jj = j + Yd[d];
        if(eslegal(ii,jj)) S.push(P(ii,jj));
      }
    }
  }
  return false;
}

int main(){
  int row, col;
  while(cin>>row>>col){
    g = VVC(row,VC(col));
    int ipac, jpac;
    for(int i = 0; i<row;++i){
      for(int j = 0; j < col; ++j){
        cin >> g[i][j];
        if(g[i][j] == 'P') {
          ipac = i;
          jpac = j;
        }
      }
    }
    if(dfs(ipac, jpac)) cout << "si" << endl;
    else cout << "no" << endl;
  }
}
