#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<double, double> pos;
struct pedra {
  pos centre;
  double radi;
};


typedef vector<pedra> Vp;


Vp rocas;

bool operator==(const pedra& a, const pedra& b){
  return a.radi == b.radi and a.centre.first == b.centre.first and a.centre.second == b.centre.second;
}


bool arribes(pedra from, pedra to, double max){
  double c1 = from.centre.first - to.centre.first;
  double c2 = from.centre.second - to.centre.second;
  double dist = sqrt(c1*c1 + c2*c2)-(from.radi + to.radi);
  return dist <= max;
}

int bfs(double max) {
  int n = rocas.size();
  vector<int> salts(n,-1);
  salts[0] = 0;
  queue<int> Q;
  Q.push(0);
  while(!Q.empty()){
    int pid = Q.front(); Q.pop();
    pedra p = rocas[pid];
    if(p == rocas[n-1]) return salts[pid];
    for(int i = 1; i < n ; ++i ){
      if(salts[i] == -1 and arribes(p, rocas[i], max)) {
        salts[i] = salts[pid] + 1;
        Q.push(i);
      }
    }
  }
  return -1;
}

int main() {
  int x;
  double y;
  while(cin >> x >> y) {
    rocas = Vp(x);
    for(int i = 0; i < x; ++i){
      cin >> rocas[i].centre.first >> rocas[i].centre.second >> rocas[i].radi;
    }
    int salts = bfs(y);
    if(salts != -1) cout << salts << endl;
    else cout << "Xof!" << endl;
  }
}
