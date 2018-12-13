#include <iostream>
#include <set>

using namespace std;

int main(){

  int n;
  long int q;
  cin >> n;
  string op;
  set<int> S;
  set<int, greater<int> > R;
  long int suma = 0;
  while(cin >> op >> q) {
    if(op == "deixar"){
      if(S.size()<n){
        S.insert(q);
        suma += q;
      }
      else{
        auto itd = S.begin();
        if(*itd < q){
          suma += q - *itd;
          R.insert(*itd);
          S.erase(itd); S.insert(q);

        }
        else R.insert(q);

      }
    }
    else{
      auto itd = S.begin();
      if(*itd > q){
        R.erase(q);
      }
      else {
        auto id = R.begin();
        S.erase(q);
        suma += *(id) - q;
        S.insert(*id) ; R.erase(*id);
      }
    }
    // auto it = S.begin();
    // long int val = 0;
    // int t = n;
    // while(t > 0){
    //   if(it == S.end()) break;
    //   val += *it;
    //   ++it;
    //   --t;
    // }
    cout << suma << endl;
  }

}
