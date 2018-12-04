#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> Graf;

Graf a;
vector<int> X = {-1, 1, -1, 1};
vector<int> Y = {-1, -1, 1, 1};

void llegir_graf(int row, int col) {
  string x;
  for(int i = 0; i<row; ++i ){
    for(int j = 0; j<col; ++j){
      cin >> x;
        if(x == "X")a[i][j] = -1;
        else a[i][j] = stoi(x);
    }
  }
}

bool validPos(int x, int y) {
  int n = a.size();
  int m = a[0].size();
  if(x >= 0 and x < n and y<m and y >= 0) return true;
  else return false;
}

void dfs_search(int x, int y, int& count, int& sum) {
  stack<P> S;
  sum = a[x][y];
  a[x][y] = -1;
  count = 1;
  S.push(P(x, y));
  while(!S.empty()) {
    x = S.top().first;
    y = S.top().second; S.pop();
  for(int i = 0; i < 4; ++i) {
    int tx = x + X[i];
    int ty = y + Y[i];
    if(validPos(tx, ty) and a[tx][ty] != -1) {
      ++count;
      sum += a[tx][ty];
      a[tx][ty] = -1;
      S.push(P(tx,ty));
      }
    }
  }
}

bool esBishop() {
  int last = 0;
  int c = 0;
  for(int i = 0; i<a.size();++i) {
    for(int j = 0; j<a[0].size();++j) {
      if(a[i][j] != -1) {
        int sum, count;
        dfs_search(i, j, count, sum);
        if(sum%count != 0) return false;
        if(c != 0 and last != sum/count) return false;
        last = sum/count;
        ++c;

      }
    }
  }
  return true;
}



int main() {

  int cases, cas;
  cin >> cases;
  cas = 1;
  while(cas <= cases) {
    int row, col;
    cin >> row >> col;
    a = Graf(row,VI(col));
    llegir_graf(row, col);
    if(esBishop()) cout << "Case " << cas << ": yes" << endl;
    else cout << "Case " << cas << ": no" << endl;
    ++cas;
  }

}
