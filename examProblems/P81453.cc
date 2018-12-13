
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<set<int> > VVI;



VI bfs(int v, VVI& g){
VI p(v, -1);
VI s(v, -1);
queue<int> Q;
Q.push(0);
p[0] = -2;
s[0] = 0;
while(!Q.empty()){
 int o = Q.front(); Q.pop();
 if(o == v-1) return p;
 for(int a : g[o]){
   if(s[a] == -1 ){
     p[a] = o;
     s[a] = s[o]+1;
     Q.push(a);
   }
 }
}
return VI();
}

int main(){
int v, a;
while(cin >> v >>a){
 VVI g(v);
 while(--a >= 0){
   int x, y;
   cin >> x >> y;
   g[x].insert(y);
 }
 VI res = bfs(v, g);
 int cursor = v-1;
 stack<int> S;
 while(res[cursor] > -1) {
   S.push(cursor);
   cursor = res[cursor];
 }
 cout << 0;
 while(!S.empty()){
   cout << ' ' << S.top();
   S.pop();
 }
 cout << endl;
}
}
