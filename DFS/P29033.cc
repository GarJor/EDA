#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Graf;
typedef vector<int> Tiza;


bool es_twoColors(const Graf& G, Tiza& t, int u,int uold) {
  if(t[u] == 0) {
    t[u] = (t[uold]%2)+1; //1 ==> color1 ; 2 ==> color2

    for(auto& i : G[u]){
      if(not es_twoColors(G, t, i, u)) return false;
      }
    return true;
  }
  return t[u]!=t[uold];
}

bool twoColors(const Graf& G, int n) {
  Tiza t(n,false);
  for(int i = 0; i<n; ++i){
    if(t[i] == 0 and not es_twoColors(G, t, i, i)) return false;
    }
  return true;

}

int main() {

  int n, m;
  //read the graph
  while(cin >> n >> m) {
    Graf G(n);
    int uorig, udesti;
    while(m > 0 ){
      --m;
      cin >> uorig >> udesti;
      G[uorig].push_back(udesti);
      G[udesti].push_back(uorig);
    }
    if(twoColors(G, n)) cout << "yes" << endl;
    else cout << "no" << endl;
  }


}
