#include <iostream>
#include <map>

using namespace std;

int main() {
  string ordre;
  map<string, string> liats;
  while(cin >> ordre){
    string x, y;

    if(ordre == "info"){
      cout << "PARELLES:" << endl;
        for(auto it = liats.begin(); it != liats.end(); ++it){
          if(it->second != "" and it->first < it->second) cout << it->first << ' ' << it->second << endl;
        }
      cout << "SOLS:" << endl;
      for(auto it = liats.begin(); it != liats.end(); ++it){
        if(it->second == "") cout << it->first << endl;
      }
      cout << "----------" << endl;

    }
    else{
      cin >> x >> y;
      if(liats[x] != "") liats[liats[x]] = "";
      if(liats[y] != "") liats[liats[y]] = "";
      liats[x] = y;
      liats[y] = x;
    }
  }
}
