#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;
typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

VVC g;
int total;
VP inicis;

VI Kx = {-2,-1,1,2,2,1,-1,-2};
VI Ky = {-1,-2,-2,-1,1,2,2,1};
VI Bx = {1,1,-1,-1};
VI By = {1,-1,1,-1};

bool eslegal(int i, int j){
  return i >=0 and i < g.size() and j < g[0].size() and j >= 0 and g[i][j] != 'T';
}

void dfs(P p, int& monedes){
  VVB vist(g.size(),VB(g[0].size(),false));
  stack<P> S;
  S.push(p);
  while(!S.empty() and total > 0){
    P a = S.top(); S.pop();
    if(!vist[a.first][a.second]){
      vist[a.first][a.second] = true;
      if(g[a.first][a.second] >= '0' and g[a.first][a.second] <= '9'){ //recull monedes
        monedes += g[a.first][a.second] - '0';
        g[a.first][a.second] = '.';
        --total;
      }
      if(g[p.first][p.second] == 'K'){
        for(int d = 0; d < 8; ++d){
          int i = a.first + Kx[d];
          int j = a.second + Ky[d];
          if(eslegal(i,j)) S.push(P(i,j));
        }
      }
      else if(g[p.first][p.second] == 'B'){
        for(int d = 0; d < 4; ++d){
          int i = a.first + Bx[d];
          int j = a.second + By[d];
          if(eslegal(i,j)) S.push(P(i,j));

        }

      }
    }
  }
}

void read(int r, int c){
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      cin >> g[i][j];
      if(g[i][j] >= '0' and g[i][j] <= '9') ++total;
      else if(g[i][j] == 'B' or g[i][j] == 'K') inicis.push_back(P(i,j));
    }
  }
}

int main() {
  int row, col;
  while(cin >> row >> col) {
    g = VVC(row, VC(col));
    total = 0;
    inicis = VP();
    read(row, col);
    int monedes = 0;
    for(int i = 0; i < inicis.size() and total > 0; ++i) dfs(inicis[i],monedes);

    cout << monedes <<endl;
  }

}
