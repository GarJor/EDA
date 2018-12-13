#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

typedef queue<string> Q;
typedef vector<Q> VQ;

int main(){
  int n;
  cin >> n;
  VQ super(n);
  string line;
  getline(cin, line);
  for(int i = 0; i < n; ++i){
    string line;
    getline(cin, line);
    istringstream in(line);
    string nom;
    while(in >> nom) super[i].push(nom);
  }
  vector<string> res;
  string op;
  while(cin >> op){
    int cua;
    if(op == "SURT"){
      cin >> cua;
      if(cua > 0 and cua <= n and !super[cua-1].empty()){
      res.push_back(super[cua-1].front());
      super[cua-1].pop();
      }
    }
    else{
      string p;
      cin >> p >> cua;
      if(cua > 0 and cua <= n) super[cua-1].push(p);
    }
  }
  cout << "SORTIDES" << endl << "--------" << endl;
  for(int i = 0; i < res.size(); ++i) cout << res[i] << endl;
  cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for(int i = 0; i < n; ++i){
      cout << "cua " << i+1 << ":";
      if(!super[i].empty()){
        while(super[i].size() > 1) {
          cout << ' ' << super[i].front();
          super[i].pop();
        }
        cout << ' ' << super[i].front() << endl;
        super[i].pop();
      }
      else cout << endl;
    }

}
