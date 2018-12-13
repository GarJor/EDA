#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> G;
typedef vector<int> VI;

struct Aresta {
  int w; //pes de laresta
  int x, y; //vertex de laresta
};
G g;
VI wei;
VI parents;

bool operator<(const Aresta& a, const Aresta& b){
  return a.w > b.w;
}


void minim() {
  int n = g.size();
  wei = VI(n);
  parents = VI(n,-1);
  priority_queue<Aresta> Q;
  Q.push({0,0,0}); //aresta fantasma
  while(!Q.empty()) {
    Aresta a = Q.top(); Q.pop(); //agafa laresta amb el pes mes petit
    int w = a.w;
    int x = a.x;
    int y = a.y;
    if(parents[y] == -1) {
      parents[y] = x;
      wei[y] = w;
      for(int i = 0; i < g[y].size(); ++i) Q.push({g[y][i].first, y, g[y][i].second});
    }
  }
  int res = 0;
  for(int i = 0; i < n; ++i) res += wei[i];
  cout << res << endl;
}


int main() {
  int v, a;
  while(cin>>v>>a){
    g = G(v);
    int x,y,w;
    for(int i = 0; i < a; ++i) {
      cin >> x >> y >> w;
      --x; --y;
      g[x].push_back(PI(w,y));
      g[y].push_back(PI(w,x));
    }
    minim();
  }
}
