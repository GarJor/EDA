#include <iostream>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<VC> VVC;
typedef vector<VI> VVI;
typedef pair<int,int> P;

VI X = {1,1,0,-1,-1,-1,0,1};
VI Y = {0,1,1,1,0,-1,-1,-1};

int n, r;

bool eslegal(P a, VVC& sample){
  if(a.first < n and a.second < n and a.first >= 0 and a.second >= 0){
    for(int k = 0; k < 8; ++k){
      P u;
      u.first = a.first + X[k];
      u.second = a.second + Y[k];
      if(u.first < n and u.second < n and u.first >= 0 and u.second >= 0){
        if(sample[u.first][u.second] == 'K') return false;
      }
  }
  return true;
}
return false;
}

// bool bsf_reis(P u,P o, VVC& sample, VVI& vist, int& reis) {
//   if(vist[u.first][u.second] == 0){
//     vist[u.first][u.second] = (vist[o.first][o.second]%2)+1; //1 -> Rei, 2 -> buit
//     if(vist[u.first][u.second] == 1  and reis < r){
//       sample[u.first][u.second] = 'K';
//
//       cerr << "Poso REI a " << u.first << ',' << u.second << ' ' << reis << r << endl;
//       ++reis;
//
//     }
//     for(int k = 0; k < 8 and reis < r; ++k){
//       P a;
//       a.first = u.first + X[k];
//       a.second = u.second + Y[k];
//       if(eslegal(a)){
//         if(!bsf_reis(a, u, sample, vist, reis))return false;
//       }
//     }
//     return true;
//   }
//  return vist[u.first][u.second] != vist[o.first][o.second];
// }
 bool bfs(P o, VVC& sample){
   VVI vist(n, VI(n,0));
   int reis = 0;
   queue<pair<P,P> > Q;
   Q.push({o,o});
   while(!Q.empty()){
     P u = Q.front().first;
     P o = Q.front().second; Q.pop();
     if(vist[u.first][u.second] == 0){
       vist[u.first][u.second] = (vist[o.first][o.second]%2)+1;
       cerr << vist[u.first][u.second] << " assigned to " << u.first << ',' << u.second << " from " << o.first << ',' << o.second << endl;
       o = u;
       for(int k = 0; k < 8; ++k){
         u.first = o.first + X[k];
         u.second = o.second + Y[k];
         if(eslegal(u, sample)){

           Q.push({u,o});
          cout << "PUSHED: " << u.first << ',' << u.second << endl;
         }

       }
       if(vist[o.first][o.second] == 1 ){
         sample[o.first][o.second] = 'K';
         ++reis;
         if(reis == r) return true;
       }
     }
     else if(vist[u.first][u.second] == vist[o.first][o.second]) return false;
   }
   return false;

 }

void print(VVC& sample) {
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
    cout << sample[i][j];
    }
    cout << endl;
  }
  cout << "----------" << endl;
}

int main() {
  cin >> n >> r;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
   cerr << "------------" << endl;
      VVC sample(n, VC(n,'.'));
      VVI vist(n, VI(n,0));
      P a ={i,j};
      int reis = 0;
      bool ret = bfs(a, sample);
      if(ret) print(sample);
    }
  }


}
